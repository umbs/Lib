/* Reference: 
 *      http://www.linuxforu.com/2010/12/writing-your-first-linux-driver/
 */
#include <linux/module.h> 
#include <linux/version.h> 
#include <linux/kernel.h>

static int __init first_init(void) 
{
        printk(KERN_INFO "Namaskar: first driver registered"); 
        return 0; 
}

static void __exit first_exit(void) 
{
        printk(KERN_INFO "Alvida: first driver unregistered"); 
}

module_init(first_init); 
module_exit(first_exit); 

MODULE_LICENSE("GPL"); 
MODULE_AUTHOR("Bhaskar Sarma Upadhyayula"); 
MODULE_DESCRIPTION("First Driver"); 
