/*
 * =============================================================================
 *
 *       Filename:  globalfifo.c
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
#include <linux/poll.h>
#include <asm/io.h>
#include <asm/system.h>
#include <asm/uaccess.h>

#define GLOBALFIFO_SIZE  0X1000  /* 全局内存大小： 4KB */
#define MEM_CLEAR   0X1 /* 清零全局内存 */
#define GLOBALFIFO_MAJOR 254 /* 预设的globalfifo的主设备号 */
#define GLOBALFIFO_NUM   2   /* 全局内存个数 */

//static atomic_t globalfifo_available = ATOMIC_INIT(1);   /* 定义原子变量 */
//static int globalfifo_count = 0;    /* 定义文件打开次数计数 */
//static spinlock_t globalfifo_lock;
//static DECLARE_MUTEX(globalfifo_lock);   /* 定义互斥锁/信号量 */

//static int globalfifo_major = GLOBALFIFO_MAJOR;
static int globalfifo_major = 0;
/* globalfifo 设备结构体 */
struct globalfifo_dev
{
    struct cdev cdev;   /* cdev结构体 */
    unsigned char mem[GLOBALFIFO_SIZE];  /* 全局内存 */
    struct semaphore sem;   /* 读写时并发控制用的信号量 */
    unsigned int current_len;   /* 有效数据长度 */
    wait_queue_head_t r_wait;   /* 阻塞读用的等待队列头 */
    wait_queue_head_t w_wait;   /* 阻塞写用的等待队列头 */
    struct fasync_struct *async_queue;  /* 异步结构体指针， 用于读 */
} *globalfifo_devp;

static ssize_t globalfifo_read(struct file *filp, char __user *buf, 
        size_t count, loff_t *ppos)
{
    struct globalfifo_dev *devp = filp->private_data;
    int ret = 0;

    DECLARE_WAITQUEUE(wait, current);
    printk(KERN_INFO "----read %d bytes\n", count);

    down(&devp->sem);   /* 获得信号量 */
    add_wait_queue(&devp->r_wait, &wait);   /* 添加进读等待队列头 */

    /* 等待FIFO非空 */
    if (0 == devp->current_len)
    {
        if (filp->f_flags & O_NONBLOCK)
        {
            ret = - EAGAIN;
            goto out;
        }

        __set_current_state(TASK_INTERRUPTIBLE);    /* 改变当前进程状态为睡眠 */
        up(&devp->sem); /* 释放信号量 */

        schedule(); /* 调度其他进程执行 */
        if (signal_pending(current))
        {
            /* 如果是因为信号唤醒 */
            ret = - ERESTARTSYS;
            goto out2;
        }
        down(&devp->sem);
    }

    /* 复制到用户空间 */
    if (count > devp->current_len)
    {
        count = devp->current_len;
    }

    if (copy_to_user(buf, devp->mem, count))
    {
        ret = - EFAULT;
        goto out;
    }
    else
    {
        /* FIFO数据前移 */
        memcpy(devp->mem, devp->mem + count, devp->current_len - count);
        devp->current_len -= count;
        printk(KERN_INFO "read %d bytes, current_len:%d\n", count, 
                devp->current_len);
        wake_up_interruptible(&devp->w_wait);
        ret = count;
    }

out:
    up(&devp->sem); /* 释放信号量 */

out2:
    remove_wait_queue(&devp->r_wait, &wait);    /* 从读等待队列头移除 */
    set_current_state(TASK_RUNNING);

    return ret;
}

