# uninitialized开发文档
## 1 概述

这个文件主要定义了几个函数用于在为初始化的空间上构造对象，作为容器实现的底层操作。首先，如前面所说的那样C++中一个对象的创建
分为两个阶段来完成，先配置对象所需的内存，再创建对象（这两个操作由placement new来完成）。因此，这里提供的三个函数为
uninitalized_copy(),uninitalized_fill(),uninitalized_fill_n()三个函数。同样实现本章节的三个函数出于效率考虑需要使
用特性萃取机制，但是此处为了实现方便，不采用特性萃取技术。

## 2 接口
**1）void uninitalized_copy(ForwardIterator first,ForwardIterator last,ForwardIterator result)**

    针对输入范围内的每一个迭代器i，调用construct()函数来产生*i的复制品，并将其放置在合适的输出位置上。注意该函数需要是一个
    原子操作，即要么构造出所有的对象，要么一个也别构造。

**2)void uninitalized_fill(ForwardIterator first,ForwardIterator last,const T& x)**

    针对输入范围内的每一个迭代器i，调用construct()产生x的复制，并将其放置在合适的输出位置上，同样，要么构造出所有的对象，要
    么抛出异常并且析构掉已经构造的对象。

**3)ForwardIterator uninitalized_fill_n(ForwardIterator first,ForwardIterator last,Size n,const T& x)**

    针对输入范围内的每一个迭代器i，调用construct（）产生x的复制，并将其放置在合适的输出位置上，同时返回迭代器。


