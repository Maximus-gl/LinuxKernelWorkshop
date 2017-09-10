#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>

MODULE_AUTHOR("Maksym Pulinets <max.globallogic@gmail.com");
MODULE_DESCRIPTION("\"Hello, world!\" in Linux Kernel Training");
MODULE_VERSION("0.1");
MODULE_LICENSE("Dual BSD/GPL");

static int __init hello_init(void)
{
    pr_emerg("Hello, world!\n");
	return 0;
}

static void __exit hello_exit(void)
{
    pr_emerg("Good bye, world!\n");
}

module_init(hello_init);
module_exit(hello_exit);

// make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu-
