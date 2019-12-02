# Vector开发文档
## 1 概述
vector在C++很常用，是一种可以动态增加的数组，一旦当vector原有的空间满载，vector就
会重新分配一块大小合适的内存，并将原来的数据移动到新的内存之中。具体而言vector内部维
三个指针，start，finish，end_of_storage，分别指向开始，结束和总内存区块结束位置。
当finish指针超过end_of_storage的时候，则重新配置原来内存大小2倍的内存空间，并将原
先内存中的数据移动到新的内存块之中。
## 2 迭代器设计
vector维护的是一个连续的线性空间，所以无论其元素为何，普通指针都可以作为vector的迭代
器。所以可以直接定义：
        typedef value_type* iterator;
## 3 Vector类的设计
vector是C++中比较常见的容器，下面的接口只给出函数名而不解释其实现原理以及作用。
### 3.1 公有接口

**1)iterator begin()**  

**2)iterator end()**  

**3)size_t size()**  

**4)size_t capacity()**  

**5)bool empty()**  

**6)vector()**  

**7)vector(size_t n,const T& value)**  

**8)vector(int n,const T &value)**  

**9)vector(long n,const T &value)**  

**10)explicit vector(size_t n)**  

**11)~vector()**  

**12)void push_back(const T& value)**  

**13)void pop_back()**  

**14)iterator erase(iterator position)**  

**15)void resize(size_t new_size,const T& x)**  

**16)void resize(size_t new_size)**  

**17)iterator allocate_and_fill(size_t n,const T& x)**  

**18)reference operator[](size_t n)**  

**19)reference front()**  

**20)reference back()**  

**21)void insert(iterator position,size_t n,const T &x)**  

### 保护成员
**1)iterator start**  

**2)iterator finish**  

**3)iterator end_of_storage**  

**4)void insert_aux(iterator position,const T& x)**  

**5)void deallocate()**  

**6)void fill_initialize(size_t n,const T& value)**  

**7)iterator allocate_and_fill(size_t n,const T& x)**  



## 其它
C++中提供的容器都是非线程安全的。
