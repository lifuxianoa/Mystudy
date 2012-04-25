/*
 * =============================================================================
 *
 *       Filename:  globalmem.c
 *
 *    Description:  linux driver study
 *
 *        Version:  1.0
 *        Created:  2012年04月10日 13时02分03秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =============================================================================
 */

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

#define GLOBALMEM_SIZE  0X1000  /* 全局内存大小： 4KB */
#define MEM_CLEAR   0X1 /* 清零全局内存 */
#define GLOBALMEM_MAJOR 254 /* 预设的globalmem的主设备号 */
#define GLOBALMEM_NUM   2   /* 全局内存个数 */

//static int globalmem_major = GLOBALMEM_MAJOR;
static int globalmem_major = 0;
/* globalmem 设备结构体 */
struct globalmem_dev
{
    struct cdev cdev;   /* cdev结构体 */
    unsigned char mem[GLOBALMEM_SIZE];  /* 全局内存 */
} *globalmem_devp;

static ssize_t globalmem_read(struct file *filp, char __user *buf, 
        size_t count, loff_t *ppos)
{
    struct globalmem_dev *devp = filp->private_data;
    unsigned long p = *ppos;
    int ret = 0;

    printk(KERN_INFO "----read %d bytes from %lu\n", count, p);
    /* 分析和获取有效的读长度 */
    if (p >= GLOBALMEM_SIZE)    /*要读的偏移位置越界*/
    {
        return count ? - ENXIO : 0;
    }

    if (count > GLOBALMEM_SIZE - p) /* 要读的字节数太大 */
    {
        count = GLOBALMEM_SIZE - p;
    }

    /* 内核空间->用户空间 */
    if (copy_to_user(buf, (void *)(devp->mem + p), count))
    {
        ret = -EFAULT;
    }
    else
    {
        *ppos += count;
        ret = count;

        printk(KERN_INFO "read %d bytes from %lu\n", count, p);
    }

    return ret;
}

static ssize_t globalmem_write(struct file *filp, const char __user *buf,
        size_t count, loff_t *ppos)
{
    struct globalmem_dev *devp = filp->private_data;
    unsigned long p = *ppos;
    int ret = 0;

    printk(KERN_INFO "----write %d bytes to %lu\n", count, p);
    /* 分析和获取有效的写长度 */
    if (p >= GLOBALMEM_SIZE) /* 要写的偏移位置越界 */
    {
        return count ? - ENXIO : 0;
    }

    if (p + count > GLOBALMEM_SIZE) /* 要写的字节数太多 */
    {
        count = GLOBALMEM_SIZE - p;
    }

    /* 用户空间->内核空间 */
    if (copy_from_user((void *)(devp->mem + p), buf, count))
    {
        ret = - EFAULT;
    }
    else
    {
        *ppos += count;
        ret = count;

        printk(KERN_INFO "written %d bytes to %lu\n", count, p);
    }

    return ret;
}

static loff_t globalmem_llseek(struct file *filp, loff_t offset, int orig)
{
    loff_t ret;
    printk(KERN_INFO "llseek: offset=%lld,orig=%d\n", offset, orig);
    switch(orig)
    {
        case 0:     /* SEEK_SET 从文件开头开始偏移 */
            if (offset < 0)
            {
                ret = - EINVAL;
                break;
            }
            if ((unsigned int)offset > GLOBALMEM_SIZE)  /* 偏移越界 */
            {
                ret = - EINVAL;
                break;
            }
            filp->f_pos = (unsigned int)offset;
            ret = filp->f_pos;
            break;

        case 1:     /* SEEK_CUR 从文件当前位置开始偏移 */
            if ((filp->f_pos + offset) > GLOBALMEM_SIZE)    /* 偏移越界 */
            {
                ret = - EINVAL;
                break;
            }
            if ((filp->f_pos + offset) < 0)
            {
                ret = - EINVAL;
                break;
            }
            filp->f_pos += offset;
            ret = filp->f_pos;
            break;

        case 2:     /* SEEK_END 从文件结束位置开始偏移 */
            if (offset > 0)
            {
                ret = - EINVAL;
                break;
            }
            if ((filp->f_pos + offset) < 0)
            {
                ret = - EINVAL;
                break;
            }
            filp->f_pos += offset;
            ret = filp->f_pos;
            break;

        default:
            ret = - EINVAL;
            break;
    }
    return ret;
}

