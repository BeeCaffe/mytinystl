/***********************************************************************************************************************
 * Created by caffe on 2019/12/2.
 *
 **********************************************************************************************************************/
#ifndef MYTINYSTL_LIST_H
#define MYTINYSTL_LIST_H

#include "Construct.h"
#include <lzma.h>
#include "Alloc.h"

namespace mystl{
    /**
     * @brief the struct of list node,which contains two pointer and a data.pointer prev point to the front node,
     * pointer next points the next node.
     * @tparam T : type
     */
    template <class T>
    struct list_node{
        void *prev;
        void *next;
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
        node_type node;
    public:
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
    bool list_iter<T>::operator==(const mystl::list_iter<T>::self &x) {
        return node.data==x.node.data;
    }

    template <class T>
    bool list_iter<T>::operator!=(const mystl::list_iter<T>::self &x) {
        return node.data!=x.node.data;
    }

    template <class T>
    typename list_iter<T>::reference list_iter<T>::operator*() const {
        return node.data;
    }

    template <class T>
    typename list_iter<T>::pointer list_iter<T>::operator->() const {
        return &node;
    }

    template <class T>
    typename list_iter<T>::self& list_iter<T>::operator++() {
        node=node.next;
        return *this;
    }

    template <class T>
    typename list_iter<T>::self& list_iter<T>::operator++(int) {
        self tmp=*this;
        node=node.next;
        return tmp;
    }

    template <class T>
    typename list_iter<T>::self& list_iter<T>::operator--() {
        node=node.prev;
        return *this;
    }

    template <class T>
    typename list_iter<T>::self& list_iter<T>::operator--(int) {
        self tmp=*this;
        node=node.prev;
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
        node_ptr_type p_node;
        node_ptr_type get_node();
        void put_node(node_ptr_type node_ptr);
        node_ptr_type create_node(const T& val);
        void destory_node(node_ptr_type ptr);
        void empty_initialized();

    public:
        List():p_node(nullptr){}
        List(const T& val){
            p_node->data=val;
        }

    };

    template <class T,class Alloc>
    typename List<T,Alloc>::node_ptr_type List<T,Alloc>::get_node() {
        return data_alloc::allocate(1);
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
        p_node=get_node();
        p_node->next=p_node;
        p_node->prev=p_node;
    }
}
#endif //MYTINYSTL_LIST_H
