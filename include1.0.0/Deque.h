//
// Created by caffe on 2019/12/20.
//
#ifndef MYTINYSTL_DEQUE_H
#define MYTINYSTL_DEQUE_H
#include "envs_msg.h"
#include "Alloc.h"
#include <cstddef>
#ifdef envs_windows
#endif
namespace mystl{
    template <class T,class Alloc=mystl::default_alloc>
    class deque_iter{
    public:
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef size_t size_type;
        typedef ptrdiff_t diff_type;
        typedef pointer* map_pointer;
        typedef mystl::simply_alloc<T,Alloc> data_allocate;
        typedef deque_iter<T> self;
//    protected:
    public:
        pointer cur;
        pointer first;
        pointer last;
        map_pointer node;
        static size_type buf_sz;
        size_type node_sz=1024;
        map_pointer node_start;
    public:
        static size_type buff_size(size_type bufsz);
        static size_type deque_buff_size(size_type bufsz,size_type sz);
    public:
        deque_iter();
        deque_iter(const self &x);
        self& operator=(const self& x);
        reference operator*() const;
        pointer operator->() const;
        void set_node(map_pointer new_node);
        diff_type operator-(const self& x);
        self& operator++();
        self& operator++(int);
        self& operator--();
        self& operator--(int);
        self& operator+=(const diff_type i);
        self& operator-=(const self& x);
        self& operator+(const self& x);
        reference operator[](size_type i);
        bool operator==(const self& x);
        bool operator!=(const self& x);
        bool operator<(const self& x);
    };
    template <class T, class Alloc>
    typename deque_iter<T,Alloc>::self & deque_iter<T,Alloc>::operator+=(const diff_type i) {
        if(cur+i < last){//still in current node
            cur+=i;
        }else{//must jump a node;
            if(node < node_start+node_sz) ++node;
            else perror("memory size is too big, you can modify node_sz to solve this problem\n");
            if(*node== nullptr) *node = data_allocate ::allocate(buf_sz);
            cur = *node + (i-(last-first));
            first =  *node;
            last = first+buf_sz;
        }
        return *this;
    }
    /**
     * @brief : reload operator--
     * @return
     */
    template <class T,class Alloc>
    typename deque_iter<T,Alloc>::self & deque_iter<T,Alloc>::operator--() {
        if(cur > first){
            cur--;
        }else{
            if(node > node_start) --node;
            else perror("memory size is too big, you can modify node_sz to solve this problem\n");
            if(*node == nullptr){
                *node = data_allocate::allocate(buf_sz);
            }
            first = *node;
            last = first + buf_sz;
            cur = last-1;
        }
        return *this;
    }
    /**
    * @brief : reload operator--
    * @return
    */
    template <class T,class Alloc>
    typename deque_iter<T,Alloc>::self & deque_iter<T,Alloc>::operator--(int ) {
        self& ret = *this;
        if(cur > first){
            cur--;
        } else{
            if(node > node_start) --node;
            else perror("memory size is too big, you can modify node_sz to solve this problem\n");
            if( *node == nullptr){
                *node = data_allocate::allocate(buf_sz);
            }
            first = *node;
            last = first+buf_sz;
            cur = last-1;
        }
        return ret;
    }
    /**
     * call the copy constructor of deque_iter
     * @param x
     * @return
     */
    template <class T,class Alloc>
    typename deque_iter<T,Alloc>::self& deque_iter<T,Alloc>::operator=(const deque_iter::self & x) {
        *this(x);
        return *this;
    }
    /**
     * @brief : copy constructor
     * @param x
     */
    template <class T,class Alloc>
    deque_iter<T,Alloc>::deque_iter(const mystl::deque_iter<T, Alloc>::self &x) {
        node = x.node;
        node_start = x.node_start;
        node_sz = x.node_sz;
        cur = x.cur;
        first = x.first;
        last = x.last;
    }

