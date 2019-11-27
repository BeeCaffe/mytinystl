/***********************************************************************************************************************
 * Created by caffe on 2019/11/25.
 *
 **********************************************************************************************************************/
#ifndef MYTINYSTL_UNINITIALIZED_H
#define MYTINYSTL_UNINITIALIZED_H

#include <cstdio>
#include <cstdlib>
#include "Construct.h"
namespace mystl{
    template <class ForwardIterator>
    inline ForwardIterator uninitialized_copy(ForwardIterator first,ForwardIterator last,ForwardIterator result){
        ForwardIterator iter=first;
        try{
            for(; iter!=last;++iter)
                mystl::construct(&(*(result+(iter-first))),*iter);
        }catch (int){
            ForwardIterator beg_iter=result;
            mystl::destory(beg_iter,beg_iter+(iter-first));
        }
        return result;
    }

    template <class ForwardIterator,class T>
    inline void uninitialized_fill(ForwardIterator first,ForwardIterator last,const T& val){
        ForwardIterator iter=first;
        try {
            for (; iter != last; ++iter)
                mystl::construct(&(*iter), val);
        }catch (int){
            mystl::destory(first,iter);
        }
    }

    template <class ForwardIterator,class T,class Size>
    inline ForwardIterator uninitalized_fill_n(ForwardIterator first,ForwardIterator last,Size n,const T& val){
        ForwardIterator iter=first;
        if(n>last-first) {
            perror("size n is too big");
            exit(0);
        }
        try{
            for(;iter!=last&&iter-first<=n;++iter) construct(&(*iter),val);
        }catch (int){
            mystl::destory(first,iter);
        }
        return iter;
    }

    template <class ForwardIterator,class T,class Size>
    inline ForwardIterator uninitialized_fill_n(ForwardIterator result,Size n,const T& value){
        ForwardIterator iter=result;
        int i;
        try {
            for (i = 0; i < n; ++i) {
                mystl::construct(&*(iter++), value);
            }
        }catch (int){
            iter=result;
            for(int j=0;j<=i;++j){
                mystl::destory(&*(iter++));
            }
        }
    }
}
#endif //MYTINYSTL_UNINITIALIZED_H
