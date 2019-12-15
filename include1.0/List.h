/***********************************************************************************************************************
 * Created by caffe on 2019/12/2.
 *
 **********************************************************************************************************************/
#ifndef MYTINYSTL_LIST_H
#define MYTINYSTL_LIST_H
#include "envs_msg.h"

#include "Construct.h"
#if envs_linux
#include <lzma.h>
#endif
#include "Alloc.h"

namespace mystl{
    /**
     * @brief the struct of list node,which contains two pointer and a data.pointer prev point to the front node,
     * pointer next points the next node.
     * @tparam T : type
     */
    template <class T>
    struct list_node{
        list_node *prev;
        list_node *next;
        T data;
    };
    /**
     * @brief the class of iterator.
     * @tparam T : type
     */
    template <class T>
    class list_iter{
    public:
        typedef T value_type;
        typedef T& reference;
        typedef T* pointer;
        typedef size_t size_type;
        typedef ptrdiff_t dif_type;
        typedef list_node<T> node_type;
        typedef list_node<T>* node_ptr_type;
        typedef list_iter<T> self;
    public:
        node_ptr_type node;
    public:
        list_iter()= default;
        list_iter(node_ptr_type x);
        list_iter(const list_iter &x);
        list_iter(list_iter &x);
        self& operator=(const self &x);
        self& operator+(const int step);
        bool operator==(const self& x);
        bool operator!=(const self &x);
        self&  operator++();
        self&  operator++(int);
        self& operator--();
        self& operator--(int);
        reference operator*() const;
        pointer operator->() const;
        };
    template <class T>
    list_iter<T>::list_iter(mystl::list_iter<T>::node_ptr_type x) :node(x){

    }
    template <class T>
    list_iter<T>::list_iter(const list_iter<T> &x) :node(x.node){}
    template <class T>
    list_iter<T>::list_iter(list_iter<T> &x):node(x.node){}
    template <class T>
    typename list_iter<T>::self & list_iter<T>::operator=(const list_iter<T>::self & x) {
        node=x.node;
        return *this;
    }

//    template <class T>
//    typename list_iter<T>::self & list_iter<T>::operator+(const int step) {
//        self ret=*this;
//        for(int i=0;i<step;++i){
//            ret.node=ret.node->next;
//        }
//        return ret;
//    }


    template <class T>
    bool list_iter<T>::operator==(const mystl::list_iter<T>::self &x) {
        return node->data==x.node->data;
    }

    template <class T>
    bool list_iter<T>::operator!=(const mystl::list_iter<T>::self &x) {
        return node->data!=x.node->data;
    }

    template <class T>
    typename list_iter<T>::reference list_iter<T>::operator*() const {
        return const_cast<reference>(node->data);
    }

    template <class T>
    typename list_iter<T>::pointer list_iter<T>::operator->() const {
        return &node;
    }

    template <class T>
    typename list_iter<T>::self& list_iter<T>::operator++() {
        node=node->next;
        return *this;
    }

    template <class T>
    typename list_iter<T>::self& list_iter<T>::operator++(int) {
        self tmp=*this;
        node=node->next;
        return tmp;
    }

    template <class T>
    typename list_iter<T>::self& list_iter<T>::operator--() {
        node=node->prev;
        return *this;
    }

    template <class T>
    typename list_iter<T>::self& list_iter<T>::operator--(int) {
        self tmp=*this;
        node=node->prev;
        return tmp;
    }
    /**
     * @brief : class of List, we have implemented all interface of a List required.
     */
    template <class T,class Alloc=mystl::default_alloc>
    class List{
    public:
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef size_t size_type;
        typedef ptrdiff_t diff_type;
        typedef list_iter<T> iterator;
        typedef list_node<T>* node_ptr_type;
        typedef list_node<T> node_type;
        typedef mystl::simply_alloc<node_type,Alloc> data_alloc;
    protected:
        node_ptr_type head_node;
        node_ptr_type get_node();
        void put_node(node_ptr_type node_ptr);
        node_ptr_type create_node(const T& val);
        void destory_node(node_ptr_type ptr);
        void empty_initialized();

    public:
        List();

        iterator begin();

