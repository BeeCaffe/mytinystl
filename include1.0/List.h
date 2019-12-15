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
        list_iter();
        list_iter(node_ptr_type x):node(x){}
        list_iter(const list_iter &x):node(x.node){}
        self& operator=(const self &x);
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
    typename list_iter<T>::self & list_iter<T>::operator=(const list_iter<T>::self & x) {
        return x;
    }

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
//        List(const T& val){
//            empty_initialized();
//
//        }

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
        return iterator(head_node->next);
    }

    template <class T,class Alloc>
    typename List<T,Alloc>::iterator List<T,Alloc>::end() {
        return iterator (head_node);
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
        put_node(last_node);//销毁最后一个节点
    }

    template <class T,class Alloc>
    void List<T,Alloc>::pop_front() {
        node_ptr_type first=head_node->next;//把第一个节点摘下来
        node_ptr_type tmp=first->next;
        head_node->next=tmp;
        tmp->prev=head_node;
        put_node(first);//销毁第一个节点
    }

}
#endif //MYTINYSTL_LIST_H
