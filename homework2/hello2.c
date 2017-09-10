#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>

#include <linux/errno.h> 
#include <linux/types.h>
#include <linux/slab.h>
#include <asm/bug.h>
#include <linux/moduleparam.h>

#include "inc/hello1.h"

MODULE_AUTHOR("Maksym Pulinets <max.globallogic@gmail.com");
MODULE_DESCRIPTION("\"Hello, world! (2)\" in Linux Kernel Training");
MODULE_VERSION("0.2");
MODULE_LICENSE("Dual BSD/GPL");

static uint number = 1;
module_param(number, uint, S_IRUSR);
MODULE_PARM_DESC(number, "The number to print \"Hello, world!\"");

static int __init hello_init(void)
{
	u32 i = 0;
    pr_emerg("Hello2: start, number = %d\n", number);
    
    if (number == 0) {
        WARN_ON(1);
    } else if (number > 10) {
        BUG_ON(1);
    } else if (number == 5) {

        return -EINVAL;
    } else {
        for (i = 0; i < number; ++i) {
            print_hello();
        }

        if (number == 2) {
        	__module_get(THIS_MODULE);
        }
    }
	return 0;
}

void print_goodbye(void)
{
    pr_emerg("Good bye!\n");
}

static void __exit hello_exit(void)
{
    u8* pointer = (u8*)__kmalloc;
    if (number == 3) {
        *pointer = 0x90;
    }
    
    print_goodbye();
    pr_emerg("Hello2: stop\n");
}

module_init(hello_init);
module_exit(hello_exit);

// make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu-
