#include <linux/module.h>
#include <linux/init.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <asm/uaccess.h>        /* copy_*_user */

#include "scull.h"

static int scull_major = SCULL_MAJOR;
static int scull_minor = SCULL_MINOR;
static int scull_nr_devs = SCULL_NR_DEVS;
static int scull_quantum = SCULL_QUANTUM;
static int scull_qset = SCULL_QSET;

module_param(scull_major, int, S_IRUGO);
module_param(scull_minor, int, S_IRUGO);
module_param(scull_nr_devs, int, S_IRUGO);
module_param(scull_quantum, int, S_IRUGO);
module_param(scull_qset, int, S_IRUGO);

MODULE_LICENSE("Dual BSD/GPL");

struct scull_dev *scull_devices;    /* allocated in scull_init_module */

int scull_open(struct inode *inode, struct file *filp);
int scull_release(struct inode *inode, struct file *filp);
ssize_t scull_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos);
ssize_t scull_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos);

int scull_trim(struct scull_dev *dev);

struct file_operations scull_fops =
{
    .owner = THIS_MODULE,
    //.llseek = scull_llseek,
    .read = scull_read,
    .write = scull_write,
    //.ioctl = scull_ioctl,
    .open = scull_open,
    .release = scull_release,
};

int scull_trim(struct scull_dev *dev)
{
    struct scull_qset *next, *dptr;
    int qset = dev->qset;   /* "dev" is not-null */
    int i;

    for (dptr = dev->data; dptr; dptr = next)
    {
        /* all the list item */
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

struct scull_qset * scull_follow(struct scull_dev *dev, int n)
{
    struct scull_qset *dptr = dev->data;

    /* Allocate first qset explicitly if need be */
    if (!dptr)
    {
        dptr = dev->data = kmalloc(sizeof(struct scull_qset), GFP_KERNEL);
        if (!dptr)
        {
            return NULL;
        }
        memset(dptr, 0, sizeof(struct scull_qset));
    }

    /* Follow the list */
    while (n--)
    {
        if (!dptr->next)
        {
            dptr->next = kmalloc(sizeof(struct scull_qset), GFP_KERNEL);
            memset(dptr->next, 0, sizeof(struct scull_qset));
        }
        dptr = dptr->next;
    }
    return dptr;
}

ssize_t scull_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
    struct scull_dev *dev = filp->private_data;
    struct scull_qset *dptr = NULL; /* the first listitem */
    int quantum = dev->quantum;
    int qset = dev->qset;
    int itemsize = quantum * qset;  /* how many bytes in the listitem */
    int item, rest, s_pos, q_pos;
    ssize_t retval = 0;

    //wait_for_completion(&dev->comp);
    if (down_interruptible(&dev->sem))
    {
        return -ERESTARTSYS;
    }

    PDEBUG("scull_read \n");
    if (*f_pos >= dev->size)
    {
        goto out;
    }

    if (*f_pos + count > dev->size)
    {
        count = dev->size - *f_pos;
    }

    /* find listitem, qset index, and offset in the quantum */
    item = (long) * f_pos / itemsize;
    rest = (long) * f_pos % itemsize;
    s_pos = rest / quantum;
    q_pos = rest % quantum;

    /* follow the list up to the right position (defined elsewhere) */
    dptr = scull_follow(dev, item);
    if (dptr == NULL || !dptr->data || !dptr->data[s_pos])
    {
        goto out;   /* don't file holes */
    }

    /* read only up to the end of this quantum */
    if (count > quantum - q_pos)
    {
        count = quantum - q_pos;
    }

    PDEBUG("s_pos = %d, q_pos = %d, data = %s\n", s_pos, q_pos, (char*)(dptr->data[s_pos] + q_pos));
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

ssize_t scull_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
    struct scull_dev *dev = filp->private_data;
    struct scull_qset *dptr = NULL; /* the first listitem */
    int quantum = dev->quantum;
    int qset = dev->qset;
    int itemsize = quantum * qset;  /* how many bytes in the listitem */
    int item, rest, s_pos, q_pos;
    ssize_t retval = -ENOMEM;

    if (down_interruptible(&dev->sem))
    {
        return -ERESTARTSYS;
    }

    PDEBUG("scull_write \n");
    /* find listitem, qset index, and offset in the quantum */
    item = (long) * f_pos / itemsize;
    rest = (long) * f_pos % itemsize;
    s_pos = rest / quantum;
    q_pos = rest % quantum;

    /* follow the list up to the right position (defined elsewhere) */
    dptr = scull_follow(dev, item);
    if (dptr == NULL)
    {
        goto out;   /* don't file holes */
    }

    if (!dptr->data)
    {
        dptr->data = kmalloc(qset * sizeof(char *), GFP_KERNEL);
        if (!dptr->data)
        {
            goto out;
        }
        memset(dptr->data, 0, qset * sizeof(char *));
    }

    if (!dptr->data[s_pos])
    {
        dptr->data[s_pos] = kmalloc(quantum, GFP_KERNEL);
        if (!dptr->data[s_pos])
        {
            goto out;
        }
        memset(dptr->data[s_pos], 0, quantum);
    }

    /* write only up to the end of this quantum */
    if (count > quantum - q_pos)
    {
        count = quantum - q_pos;
    }

    if (copy_from_user(dptr->data[s_pos] + q_pos, buf, count))
    {
        retval = -EFAULT;
        goto out;
    }

    PDEBUG("s_pos = %d, q_pos = %d, data = %s\n", s_pos, q_pos, (char *)(dptr->data[s_pos] + q_pos));
    *f_pos += count;
    retval = count;

    /* update the size */
    if (dev->size < *f_pos)
    {
        dev->size = *f_pos;
    }
    //complete(&dev->comp);

out:
    up(&dev->sem);
    return retval;
}

int scull_open(struct inode *inode, struct file *filp)
{
    struct scull_dev *dev;  /* device informaiton */
    dev = container_of(inode->i_cdev, struct scull_dev, cdev);
    filp->private_data = dev;   /* for other methods */

    /* now trim to 0 the length of the device if open was write-only */
    if ( (filp->f_flags & O_ACCMODE) == O_WRONLY)
    {
        scull_trim(dev);    /* ignore errors */
    }

    return 0;
}

int scull_release(struct inode *inode, struct file *filp)
{
    return 0;
}

static void scull_cleanup_module(void)
{
    int i;
    dev_t devno = MKDEV(scull_major, scull_minor);
    PDEBUG("scull exit!\n");
    
    /* Get rid of our char dev entries */
    if (scull_devices)
    {
        for (i = 0; i < scull_nr_devs; i++)
        {
            scull_trim(scull_devices + i);
            cdev_del(&scull_devices[i].cdev);
        }
        kfree(scull_devices);
    }
    unregister_chrdev_region(devno, scull_nr_devs);
}

static void scull_setup_cdev(struct scull_dev *dev, int index)
{
    int err, devno = MKDEV(scull_major, scull_minor + index);

    cdev_init(&dev->cdev, &scull_fops);
    dev->cdev.owner = THIS_MODULE;
    dev->cdev.ops = &scull_fops;
    err = cdev_add(&dev->cdev, devno, 1);
    if (err)
    {
        PDEBUG("Error %d adding scull%d", err, index);
    }
}

static int scull_init_module(void)
{
    int result = 0, i = 0;
    char devno[24] = {'\0'};
    dev_t dev;

    PDEBUG("scull init!\n");
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
        PDEBUG("scull: can't get major %d\n", scull_major);
        return result;
    }

    PDEBUG("devno:%s\n", format_dev_t(devno, dev));
    PDEBUG("major: %d\n", scull_major);

    /* allocate the devices -- we can't have them static, 
       as the number can be specified at load time */
    scull_devices = kmalloc(scull_nr_devs * sizeof(struct scull_dev), GFP_KERNEL);
    if (!scull_devices)
    {
        result = -ENOMEM;
        goto fail;
    }
    memset(scull_devices, 0, scull_nr_devs * sizeof(struct scull_dev));

    /* Initialize each device */
    for (i = 0; i < scull_nr_devs; i++)
    {
        scull_devices[i].quantum = scull_quantum;
        scull_devices[i].qset = scull_qset;
        init_MUTEX(&scull_devices[i].sem);
        //init_completion(&scull_devices[i].comp);
        scull_setup_cdev(&scull_devices[i], i);
    }

    return 0;

fail:
    scull_cleanup_module();
    return result;
}

MODULE_DESCRIPTION("scull test");
MODULE_AUTHOR("fuxian.li<lifuxian@163.com>");
MODULE_LICENSE("GPL");

module_init(scull_init_module);
module_exit(scull_cleanup_module);