static long globalmem_ioctl(struct file *filp, unsigned int cmd, 
        unsigned long arg)
{
    struct globalmem_dev *devp = filp->private_data;
    printk(KERN_INFO "ioctl: cmd=%u, arg=%lu\n", cmd, arg);
    switch (cmd)
    {
        case MEM_CLEAR:
            /* 清除全局内存 */
            memset(devp->mem, 0, GLOBALMEM_SIZE);
            printk(KERN_INFO "globalmem is set to zero\n");
            break;

        default:
            return - EINVAL;    /* 其他不支持的命令 */
    }
    return 0;
}

/* 文件打开函数 */
static int globalmem_open(struct inode *inode, struct file *filp)
{
    /* 降设备结构体指针赋值给文件私有数据指针 */
    struct globalmem_dev *devp;
    printk(KERN_INFO "open: \n");

    devp = container_of(inode->i_cdev, struct globalmem_dev, cdev);
    filp->private_data = devp;

    return 0;
}

/* 文件关闭函数 */
static int globalmem_release(struct inode *inode, struct file *filp)
{
    printk(KERN_INFO "release: \n");
    return 0;
}

static const struct file_operations globalmem_fops = 
{
    .owner = THIS_MODULE,
    .llseek = globalmem_llseek,
    .read = globalmem_read,
    .write = globalmem_write,
    .unlocked_ioctl = globalmem_ioctl,
    .open = globalmem_open,
    .release = globalmem_release,
};

/* 初始化并添加cdev结构体 */
static void globalmem_setup_cdev(struct globalmem_dev *devp, int index)
{
    int err, devno = MKDEV(globalmem_major, index);

    cdev_init(&devp->cdev, &globalmem_fops);
    devp->cdev.owner = THIS_MODULE;
    devp->cdev.ops = &globalmem_fops;
    err = cdev_add(&devp->cdev, devno, 1);
    if (err)
    {
        printk(KERN_NOTICE "Error %d adding globalmem", err);
    }
}

/* globalmem设备驱动模块加载函数 */
int globalmem_init(void)
{
    int result;
    int i = 0;
    dev_t devno = MKDEV(globalmem_major, 0);

    /* 申请字符设备驱动区域 */
    if (globalmem_major)
    {
        result = register_chrdev_region(devno, GLOBALMEM_NUM, "globalmem");
    }
    else
    {
        /* 动态获得主设备号 */
        result = alloc_chrdev_region(&devno, 0, GLOBALMEM_NUM, "globalmem");
        globalmem_major = MAJOR(devno);
    }
    if (result < 0)
    {
        return result;
    }

    /* 动态申请设备结构体的内存 */
    globalmem_devp = kmalloc(GLOBALMEM_NUM * sizeof(struct globalmem_dev), 
            GFP_KERNEL);
    if (!globalmem_devp)    /* 申请失败 */
    {
        result = - ENOMEM;
        goto fail_malloc;
    }
    memset(globalmem_devp, 0, GLOBALMEM_NUM * sizeof(struct globalmem_dev));

    for (i = 0; i < GLOBALMEM_NUM; i++)
    {
        globalmem_setup_cdev(globalmem_devp + i, i);
    }
    return 0;

fail_malloc:
    unregister_chrdev_region(devno, 1);
    return result;
}

/* globalmem设备驱动模块卸载函数 */
void globalmem_exit(void)
{
    int i = 0;

    /*删除cdev结构 */
    for (i = 0; i < GLOBALMEM_NUM; i++)
    {
        cdev_del(&globalmem_devp[i].cdev);   
    }
    
    kfree(globalmem_devp);  /* 释放设备结构体内存 */
    /* 注销这个区域 */
    unregister_chrdev_region(MKDEV(globalmem_major, 0), GLOBALMEM_NUM); 
}

MODULE_AUTHOR("lifuxian");
MODULE_LICENSE("Dual BSD/GPL");

module_param(globalmem_major, int, S_IRUGO);

module_init(globalmem_init);
module_exit(globalmem_exit);