static ssize_t globalfifo_write(struct file *filp, const char __user *buf,
        size_t count, loff_t *ppos)
{
    struct globalfifo_dev *devp = filp->private_data;
    int ret = 0;

    DECLARE_WAITQUEUE(wait, current);   /* 定义等待队列 */
    printk(KERN_INFO "----write %d bytes \n", count);

    down(&devp->sem);   /* 获取信号量 */
    add_wait_queue(&devp->w_wait, &wait);    /* 添加进写等待队列头 */

    /* 等待FIFO非满 */
    if (devp->current_len == GLOBALFIFO_SIZE)
    {
        if (filp->f_flags & O_NONBLOCK)
        {
            /* 如果是非阻塞访问 */
            ret = - EAGAIN;
            goto out;
        }

        __set_current_state(TASK_INTERRUPTIBLE);    /* 改变当前进程状态为睡眠 */
        up(&devp->sem);

        schedule(); /* 调度其他进程执行 */

        if (signal_pending(current))
        {
            /* 如果是因为信号唤醒 */
            ret = - ERESTARTSYS;
            goto out2;
        }

        down(&devp->sem);   /* 获得信号量 */
    }

    /* 从用户空间复制到内核空间 */
    if (count > GLOBALFIFO_SIZE - devp->current_len)
    {
        count = GLOBALFIFO_SIZE - devp->current_len;
    }

    if (copy_from_user(devp->mem + devp->current_len, buf, count))
    {
        ret = - EFAULT;
        goto out;
    }
    else
    {
        devp->current_len += count;
        printk(KERN_INFO "written %d bytes, current_len:%d\n", count, 
                devp->current_len);

        wake_up_interruptible(&devp->r_wait);   /* 唤醒读等待队列 */

        /* 产生异步读信号 */
        if (devp->async_queue)
        {
            kill_fasync(&devp->async_queue, SIGIO, POLL_IN);
        }

        ret = count;
    }

out:
    up(&devp->sem); /* 释放信号量 */

out2:
    remove_wait_queue(&devp->w_wait, &wait);  /* 从写等待队列头移除 */
    set_current_state(TASK_RUNNING);

    return ret;
}

static loff_t globalfifo_llseek(struct file *filp, loff_t offset, int orig)
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
            if ((unsigned int)offset > GLOBALFIFO_SIZE)  /* 偏移越界 */
            {
                ret = - EINVAL;
                break;
            }
            filp->f_pos = (unsigned int)offset;
            ret = filp->f_pos;
            break;

        case 1:     /* SEEK_CUR 从文件当前位置开始偏移 */
            if ((filp->f_pos + offset) > GLOBALFIFO_SIZE)    /* 偏移越界 */
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

static long globalfifo_ioctl(struct file *filp, unsigned int cmd, 
        unsigned long arg)
{
    struct globalfifo_dev *devp = filp->private_data;
    printk(KERN_INFO "ioctl: cmd=%u, arg=%lu\n", cmd, arg);
    switch (cmd)
    {
        case MEM_CLEAR:
            if (down_interruptible(&devp->sem)) /* 获得信号量 */
            {
                return - ERESTARTSYS;
            }

            /* 清除全局内存 */
            memset(devp->mem, 0, GLOBALFIFO_SIZE);
            up(&devp->sem);     /* 释放信号量 */
            printk(KERN_INFO "globalfifo is set to zero\n");
            break;

        default:
            return - EINVAL;    /* 其他不支持的命令 */
    }
    return 0;
}

static int globalfifo_fasync(int fd, struct file *filp, int mode)
{
    struct globalfifo_dev *devp = filp->private_data;
    return fasync_helper(fd, filp, mode, &devp->async_queue);
}

/* 文件打开函数 */
static int globalfifo_open(struct inode *inode, struct file *filp)
{
    /* 降设备结构体指针赋值给文件私有数据指针 */
    struct globalfifo_dev *devp;
    printk(KERN_INFO "open: \n");

#if 0
    if (!atomic_dec_and_test(&globalfifo_available))
    {
        atomic_inc(&globalfifo_available);
        return - EBUSY; /* 已经打开 */
    }
#endif

#if 0
    spin_lock(&globalfifo_lock);
    if (globalfifo_count)    /* 已经打开 */
    {
        spin_unlock(&globalfifo_lock);
        return - EBUSY;
    }
    globalfifo_count++;  /* 增加使用计数 */
    spin_unlock(&globalfifo_lock);
#endif

#if 0
    /* 获得信号量 */
    if (down_trylock(&globalfifo_lock))
    {
        return - EBUSY;
    }
#endif

    devp = container_of(inode->i_cdev, struct globalfifo_dev, cdev);
    filp->private_data = devp;

    return 0;
}

/* 文件关闭函数 */
static int globalfifo_release(struct inode *inode, struct file *filp)
{
#if 0
    spin_lock(&globalfifo_lock);
    globalfifo_count++;  /* 减少使用计数 */
    spin_unlock(&globalfifo_lock);
#endif

    /* 将文件从异步通知列表中删除 */
    globalfifo_fasync(-1, filp, 0);

    //up(&globalfifo_lock);    /* 释放信号量 */
    printk(KERN_INFO "release: \n");
    //atomic_inc(&globalfifo_available);   /* 释放设备 */
    return 0;
}

