/***********************************************************************************************************************
 * Created by caffe on 2019/11/25.
 *
 **********************************************************************************************************************/
#ifndef MYTINYSTL_CONSTRUCT_H
#define MYTINYSTL_CONSTRUCT_H
namespace mystl{
//#include <new.h>
    template <class T1,class T2>
    inline void construct(T1* p,T2& value)  throw(int) {
        new (p) T1(value);
        if(p == nullptr) throw (-1);
    }

    template <class T>
    inline void destory(T *obj){
        obj->~T();
    }

    template <class ForwardIterator>
    inline void destory(ForwardIterator first,ForwardIterator last){
        ForwardIterator iter;
        for(iter=first;iter!=last;++iter)
            destory(&(*first));
    }

    inline void destory(char*,char*){}
    inline void destory(wchar_t *,wchar_t*){}
}
#endif //MYTINYSTL_CONSTRUCT_H