        iterator end();

        bool empty();

        reference front();

        reference back();

        iterator insert(iterator position,const T& x);

        void push_front(const T& x);

        void push_back(const T& x);

        iterator erase(iterator pos);

        void pop_front();

        void pop_back();

        void clear();

        void remove(const T& value);

        void unique();

        void transfer(iterator pos,iterator first, iterator last);

        void splice(iterator pos,List &x);

        void splice(iterator pos,List &x, iterator i);

        void splice(iterator pos,List &x,iterator first,iterator last);

        void merge(List &x);

        void reverse();

        void sort();

    };

    template <class T,class Alloc>
    List<T,Alloc>::List(){
            empty_initialized();
    }
    template <class T,class Alloc>
    typename List<T,Alloc>::node_ptr_type List<T,Alloc>::get_node() {
        return static_cast<node_ptr_type>(data_alloc::allocate(sizeof(node_type)));
    }

    template <class T,class Alloc>
    void List<T,Alloc>::put_node(mystl::List<T, Alloc>::node_ptr_type node_ptr) {
        data_alloc::deallocate(node_ptr);
    }

    template <class T,class Alloc>
    typename List<T,Alloc>::node_ptr_type List<T,Alloc>::create_node(const T &val) {
        node_ptr_type tmp=get_node();
        construct(&tmp->data,val);
        return tmp;
    }
    template <class T,class Alloc>
    void List<T,Alloc>::destory_node(node_ptr_type ptr) {
        destory(&ptr->data);
        data_alloc::deallocate(ptr);
    }
    template <class T,class Alloc>
    void List<T,Alloc>::empty_initialized() {
        head_node=get_node();
        head_node->next=head_node;
        head_node->prev=head_node;
    }
    template <class T,class Alloc>
    typename List<T,Alloc>::iterator List<T,Alloc>::begin() {
        return static_cast<iterator>(head_node->next);
    }

    template <class T,class Alloc>
    typename List<T,Alloc>::iterator List<T,Alloc>::end() {
        return static_cast<iterator>(head_node);
    }
    template <class T,class Alloc>
    bool List<T,Alloc>::empty() {
        return head_node->next == head_node;
    }
    template <class T,class Alloc>
    typename List<T,Alloc>::reference List<T,Alloc>::front() {
        return head_node->data;
    }
    template <class T,class Alloc>
    typename List<T,Alloc>::reference List<T,Alloc>::back() {
        return end().node.data;
    }

    template <class T,class Alloc>
    typename List<T,Alloc>::iterator List<T,Alloc>::insert(List<T,Alloc>::iterator position, const T & x) {
        node_ptr_type new_node=create_node(x);
        iterator tmp=position.node.next;//临时节点，用来记录下一个节点指针
        position.node.next=new_node;//当前节点后面插入新节点
        new_node->prev=position;
        new_node->next=position;//新节点的后面指向临时节点
        position.node.prev=new_node;
        return position;
    }

    template <class T,class Alloc>
    void List<T,Alloc>::push_back(const T & x) {
        node_ptr_type new_node=create_node(x);
        node_ptr_type last= static_cast<node_ptr_type>(head_node->prev);//得到最尾巴上的节点last
        last->next=new_node;//新节点放在last节点的后面
        new_node->prev=last;
        head_node->prev=new_node;//空节点放在和尾节点连接起来
        new_node->next=head_node;
    }

    template <class T,class Alloc>
    void List<T,Alloc>::push_front(const T &x) {
        node_ptr_type new_node=create_node(x);//新节点
        node_ptr_type tmp=head_node->next;//当前第一个节点
        head_node->next=new_node;//将新节点插入头部
        new_node->prev=head_node;
        new_node->next=tmp;//连接新节点和之前的第一个节点tmp
        tmp->prev=new_node;
    }

    template <class T,class Alloc>
    void List<T,Alloc>::pop_back() {
        node_ptr_type last_node=head_node->prev;//把最后一个节点摘下来
        node_ptr_type tmp=head_node->prev->prev;
        tmp->next=head_node;
        head_node->prev=tmp;
        destory_node(last_node);//销毁最后一个节点
    }

