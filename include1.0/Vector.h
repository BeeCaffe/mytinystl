/***********************************************************************************************************************
 * Created by caffe on 2019/11/27.
 *
 **********************************************************************************************************************/
#ifndef MYTINYSTL_VECTOR_H
#define MYTINYSTL_VECTOR_H

#include <lzma.h>
#include "Alloc.h"
#include "Uninitialized.h"

namespace mystl{
    template <class T,class Alloc=mystl::simply_alloc<T>>
    class Vector{
    public:
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef T* iterator;
    protected:
        iterator start;
        iterator finish;
        iterator end_of_storage;
        typedef Alloc data_alloc;
        void deallocate();
        void fill_initialize(size_type n,const T& value);
        iterator allocate_and_fill(size_type n,const T& value);

    public:
        Vector()= default;
        Vector(size_type n,const T& value);
        Vector(int n,const T& value);
        Vector(int long,const T& value);
        ~Vector();
        iterator begin();
        iterator end();
        size_type size();
        bool empty();
        void clear();
        size_type capacity();
        void push_back(const T& value);
        void pop_back();
        reference operator[](size_type i);
        reference front();
        reference back();
        void insert(iterator position,size_type n, const value_type& value);
        void resize(size_type new_sz, const value_type &value);
        void resize(size_type new_sz);
        iterator earse(iterator position);
        iterator earse(iterator first,iterator last);
    };
    /**
     * @brief using space allocator to allocate 'n' space and construct it by 'value'.
     * @tparam T : type
     * @param n : number of you suppose to allocate.
     * @param value : the value you fill.
     * @return the first iterator.
     */
    template <class T,class Alloc>
    typename Vector<T,Alloc>::iterator Vector<T,Alloc>::allocate_and_fill(mystl::Vector<T,Alloc>::size_type n, const T &value) {
        pointer ptr=data_alloc::allocate(n);
        mystl::uninitialized_fill_n(ptr,n,value);
        return ptr;
    }
    /**
     * @brief allocate 'n' value and fill it by 'value',meanwhile, initializing start,finish and end_of_storage.
     * @tparam T : type
     * @param n : how many elements to allocate
     * @param value : the value of filling.
     */
    template <class T,class Alloc>
    void Vector<T,Alloc>::fill_initialize(mystl::Vector<T,Alloc>::size_type n, const T &value) {
        start=allocate_and_fill(n,value);
        finish=start+n;
        end_of_storage=finish;
    }
    /**
     * @brief deallocate all memory space in vector.
     * @tparam T : type
     */
    template <class T,class Alloc>
    void Vector<T,Alloc>::deallocate() {
        if(start) data_alloc::deallocate(start, sizeof(end_of_storage-start));
    }
    /**
     * @brief get the first iterator of vector.
     * @tparam T type
     * @return first iterator
     */
    template <class T,class Alloc>
    typename Vector<T,Alloc>::iterator Vector<T,Alloc>::begin() {
        return start;
    }
    /**
     * @brief get the last iterator of vector.
     * @tparam T type
     * @return first iterator
     */
    template <class T,class Alloc>
    typename Vector<T,Alloc>::iterator Vector<T,Alloc>::end() {
        return finish;
    }
    /**
     * @brief : get the size of vector.
     * @return size
     */
     template <class T,class Alloc>
    typename Vector<T,Alloc>::size_type Vector<T,Alloc>::size() {
        return static_cast<size_type >(finish-start);
    }
    /**
     * @brief append an element to the end of vector.Deserve to notice that if element numbers are exceed
     * the capacity of vector,this function will reallocate 2*capacity numbers of space,and remove those
     * elements to new memory and deallocate previous space.
     * @param value
     */
    template <class T,class Alloc>
    void Vector<T,Alloc>::push_back(const T &value) {
        int capacities=capacity();
        int sz=size();
        if(sz+1<=capacities){
            *(finish++)=value;
        }else{
            iterator new_start=data_alloc::allocate(2*capacities);
            iterator new_capacity=new_start+2*capacities;
            iterator new_finish=new_start+size();
            for(int i=0;i<size();++i){
                *(new_start+i)=*(begin()+i);
            }
            for(iterator iter=begin();iter!=end();++iter) mystl::destory(iter);
            deallocate();
            start=new_start;
            finish=new_finish;
            end_of_storage=new_capacity;
            *(finish++)=value;
        }
    }
    /**
     * @brief get the maximum numbers of vector can hold.
     * @return capacity of vector
     */
    template <class T,class Alloc>
    typename Vector<T,Alloc>::size_type Vector<T,Alloc>::capacity() {
        return static_cast<size_type >(end_of_storage-start);
    }

