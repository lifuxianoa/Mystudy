#include <linux/module.h>
#include <linux/init.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>

#include "scull.h"

static int scull_major = SCULL_MAJOR;
static int scull_minor = 0;
static int scull_nr_devs = 4;
static dev_t dev;

MODULE_LICENSE("Dual BSD/GPL");

static int scull_init(void)
{
    int result = 0;

    printk(KERN_INFO "scull init!\n");
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
    printk(KERN_INFO "major: %d\n", scull_major);
    return 0;
}

static void scull_exit(void)
{
    printk(KERN_INFO "scull exit!\n");
    unregister_chrdev_region(dev, scull_nr_devs);
}

module_init(scull_init);
module_exit(scull_exit);