    template <class T,class Alloc>
    void List<T,Alloc>::pop_front() {
        node_ptr_type first=head_node->next;//把第一个节点摘下来
        node_ptr_type tmp=first->next;
        head_node->next=tmp;
        tmp->prev=head_node;
        destory_node(first);//销毁第一个节点
    }

    template <class T,class Alloc>
    typename List<T,Alloc>::iterator List<T,Alloc>::erase(List<T,Alloc>::iterator pos) {
        node_ptr_type pos_front=pos.node->prev;
        node_ptr_type pos_next=pos.node->next;
        destory_node(pos.node);//删除当前节点
        pos_front->next=pos_next;//将前后两个节点连接起来
        pos_next->prev=pos_front;
        iterator ret(pos_next);
        return ret;//返回
    }

    template <class T,class Alloc>
    void List<T,Alloc>::clear() {
        for(List<T,Alloc>::iterator iter=begin();iter!=end();++iter)
            erase(iter);
        head_node->next=head_node;
        head_node->prev=head_node;
    }

    template<class T,class Alloc>
    void List<T,Alloc>::remove(const T & value) {
        for(iterator iter=begin();iter!=end();++iter){
            if(iter.node->data==value) erase(iter);
        }
    }

    //注意这个函数移除的是连续且相同的两个元素
    template <class T,class Alloc>
    void List<T,Alloc>::unique() {
        iterator first= begin();
        iterator last= end();
        iterator next=first;
        if(begin()==end()) return;
        while(++next!=last){
            if(*first==*next){
                erase(next);
            }
            else
                first=next;
            next=first;
        }
    }

    //将[first,last)内的所有元素移动到position之前
    template <class T,class Alloc>
    void List<T,Alloc>::transfer(List::iterator pos, List::iterator first, List::iterator last) {
        node_ptr_type tmp=pos.node->prev;
        last.node->prev->next=pos.node;
        first.node->prev->next=last.node;
        tmp->next=first.node;
        pos.node->prev=last.node->prev;
        last.node->prev=first.node->prev;
        first.node->prev=tmp;
    }

    //将list x放在pos之前
    template <class T,class Alloc>
    void List<T,Alloc>::splice(List::iterator pos, List<T, Alloc> & x) {
        transfer(pos,x.begin(),x.end());
    }

    //将i放在pos之前
    template <class T,class Alloc>
    void List<T,Alloc>::splice(List::iterator pos, List<T, Alloc> & x, List::iterator i) {
        iterator j=i;
        ++j;
        if(pos==i||pos==j) return;
        transfer(pos,i,j);
    }

    //将[first,last)内容放在pos之前
    //pos和[first,last)可以指向同一个list
    //但pos不能位于[first,last)内部
    template <class T,class Alloc>
    void List<T,Alloc>::splice(List::iterator pos, List<T, Alloc> & x, List::iterator first, List::iterator last) {
        if(first!=last) transfer(pos,first,last);
    }

    //将两个排好序的list合并在一起
    //这是《数据结构》第二章的一个练习题
    template <class T,class Alloc>
    void List<T,Alloc>::merge(mystl::List<T, Alloc> &x) {
        iterator first1=this->begin();
        iterator last1=this->end();
        iterator first2=this->begin();
        iterator last2=this->end();
        while(first1!=last1&&first2!=last2){
            if(*first1>*first2){
                iterator next=first2;
                transfer(first1,first2,++next);
                first2=next;
            }else ++first1;
        }
        if(first2!=last2) transfer(last1,first2,last2);
    }

    //将*this中的内容转置,算法过程相当于从第二个开始，对后面的所有元素进行头插
    template <class T,class Alloc>
    void List<T,Alloc>::reverse() {
        iterator first=begin();
        if(first.node->next==first || first.node->next->next==first) return;
        ++first;
        while(first!=end()){
            iterator old=first;
            ++first;
            transfer(begin(),old,first);
        }
    }

    //list无法使用STL算法中的sort(),因为其迭代器不是random accessed，需要自己实现
    //list内置sort()采用快排
    template <class T,class Alloc>
    void List<T,Alloc>::sort() {

    }
}
#endif //MYTINYSTL_LIST_H
