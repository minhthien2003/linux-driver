#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
static int hello_init(void)

{

    printk(KERN_ALERT "Khoi tao thanh cong\n");

return 0;
}
static void hello_exit(void)
{
    printk(KERN_ALERT "Ket thuc thanh cong\n");
}
module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Anil Kumar Pugalia");
MODULE_DESCRIPTION("Our First Driver");
