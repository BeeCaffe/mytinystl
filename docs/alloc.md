# 空间配置器开发文档
## 1.概述
空间配置器广义上来说是指配置计算机中各种存储资源的一个类，其中包含和分配资源，释放资源等函数接口。

对于STL来说，空间配置器一般是指的内存资源，因为对于STL的算法和容器来说，都需要计算机的内存资源来存

储数据。在C语言里面，我们有malloc和free函数来申请和释放计算机内存资源，但是这两个函数直接运用在C++

中则存在一些问题：首先,malloc 返回值是一个通用型指针（void*）无法适用于C++中的对象。另外，当频繁

分配小块内存空间时，会造成巨大的开销。因此，空间配置器所需要达到的目标有两个：

    第一，具有泛化性，能够适用于C++中的各种数据类型包括对象。

    第二，解决频繁分配小块内存所造成的系统开销。

第一个问题的解决方法是：运用类模板提高类的泛化性，第二个问题的解决方案是：采用内存池技术。

## 2.配置器的接口

### 2.1类名：
***1）class allocator:*** 公有通用接口，为用户提供服务

***2）class default_alloc:*** 默认配置类，采用内存池技术，当分配小块内存时采用该类的公有函数，当分配大块内存时，调用malloc_alloc类中的接口。

***3）class malloc_alloc:*** 二级配置器，配置大块内存，采用malloc函数。


### 2.2类的接口：
#### 2.2.1 class simply_alloc(通用配置器接口)
***1) pointer allocate(size_type n);***

    分配n字节内存并返回内存地址，调用C语言内置malloc函数。

***2) void deallocate(pointer p);***

    释放指针p所指向内存区域的内存，调用C语言内置dealloc函数。

***3) void deallocate(pointer p,size_type n);***

    释放指针p所指向内存区域的前n个字节的内存。

#### 2.2.2 class default_alloc (二级配置器)

***public:***

***1)pointer allocate(size_type n);***

    使用内存池技术的allocate函数，该函数的逻辑是：当分配大块内存时，直接转到二级配置器的
    allocate函数。当分配小块内存，在内存池的自由链表中找合适大小的内存块，有则直接拿出来，
    没有就调用私有的refill函数（从内存池中拿内存块来填充到自由链表）。然后分配内存，分配n字节内存并返回内存地址
    回内存地址，如果系统内存耗尽，转到自定义内存耗尽处理程序。

***2)void deallocate(pointer p,size_type n);***

    释放指针p所指向内存区域的地址，对于小块内存，将它挂到自由链表上。对于大块内存，使用free函数释放。

***3)void reallocate(pointer p,size_type n);***

    调用deallocte然后再调用allocate，返回新的内存地址。

***private:***

***1)pointer refill(size_type n);***

    重新装填自由链表，具体的做法是向内存池申请（调用chunk_alloc）默认20*n字节的内存空间，如果内存池空间不足20*n

    的时候，分配所能够分配的最大数量，返回一块内存，将剩余的内存挂载在自由链表上。

***2)pointer chunk_alloc(size_type n,int &nobjs);***

    从内存池分配n块内存，如果内存池空间不足n时，使用malloc函数分配2倍所需大小的内存区块，返回一块，另一块留在内存

    池。当系统内存不足时，调用一级配置器，使用out of memory机制来进行处理。

#### 2.2.3 malloc_alloc（一级配置器）
***1)void* allocate(size_type nbytes);***

***2)void deallocate(void* ptr,size_type n);***

***3)void* reallocate(void* ptr,size_type n);***

***4)void* oom_allocate(size_type nbytes);***

***5)void* oom_reallocate(void* ptr,size_type n);***

### 2.3成员变量

## 3.其他