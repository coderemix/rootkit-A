/*
Study write a LKM rootkit
now for ubuntu

*/

//模块
#include <linux/module.h>
//内核
#include <linux/kernel.h>
//初始化
#include <linux/init.h>


static int alkm_init(void)
{
    //指定消息优先级，输出到内核控制台/dmesg查看
    printk(KERN_ALERT "alkm: module loaded.\n");
    return 0;
}

static int alkm_exit(void)
{
    printk("alkm: module removed.\n");
}

//内核宏-加载
module_init(alkm_init);
//内核宏-卸载
module_exit(alkm_exit);

MODULE_LICENSE("alkm");