    /**
     * @brief constructor of vector.using value to construct.
     * @tparam T : type
     * @tparam Alloc : allocator
     * @param n : number
     * @param value : value
     */
    template <class T,class Alloc>
    Vector<T,Alloc>::Vector(unsigned long n, const T &value) {
       fill_initialize(n,value);
    }
    template <class T,class Alloc>
    Vector<T,Alloc>::Vector(int n, const T &value) {
        fill_initialize(n,value);
    }
    template <class T,class Alloc>
    Vector<T,Alloc>::Vector(long n, const T &value) {
        fill_initialize(n,value);
    }
    /**
     * @brief
     * @tparam T
     * @tparam Alloc
     * @return
     */
    template <class T,class Alloc>
    bool Vector<T,Alloc>::empty() {
        return begin()==end();
    }
    template <class T,class Alloc>
    void Vector<T,Alloc>::clear() {
    }
    /**
     * @brief destory all objects and release all memory space.
     * @tparam T : type
     * @tparam Alloc : allocator
     */
    template <class T,class Alloc>
    Vector<T,Alloc>::~Vector() {
        destory(begin(),end());
        deallocate();
    }
    /**
     * delete the last element of vector
     * @tparam T : type
     * @tparam Alloc : allocator
     */
    template <class T,class Alloc>
    void Vector<T,Alloc>::pop_back() {
        destory(&*(--finish));
    }
    /**
     * @brief get the first element of vector.
     * @tparam T : type
     * @tparam Alloc : allocate
     * @return
     */
    template <class T,class Alloc>
    typename Vector<T,Alloc>::reference Vector<T,Alloc>::front() {
        return *begin();
    }
    /**
     * @brief get the last element of vector
     * @tparam T : type
     * @tparam Alloc : allocator
     * @return
     */
    template <class T,class Alloc>
    typename Vector<T,Alloc>::reference  Vector<T,Alloc>::back(){
        return *end();
    }
    /**
     * @brief destory the object of iterator,and move the behind element forward 1 step.
     * @tparam T : type
     * @tparam Alloc : allocator
     * @param position : the iterator of you suppose to delete
     * @return the last iter
     */
    template <class T,class Alloc>
    typename Vector<T, Alloc>::iterator Vector<T,Alloc>::earse(mystl::Vector<T, Alloc>::iterator position) {
        destory(position);
        --finish;
        for(iterator iter=position; iter!=finish;++iter){
            *iter=*(iter+1);
        }
        destory(finish);
        return finish;
    }
    /**
     * @brief delete 'n' element form 'first' to 'last - 1'
     * @tparam T : type
     * @tparam Alloc : allocator
     * @param first : the first iterator
     * @param last : the last iterator
     * @return the finish iteartor
     */
    template <class T,class Alloc>
    typename Vector<T, Alloc>::iterator Vector<T,Alloc>::earse(mystl::Vector<T, Alloc>::iterator first,mystl::Vector<T, Alloc>::iterator last) {
//        for(iterator iter=first;iter!=last;++iter) earse(iter);
        for(iterator iter=first;iter!=last;++iter) *(iter)=*(iter+(last-first));
        for(iterator iter=finish-(last-first);iter!=finish;--iter) destory(iter);
        finish=finish-(last-first);
        return finish;
    }
    /**
     * @brief overload operator[],to get the element in location 'n'
     * @tparam T : type
     * @tparam Alloc : allocator
     * @param i : the element index of which you suppose to get.
     * @return element number of index i.
     */
    template <class T,class Alloc>
    typename Vector<T,Alloc>::reference Vector<T,Alloc>::operator[](unsigned long i) {
        return *(begin()+i);
    }
    template <class T,class Alloc>
    void Vector<T,Alloc>::resize(unsigned long new_sz) {
        if(new_sz>size()){
            for(int i=size();i<new_sz;++i) push_back(T());
        }else if(new_sz<size()){
            earse(begin()+new_sz-1,finish);
        }
    }

    template <class T,class Alloc>
    void Vector<T,Alloc>::resize(unsigned long new_sz, const value_type &value) {
        if(new_sz>size()){
            for(int i=size();i<new_sz;++i) push_back(value);
        }else if(new_sz<size()){
            earse(begin()+new_sz-1,finish);
        }
    }
}



#endif //MYTINYSTL_VECTOR_H
