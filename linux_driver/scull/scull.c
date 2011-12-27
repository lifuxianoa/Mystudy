#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>

MODULE_LICENSE("Dual BSD/GPL");

static int scull_nr_devs = 4;
static dev_t dev;
static int scull_major = 0;
static int scull_minor = 0;
static int scull_quantum = 4000;
static int scull_qset = 1000;

static int scull_open(struct inode *inode, struct file *filp);
static int scull_release(struct inode *inode, struct file *filp);
static ssize_t scull_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos);
static ssize_t scull_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos);

struct scull_qset
{
	void **data;
	struct scull_qset *next; 
}; 

struct scull_dev { 
	struct scull_qset *data;  /* Pointer to first quantum set */ 
	int quantum;  /* the current quantum size */ 
	int qset;  /* the current array size */ 
	unsigned long size;  /* amount of data stored here */ 
	unsigned int access_key;  /* used by sculluid and scullpriv */ 
	struct semaphore sem;  /* mutual exclusion semaphore  */ 
	struct cdev cdev; /* Char device structure */
};

struct file_operations scull_fops = {
	.owner =  THIS_MODULE,
	//.llseek =  scull_llseek,
	.read =  scull_read,
	.write =  scull_write,
	//.ioctl =  scull_ioctl,
	.open =  scull_open,
	.release =  scull_release,
};

int scull_trim(struct scull_dev *dev)
{
	struct scull_qset *next, *dptr;
	int qset = dev->qset; /* "dev" is not-null */
	int i;
	for (dptr = dev->data; dptr; dptr = next)
	{
		/* all the list items */
		if (dptr->data)
		{
			for (i = 0; i < qset; i++)
			{
				kfree(dptr->data[i]);
			}
			kfree(dptr->data);
			dptr->data = NULL;
		}

		next = dptr->next;
		kfree(dptr);
	}
	dev->size = 0;
	dev->quantum = scull_quantum;
	dev->qset = scull_qset;
	dev->data = NULL;
	return 0;
}

static void scull_setup_cdev(struct scull_dev *dev, int index)
{
	int err, devno = MKDEV(scull_major, scull_minor + index);

	cdev_init(&dev->cdev, &scull_fops);
	dev->cdev.owner = THIS_MODULE;
	dev->cdev.ops = &scull_fops;
	err = cdev_add (&dev->cdev, devno, 1);
	/* Fail gracefully if need be */
	if (err)
	{
		printk(KERN_NOTICE "Error %d adding scull%d", err, index);
	}
} 

static int scull_open(struct inode *inode, struct file *filp)
{
	struct scull_dev *dev; /* device information */
	dev = container_of(inode->i_cdev, struct scull_dev, cdev);
	filp->private_data = dev; /* for other methods */

	/* now trim to 0 the length of the device if open was write-only */
	if ( (filp->f_flags & O_ACCMODE) == O_WRONLY)
	{
		scull_trim(dev); /* ignore errors */
	}
	return 0; /* success */
}

static int scull_release(struct inode *inode, struct file *filp)
{
	 return 0;
}

/*
* Follow the list
*/
struct scull_qset *scull_follow(struct scull_dev *dev, int n)
{
	struct scull_qset *qs = dev->data;

	/* Allocate first qset explicitly if need be */
	if (! qs) {
		qs = dev->data = kmalloc(sizeof(struct scull_qset), GFP_KERNEL);
		if (qs == NULL)
			return NULL;  /* Never mind */
		memset(qs, 0, sizeof(struct scull_qset));
	}

	/* Then follow the list */
	while (n--) {
		if (!qs->next) {
			qs->next = kmalloc(sizeof(struct scull_qset), GFP_KERNEL);
			if (qs->next == NULL)
				return NULL;  /* Never mind */
			memset(qs->next, 0, sizeof(struct scull_qset));
		}
		qs = qs->next;
		continue;
	}
	return qs;
}

static ssize_t scull_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
	struct scull_dev *dev = filp->private_data;
	struct scull_qset *dptr; /* the first listitem */
	int quantum = dev->quantum, qset = dev->qset;
	int itemsize = quantum * qset; /* how many bytes in the listitem */
	int item, s_pos, q_pos, rest;
	ssize_t retval = 0;

	if (down_interruptible(&dev->sem))
		return -ERESTARTSYS;
	if (*f_pos >= dev->size)
		goto out;
	if (*f_pos + count > dev->size)
		count = dev->size - *f_pos;

	/* find listitem, qset index, and offset in the quantum */
	item = (long)*f_pos / itemsize;
	rest = (long)*f_pos % itemsize;
	s_pos = rest / quantum;
	q_pos = rest % quantum;

	/* follow the list up to the right position (defined elsewhere) */
	dptr = scull_follow(dev, item);
	if (dptr == NULL || !dptr->data || ! dptr->data[s_pos])
		goto out; /* don't fill holes */

	/* read only up to the end of this quantum */
	if (count > quantum - q_pos)
		count = quantum - q_pos;

	if (copy_to_user(buf, dptr->data[s_pos] + q_pos, count))
	{
		retval = -EFAULT;
		goto out;

	}
	*f_pos += count;
	retval = count;

out:
	up(&dev->sem);
	return retval;
}

static ssize_t scull_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
	struct scull_dev *dev = filp->private_data;
	struct scull_qset *dptr;
	int quantum = dev->quantum, qset = dev->qset;
	int itemsize = quantum * qset;
	int item, s_pos, q_pos, rest;
	ssize_t retval = -ENOMEM; /* value used in "goto out" statements */
	if (down_interruptible(&dev->sem))
		return -ERESTARTSYS;

	/* find listitem, qset index and offset in the quantum */
	item = (long)*f_pos / itemsize;
	rest = (long)*f_pos % itemsize;
	s_pos = rest / quantum;
	q_pos = rest % quantum;
	/* follow the list up to the right position */
	dptr = scull_follow(dev, item);
	if (dptr == NULL)
		goto out;
	if (!dptr->data)
	{
		dptr->data = kmalloc(qset * sizeof(char *), GFP_KERNEL);
		if (!dptr->data)
			goto out;
		memset(dptr->data, 0, qset * sizeof(char *));
	}
	if (!dptr->data[s_pos])
	{
		dptr->data[s_pos] = kmalloc(quantum, GFP_KERNEL);
		if (!dptr->data[s_pos])

			goto out;
	}
	/* write only up to the end of this quantum */
	if (count > quantum - q_pos)

		count = quantum - q_pos;
	if (copy_from_user(dptr->data[s_pos]+q_pos, buf, count))
	{
		retval = -EFAULT;
		goto out;

	}
	*f_pos += count;
	retval = count;

	/* update the size */
	if (dev->size < *f_pos)
		dev->size = *f_pos;

out:
	up(&dev->sem);
	return retval;

}

static int hello_init(void)
{
	int result = 0;

	printk(KERN_ALERT "Hello World linux driver\n");
	if (scull_major)
	{
		dev = MKDEV(scull_major, scull_minor);
		result = register_chrdev_region(dev, scull_nr_devs, "scull");
	}
	else
	{
		result = alloc_chrdev_region(&dev, scull_minor, scull_nr_devs, "scull");
		scull_major = MAJOR(dev);
	}

	if (result < 0)
	{
		printk(KERN_WARNING "scull: can't get major %d\n", scull_major);
		return result;
	}

	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "Goodbey linux driver\n");

	unregister_chrdev_region(dev, scull_nr_devs);
}

module_init(hello_init);
module_exit(hello_exit);

