/***********************************************************************************************************************
 * Created by caffe on 2019/11/25.
 *
 **********************************************************************************************************************/
#ifndef MYTINYSTL_UNINITIALIZED_H
#define MYTINYSTL_UNINITIALIZED_H
#include "Construct.h"
namespace mystl{
    template <class ForwardIterator>
    inline void uninitialized_copy(ForwardIterator first,ForwardIterator last,ForwardIterator result){
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
}
#endif //MYTINYSTL_UNINITIALIZED_H
