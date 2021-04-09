# rootkit-A


### 1.1 [基本模块](https://www.freebuf.com/articles/system/54263.html)



```
make
insmod alkm.ko

lsmod
rmmod alkm.ko

cat /var/log/messages
dmesg

```

### 1.2 hide from lsmod & sysfs /proc/modules
lsmod命令是通过/proc/modules来获取当前系统模块信息的。而/proc/modules中的当前系统模块信息是内核利用struct modules结构体的表头遍历内核模块链表、从所有模块的struct module结构体中获取模块的相关信息来得到的。结构体struct module在内核中代表一个内核模块。通过insmod(实际执行init_module系统调用)把自己编写的内核模块插入内核时，模块便与一个 struct module结构体相关联，并成为内核的一部分，所有的内核模块都被维护在一个全局链表中，链表头是一个全局变量struct module *modules。任何一个新创建的模块，都会被加入到这个链表的头部，通过modules->next即可引用到。为了让我们的模块在lsmod命令中的输出里消失掉，我们需要在这个链表内删除我们的模块

### 1.3 从sysfs中隐藏模块