static unsigned int globalfifo_poll(struct file *filp, 
        struct poll_table_struct *wait)
{
    unsigned int mask = 0;
    struct globalfifo_dev *devp = filp->private_data;

    down(&devp->sem);

    poll_wait(filp, &devp->r_wait, wait);
    poll_wait(filp, &devp->w_wait, wait);

    /* FIFO非空 */
    if (devp->current_len > 0)
    {
        mask |= POLLIN | POLLRDNORM;    /* 表示数据可获得 */
    }

    /* FIFO非满 */
    if (devp->current_len < GLOBALFIFO_SIZE)
    {
        mask |= POLLOUT | POLLRDNORM;   /* 表示数据可写 */
    }

    up(&devp->sem);
    return mask;
}

static const struct file_operations globalfifo_fops = 
{
    .owner = THIS_MODULE,
    .llseek = globalfifo_llseek,
    .read = globalfifo_read,
    .write = globalfifo_write,
    .unlocked_ioctl = globalfifo_ioctl,
    .poll = globalfifo_poll,
    .fasync = globalfifo_fasync,
    .open = globalfifo_open,
    .release = globalfifo_release,
};

/* 初始化并添加cdev结构体 */
static void globalfifo_setup_cdev(struct globalfifo_dev *devp, int index)
{
    int err, devno = MKDEV(globalfifo_major, index);

    cdev_init(&devp->cdev, &globalfifo_fops);
    devp->cdev.owner = THIS_MODULE;
    devp->cdev.ops = &globalfifo_fops;
    err = cdev_add(&devp->cdev, devno, 1);
    if (err)
    {
        printk(KERN_NOTICE "Error %d adding globalfifo", err);
    }
}

/* globalfifo设备驱动模块加载函数 */
int globalfifo_init(void)
{
    int result;
    int i = 0;
    dev_t devno = MKDEV(globalfifo_major, 0);

    /* 申请字符设备驱动区域 */
    if (globalfifo_major)
    {
        result = register_chrdev_region(devno, GLOBALFIFO_NUM, "globalfifo");
    }
    else
    {
        /* 动态获得主设备号 */
        result = alloc_chrdev_region(&devno, 0, GLOBALFIFO_NUM, "globalfifo");
        globalfifo_major = MAJOR(devno);
    }
    if (result < 0)
    {
        return result;
    }

    /* 动态申请设备结构体的内存 */
    globalfifo_devp = kmalloc(GLOBALFIFO_NUM * sizeof(struct globalfifo_dev), 
            GFP_KERNEL);
    if (!globalfifo_devp)    /* 申请失败 */
    {
        result = - ENOMEM;
        goto fail_malloc;
    }
    memset(globalfifo_devp, 0, GLOBALFIFO_NUM * sizeof(struct globalfifo_dev));

    for (i = 0; i < GLOBALFIFO_NUM; i++)
    {
        globalfifo_setup_cdev(globalfifo_devp + i, i);
        init_MUTEX(&globalfifo_devp[i].sem);
        init_waitqueue_head(&globalfifo_devp[i].r_wait); /* 初始化读等待队列头 */
        init_waitqueue_head(&globalfifo_devp[i].w_wait); /* 初始化写等待队列头 */
    }

    //spin_lock_init(&globalfifo_lock);
    return 0;

fail_malloc:
    unregister_chrdev_region(devno, 1);
    return result;
}

/* globalfifo设备驱动模块卸载函数 */
void globalfifo_exit(void)
{
    int i = 0;

    /*删除cdev结构 */
    for (i = 0; i < GLOBALFIFO_NUM; i++)
    {
        cdev_del(&globalfifo_devp[i].cdev);   
    }
    
    kfree(globalfifo_devp);  /* 释放设备结构体内存 */
    /* 注销这个区域 */
    unregister_chrdev_region(MKDEV(globalfifo_major, 0), GLOBALFIFO_NUM); 
}

MODULE_AUTHOR("lifuxian");
MODULE_LICENSE("Dual BSD/GPL");

module_param(globalfifo_major, int, S_IRUGO);

module_init(globalfifo_init);
module_exit(globalfifo_exit);

