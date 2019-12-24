# Deque开发文档
## 概述
deque是一种双向开口的连续线性空间。所谓双向开口，意思是可以在首
尾两端分别做元素的插入和删除操作。deque和vector的差异主要在于
第一，deque允许常数时间内对起头端进行元素的插入或者移除操作，二
在于deque没有所谓的容量概念，因为其内存是动态地以分段连续空间组
合而成的，随时可以增加一块新的内存并连接起来。由于一个deque实际
上要控制数个分散的内存块，因此，需要一个中控器来维护各个内存块的
状态以及迭代器的一些访问操作。
## deque的中控器
deque是由一系列的定量的连续空间构成的，一旦有必要在deque的前端
或者尾端增加新空间，便配置一段定量连续空间，串联在整个deque的头
端或者尾端。deque最大的任务便是w维护这些连续空间整体连续的假象
，并提供随机存取的一个接口。

deque采用一块map(不是STL中的map)作为主控，所谓的map是指一小块
连续空间，其中每一个元素都是指针，指向另一块更大的连续空间，称为
缓冲区，缓冲区才是deque存储的主体空间，默认采用512bytes作为缓冲
区大小。
## deque的迭代器
deque是分段连续空间，维持其“整体连续”假象的任务就由迭代器的operator
++和opertor--两个算子来完成。对于deque的迭代器来说，它必须
能够指出分段连续空间在哪里，其次它必须能够判断自己是否已经处于
其所在缓冲区的边缘，如果是的话，当迭代器前进或者后退的时候就必
须能够正确地跳跃到下一个或者上一个缓冲区内部。
### 成员变量

T* cur；//该迭代器所指向的当前元素  

T* first；//该迭代器当前所在的缓冲区头  

T* last；//该迭代器当前所在缓冲区尾  

T** node；//指向管控中心  

### 成员函数
static size_t buffer_size();//决定缓冲区大小的函数  

inline size_t deque_buf_size(size_t n,size_t sz);//  

void set_node(T** new_node);//跳一个缓冲区  

reference operator*() const;//解引操作  

pointer operator->() const;//访问指针成员操作  

difference_type operator-(const self& x);//重载减号操作符  

self& operator++();//重载自增操作符  

self& operator--()；//重载减号操作符  

self& operator+=();//重载+=操作符  

self& operator+();//重载+操作符  

self& operator-=();//重载-=操作符  

reference operator[]();//实现随机存取  

bool opeator==(const self& x) const;//重载==操作符  

bool operator!=(const self& x) const;//重载!=操作符  

bool operator<(const self& x) const;//重载小于操作符  

## deque的数据结构
deque除了维护一个指向map的指针外，也维护start，finish两个
迭代器，分别指向第一个缓冲区的第一个元素和最后一个缓冲区的最后
一个元素。另外，它必须记住当前map的大小，因为一旦当当前的map
所提供的节点不足时，应当重新配置一块map。
### 成员变量
simple_alloc<value_type,Alloc> data_allocator;//缓存区空间配置器，每次配置一个元素大小  

simple_alloc<pointer,Alloc> map_allocator;//中控器空间配置器，每次配置一个指针大小

T** map;//指向中控器的指针  

iterator start;//指向当前缓冲区的第一个节点  

iterator finish；//指向当前缓冲区的最后一个节点  

size_type map_size；//map内有多少指针  

### 成员函数
deque(int n,const value_type& value);//构造函数  

void fill_initialize(size_type n,const value_type& value);//负责安排好deque的结构，并将元素的初值安排妥当   

void create_map_and_nodes(size_type num_elements)//负责安排好map的结构  

void push_back(const value_type& t);//尾端插入元素  

void push_back_aux(const value_type& t);//当最后一个缓冲区只剩下一个备用元素时才会被调用  

void push_front(const value_type& t);//首端插入元素  

void push_front_aux(const value_type& t);//当第一个缓冲区没有任何备用空间时会被调用  

void reserve_map_at_back(size_type nodes_to_add = 1);//如果map尾端节点备用空间不足，采用该函数重新整理map  

void reserve_map_at_front(size_type nodes_to_add = 1);//如果map前端备用节点不足，则调用该函数重新整理map  

void reallocate_map(size_type nodes_to_add,bool add_at_front);//重新分配map  

void pop_back();//尾端元素删除  

void pop_front();//首端元素删除  

void clear();//清空整个deque  

iterator erase(iterator pos);//使用迭代器删除某个元素  

iterator erase(iterator first,iterator last);//清楚区间[first,last)中的所有元素  

iterator insert(iterator pos,const value_type& x);//在pos处插入一个元素，其值为x  

iterator insert_aux(iterator pos,const value_type &x);//在pos上插入一个元素x  

iterator begin();//返回首迭代器  

iterator end();//返回尾迭代器  

reference operator[] (size_type n)；//随机访问元素  

reference front();//返回首元素  

reference back();//返回尾元素  

size_type size() const;//返回当前deque的大小  

size_type max_size() const;//返回当前所有缓存区的大小  

bool empty();//判断deque是否为空  

