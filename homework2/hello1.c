#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>


MODULE_AUTHOR("Maksym Pulinets <max.globallogic@gmail.com");
MODULE_DESCRIPTION("\"Hello, world! (1)\" in Linux Kernel Training");
MODULE_VERSION("0.2");
MODULE_LICENSE("Dual BSD/GPL");

static void print_hello(void)
{
    pr_emerg("HELLO, WORLD!\n");
}
EXPORT_SYMBOL(print_hello);

static int __init hello_init(void)
{
    pr_emerg("Hello1: start\n");
	return 0;
}

static void __exit hello_exit(void)
{
    pr_emerg("Hello1: stop\n");
    
	/* Do nothing here right now */
}

module_init(hello_init);
module_exit(hello_exit);

// make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu-
