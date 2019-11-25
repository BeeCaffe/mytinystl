# construct开发文档
## 基本概念
在C++中对象的构造分为两个阶段来完成，第一个阶段是内存的配置，由allocate和deallocte等函数完成。第二个阶段是对象的构造，由函数
construct 和 destory等函数完成。construct主要是用来构造对象，需要用到C++里面的placement new操作，而destory主要是用来析
构函数，通过调用对象的析构函数来完成。其中destory有两个版本，一个是直接接受对象的指针，另一个是接受一个迭代器区间，在STL中还采
用了特性萃取技术来提高析构的效率，在我实现的版本中，为了方便代码实现不考虑特性萃取的机制。
## 接口
### construct()
**1)void construct(T1 *p,const T2& value)**

    使用placement new操作完成对象的构造。

### destory()
**1)void destory(T1 *pointer)**

    调用对象析构函数完成析构。

**2)void destory(ForwardIterator first,ForwardIterator last)**

    将区间[first,last)中的所有对象进行析构。


