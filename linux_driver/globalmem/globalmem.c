#include <linux/module.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/mm.h>
#include <linux/sched.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <asm/io.h>
#include <asm/system.h>
#include <asm/uaccess.h>

MODULE_AUTHOR("bolidehi@163.com");
MODULE_LICENSE("GPL");

#define GLOBALMEM_SIZE		4096
#define MEM_CLEAR			0x01
#define GLOBALMEM_MAJOR		255

//static int  globalmem_major= GLOBALMEM_MAJOR;
static int  globalmem_major= 0;

struct globalmem_dev
{
	struct cdev cdev;
	unsigned char mem[GLOBALMEM_SIZE];
};

//static struct globalmem_dev dev;
struct globalmem_dev *globalmem_devp;

static int globalmem_open(struct inode *inodep, struct file *filp)
{
	struct globalmem_dev *dev;
	dev = container_of(inodep->i_cdev, struct globalmem_dev, cdev);
	filp->private_data = dev;
	filp->private_data = globalmem_devp;
	return 0;
}


static int globalmem_release(struct inode *inode, struct file *filp)
{
	return 0;
}

static loff_t globalmem_llseek(struct file *filp, loff_t offset, int orign)
{
 	loff_t ret;
	
	switch(orign)
	{
		case  0: /*From file start to offset*/
			if(offset < 0)
			{
				ret = -EINVAL;
				break;
			}
			else if((unsigned int) offset > GLOBALMEM_SIZE)
			{
				ret = -EINVAL;
			}
			else
			{
				filp->f_pos = offset;
				ret = filp->f_pos;
			}
			break;

		case 1:/*From file current position to offset*/
			if((filp->f_pos + offset >= 0) 
			&& (filp->f_pos + offset >= GLOBALMEM_SIZE))
			{
				filp->f_pos +=  offset;
				ret = filp->f_pos;
			}
			else
			{
				ret = -EINVAL;
			}
			break;

		default:
			ret = -EINVAL;

	}
	return ret;
}


static ssize_t globalmem_read(struct file *filp, char __user *buf, size_t count, loff_t *ppos)
{
	unsigned long p = *ppos;
	int ret = 0;
	struct globalmem_dev *dev = (struct globalmem_dev *)(filp->private_data);

	if (p > GLOBALMEM_SIZE)
	{
		return count? -ENXIO:0;
	}
	else if(count > GLOBALMEM_SIZE - p)
	{
		count = GLOBALMEM_SIZE - p;
	}
	

	if (copy_to_user(buf, dev->mem + p, count))
	{//from kernel copy data to user failed.
		return -EFAULT;
	}
	else
	{
		*ppos += count;
		ret = count;
		printk(KERN_INFO"read %d byte(s) from %ld\n", count, p); 
	}
	return ret;
}


static ssize_t globalmem_write(struct file *filp, const char __user *buf, size_t count, loff_t *ppos)
{
	unsigned long p = *ppos;
	int ret = 0;
	struct globalmem_dev * dev = (struct globalmem_dev *)(filp->private_data);
	

	printk("111111111111111111111111\n");
	if (p > GLOBALMEM_SIZE)
	{
		return count?-ENXIO:0;
	}

	printk("222222222222222222222222222\n");
	if (count > GLOBALMEM_SIZE - p)
	{
		count = GLOBALMEM_SIZE - p;
	}
		
	if(copy_from_user(dev->mem + p, buf, count))
	{
		return -EFAULT;
	}
	else
	{
		*ppos += count;
		ret = count;
		printk(KERN_INFO"write %d byte(s) from %ld\n", count, p);
	}

	return ret;
}

static int globalmem_ioctl(struct inode *inodep, struct file *filp, unsigned int cmd, unsigned long arg)
{

	struct globalmem_dev *dev = (struct globalmem_dev *)(filp->private_data); 

	switch(cmd)
	{
		case MEM_CLEAR:
			memset(dev->mem, '\0', GLOBALMEM_SIZE);
			printk(KERN_INFO"globalmem is set to zero\n");
			break;

		default:
			return -EINVAL;
	}
	return 0;
}

static const struct file_operations globalmem_fops = 
{
 	.owner = THIS_MODULE,
	.llseek = globalmem_llseek,
	.read = globalmem_read,
	.write = globalmem_write,
	.ioctl = globalmem_ioctl,
	.open = globalmem_open,
	.release =globalmem_release
};


static void globalmem_setup_cdev(struct globalmem_dev *dev, int index)
{
	int err;
	dev_t devno = MKDEV(globalmem_major, index);
	cdev_init(&dev->cdev, &globalmem_fops);
	dev->cdev.owner = THIS_MODULE;
	dev->cdev.ops = &globalmem_fops;
	err = cdev_add(&dev->cdev, devno, 1);
	if(err)
	{
		printk(KERN_NOTICE"Error %d adding globalmem", err);
	} 
}


static int __init globalmem_init(void)
{
	int result;
	
	dev_t devno = MKDEV(globalmem_major, 0);

	if(globalmem_major)
	{
		result = register_chrdev_region(devno, 2, "globalmem");
	}
	else
	{
		result = alloc_chrdev_region(&devno, 0, 2, "globalmem");
		globalmem_major = MAJOR(devno);
	}
	
	if(result < 0)
	{
		printk("register globalmem device failed\n");
		return result;
	}

	globalmem_devp = kmalloc(2 * sizeof(struct globalmem_dev), GFP_KERNEL);
	if(NULL == globalmem_devp)
	{
		result =-ENOMEM;
		goto fail_malloc;
	}
	
	memset(globalmem_devp, '\0', 2 * sizeof(struct globalmem_dev));
	
	
	globalmem_setup_cdev(globalmem_devp, 0);
	globalmem_setup_cdev(globalmem_devp + 1, 1);

	printk("init module ok\n");
	return 0;
	
fail_malloc:
	unregister_chrdev_region(devno, 2);
	return result;
}


static void __exit globalmem_exit(void)
{
	cdev_del(&(globalmem_devp[0].cdev));
	cdev_del(&(globalmem_devp[1].cdev));
	kfree(globalmem_devp);

	unregister_chrdev_region(MKDEV(globalmem_major, 0), 2);
}

module_param(globalmem_major, int ,S_IRUGO);
module_init(globalmem_init);
module_exit(globalmem_exit);