    /**
     * @brief : default constructor
     */
    template <class T,class Alloc>
    deque_iter<T,Alloc>::deque_iter() {
        //initialing the center control
        node_start = static_cast<map_pointer >(mystl::simply_alloc<pointer>::allocate(node_sz));
        for(int i=0;i<node_sz;++i) *(node_start+i) = nullptr;
        *node_start = static_cast<pointer>(data_allocate::allocate(buf_sz));
        //let node to point to middle node.
        node =node_start+node_sz/2;
        cur = *node; //initial cur,first and last
        first = *node;
        last = first + buf_sz;
    }
    template <class T,class Alloc>
    typename deque_iter<T,Alloc>::self & deque_iter<T,Alloc>::operator++() {
        if(cur<last-1){//if pointer cur can move at least one step,move it and return.
            ++cur;
        }else{//if current node no more space, jump to next buffer(according to map_pointer node)
            if(node<node_start+node_sz) node++;
            else perror("memory size is too big, you can modify node_sz to solve this problem\n");
            if(*node == nullptr){
                *node = static_cast<pointer>(data_allocate::allocate(buf_sz));
            }
            cur = *node;
            first = *node;
            last = first+buf_sz;
        }
        return *this;
    }

    template <class T,class Alloc>
    typename deque_iter<T, Alloc>::self & deque_iter<T,Alloc>::operator++(int) {
        self ret = *this;
        //so as to operator++();
        if(cur<last-1){
            ++cur;
        }else{
            if(node<node_start+node_sz) node++;
            else perror("memory size is too big, you can modify node_sz to solve this problem\n");
            if(*node == nullptr) *node = static_cast<pointer>(data_allocate::allocate(buf_sz));
            cur = *node;
            first = *node;
            last = first + buf_sz;
        }
        return ret;
    }
    //get and set static member variance "bufsz"
    template <class T,class Alloc>
    typename deque_iter<T,Alloc>::size_type deque_iter<T,Alloc>::buff_size(deque_iter::size_type bufsz) {
        bufsz=deque_buff_size(bufsz, sizeof(T));
        return bufsz;
    }

    //n!=0 using user defines value
    //n==0 using default value,it should be 512/sz if sz<512,else 1
    template <class T,class Alloc>
    typename deque_iter<T,Alloc>::size_type deque_iter<T,Alloc>::deque_buff_size(deque_iter<T,Alloc>::size_type n, deque_iter::size_type sz) {
        return n==0 ? n:(sz<512 ? size_t(512/sz) : size_t(1));
    }
    
    template <class T,class Alloc>
    typename deque_iter<T,Alloc>::size_type deque_iter<T,Alloc>::buf_sz=512;

    template <class T,class Alloc>
    typename deque_iter<T,Alloc>::reference deque_iter<T,Alloc>::operator*() const{
        return const_cast<reference >(*cur);
    }

    template <class T,class Alloc>
    typename deque_iter<T,Alloc>::pointer deque_iter<T,Alloc>::operator->() const{
        return const_cast<pointer >(&(*cur));
    }
    /**
     * @brief using set_node() to change current buffer.first, set member variance node to new_node
     * second, set first to buffer's head, thirdly, set last to buffer's last.
     * @param new_node : new buffer pointer
     */
    template <class T,class Alloc>
    void deque_iter<T,Alloc>::set_node(deque_iter<T,Alloc>::map_pointer new_node) {
        node = new_node;
        first = *node;
        last = first + static_cast<diff_type >(buf_sz);
    }
    /**
     *@brief : calculates the distance between iterator x and this iterator.first, we should calculate
     * how many buffers between this and x, as a result of excluding buffer x and buffer this, buffers
     * number = node - x.node +1 -2 = node - x.node -1.second, we suppose that this buffer in front of
     * buffer x, so the length of this buffer and x buffer should be "cur-first" and "x.last-x.cur".
     * therefore: dist = buf_sz*(node-x.node-1)+(cur-first)+(x.last-x.cur)
     * @param x
     * @return
     */
    template <class T,class Alloc>
    typename deque_iter<T,Alloc>::diff_type deque_iter<T,Alloc>::operator-(const deque_iter::self & x) {
        return static_cast<diff_type >(buf_sz*(node-x.node-1)+(cur-first)+(x.last-x.cur));
    }
}
#endif //MYTINYSTL_DEQUE_H


