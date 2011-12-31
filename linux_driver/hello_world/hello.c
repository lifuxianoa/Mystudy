#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/stat.h>

MODULE_LICENSE("Dual BSD/GPL");

static char *whom = "world";
static int howmany = 1;

static int __init hello_init(void)
{
	printk(KERN_ALERT "Hello World linux driver\n");
    printk("whom=%s\n", whom);
    printk("howmany=%d\n", howmany);
	return 0;
}

static void __exit hello_exit(void)
{
	printk(KERN_ALERT "Goodbye linux driver\n");
}

module_param(howmany, int, S_IRUGO);
module_param(whom, charp, S_IRUGO);

module_init(hello_init);
module_exit(hello_exit);

