/***********************************************************************************************************************
 * Created by caffe on 2019/11/20.
 *
 **********************************************************************************************************************/
#ifndef MYTINYSTL_ALLOC_H
#define MYTINYSTL_ALLOC_H
#include "envs_msg.h"
#include <cstddef>
#include <cstdlib>

namespace mystl{
/**
 * @name Primary allocator
 *
 */
 class malloc_alloc{
    public:
        static void* oom_allocate(size_t nbytes);
        static void* oom_reallocate(void* old_ptr,size_t nbytes);
        static void (*oom_handler)();
    public:
        static void* allocate(size_t nbytes);
        static void* reallocte(void* old_ptr,size_t nbytes);
        static void deallocate(void *ptr,size_t nbytes);
        static void (*set_oom_handler(void (*f)()))(){
            void (*old_hanlder)()=oom_handler;
            oom_handler=f;
            return old_hanlder;
        };
    };
    void (*malloc_alloc::oom_handler)()= nullptr;
    /*using C function malloc to allocate nbytes memory and return a void* */
    void *malloc_alloc::allocate(size_t nbytes) {
        void* ret=malloc(nbytes);
        if(ret!=nullptr) return ret;
        else return oom_allocate(nbytes);
    }
    /*using malloc to allocate new nbytes memory and free old memory*/
    void *malloc_alloc::reallocte(void *old_ptr, size_t nbytes) {
        void* ret=realloc(old_ptr,nbytes);
        if(ret!= nullptr){
            return ret;
        }else return oom_reallocate(old_ptr,nbytes);
    }
    /*using free to deallocate memory*/
    void malloc_alloc::deallocate(void *ptr, size_t nbytes) {
        free(ptr);
    }
    /*out of memory allocate */
    void* malloc_alloc::oom_allocate(size_t nbytes) {
        void (*oom_handler_func)();
        void* ret=nullptr;
        while (true){
            oom_handler_func=oom_handler;
            if(oom_handler_func== nullptr) throw("_BAD_ALLOC");
            oom_handler_func();
            ret=malloc(nbytes);
            if(ret) return ret;
        }
    }
    /*out of memory reallocate*/
    void* malloc_alloc::oom_reallocate(void *old_ptr, size_t nbytes) {
        void (*oom_handler_func)();
        void* ret=nullptr;
        while (true){
            oom_handler_func=oom_handler;
            if(oom_handler_func== nullptr) throw("_BAD_ALLOC");
            oom_handler_func();
            ret=realloc(old_ptr,nbytes);
            if(ret) return ret;
        }
    }
/**
 * @name Secondary allocator
 *
 */
     enum {MAXSIZE=512};
     enum {BLOCKSIZE=32};
     enum {FREELISTNUM=16};
     class default_alloc{
     public:
        union obj{
            union obj* next;
            char* val[1];
        };
     private:
        static char* mempool_beg;
        static char* mempool_end;
        static int heap_size;
        static obj* volatile free_lists[FREELISTNUM];
        static void* refill(size_t nbytes);
        static void* chunk_alloc(size_t nbytes,size_t &nobjs);
//        static size_t get_roundup(size_t nbytes);
        static size_t get_index(size_t nbytes);

    public:
        static void* allocate(size_t nbytes);
        static void* reallocte(void* old_ptr,size_t nbytes);
        static void deallocate(void *ptr,size_t nbytes);

    };
    char* default_alloc::mempool_beg = nullptr;
    char* default_alloc::mempool_end = nullptr;
    int default_alloc::heap_size = 0;
    default_alloc::obj* volatile default_alloc::free_lists[FREELISTNUM]={0};
    size_t default_alloc::get_index(size_t nbytes) {
        return nbytes==0 ? 0:(nbytes-1)/(size_t)BLOCKSIZE;
    }

//    unsigned long default_alloc::get_roundup(size_t nbytes) {
//        return (nbytes+(size_t)(BLOCKSIZE-1))/(size_t)(BLOCKSIZE);
//    }

    void* default_alloc::allocate(size_t nbytes){
        void *ret= nullptr;
        //申请内存数目过大，使用一级配置器
        if(nbytes>MAXSIZE) return malloc_alloc::allocate(nbytes);
        //找到相应自由链表位置
        obj* cur_free_list=*(free_lists+get_index(nbytes));
        //该位置没有内存则向内存池申请，有则取下第一块内存
        if(cur_free_list==nullptr){
            ret=refill(nbytes);
        }else{
            ret=cur_free_list;
            cur_free_list=cur_free_list->next;
        }
        return ret;
    }

    void default_alloc::deallocate(void *ptr, size_t nbytes){
        //大块内存，直接用一级配置器free掉
        if(nbytes>MAXSIZE){
            malloc_alloc::reallocte(ptr,nbytes);
            return;
        }
        //找到当前大小内存块在自由链表中的适合位置，这里的原则是应当比自由链表中标准内存块小一个尺寸。
        obj* cur_free_list=*(free_lists+get_index(nbytes)-1);
        //把需要释放的内存接到自由链表上。
        obj* tmp=cur_free_list;
        cur_free_list = reinterpret_cast<obj* >(ptr);
        cur_free_list->next = tmp;
    }

    void* default_alloc::reallocte(void *old_ptr, size_t nbytes) {
        //释放掉原先的内存块
        deallocate(old_ptr,nbytes);
        //重新分配新的内存块
        void* new_ptr=allocate(nbytes);
        //返回新分配内存块的指针
        return new_ptr;
    }

    void* default_alloc::chunk_alloc(size_t nbytes, size_t &nobjs) {
        //内存池剩余内存字节数
        size_t total_bytes=mempool_end-mempool_beg;
        //需分配的字节数
        size_t required_bytes=nbytes*nobjs;
        void* ret=nullptr;
        //内存池剩余量大于nobjs块，直接分配。
        if(total_bytes/nbytes>nobjs){
            ret= reinterpret_cast<void* >(mempool_beg);
            mempool_beg+=required_bytes;
        }
        //内存池剩余量大于1个却小于nobjs个，返回能返回的最大内存数量。
        else if(total_bytes/nbytes>=1&&total_bytes/nbytes<nobjs){
            nobjs=total_bytes/nbytes;
            ret= reinterpret_cast<void* >(mempool_beg);
            mempool_beg+=nobjs*nbytes;
        }
        //内存池存量小于1个了，使用malloc从系统申请。
        else if(total_bytes/nbytes<1){
            //先将内存池剩余的内存挂在自由链表上
            size_t left_bytes=mempool_end-mempool_end;
            //剩余为0显然不能挂，多于0的话同样挂在小一个尺寸的位置。
            if(left_bytes>BLOCKSIZE) {
                obj *cur_free_list = *(free_lists + get_index(total_bytes) - 1);
                obj *tmp = cur_free_list;
                cur_free_list = reinterpret_cast<obj * >(mempool_beg);
                cur_free_list->next = tmp;
            }
            //先尝试在自由链表上找一块大小合适的内存解决燃煤之急。
            for(size_t i=get_index(nbytes);i+1<FREELISTNUM;++i){
                obj *cur_free_list = *(free_lists + i+1);
                if(cur_free_list!= nullptr){
                    nobjs=(i+1)*BLOCKSIZE/nbytes;
                    ret = cur_free_list;
                    cur_free_list=cur_free_list->next;
                    return ret;
                }
            }
            //分配新内存，内存数量随着分配的个数变大而变多。
            size_t new_bytes=2*nobjs*nbytes+heap_size>>4;
            //申请新内存
            char *new_mem= reinterpret_cast<char* >(malloc(new_bytes));
            //系统内卒不足，调用一级配置器处理
            if(new_mem== nullptr){
                ret=malloc_alloc::oom_allocate(nobjs*nbytes);
            }
            //调整内存池状态，并重新调用该函数进行分配。
            else{
                mempool_beg=new_mem;
                heap_size+=new_bytes;
                mempool_end=mempool_beg+new_bytes;
                return chunk_alloc(nbytes,nobjs);
            }
        }
        return ret;
    }

    void* default_alloc::refill(size_t nbytes) {
        size_t nobjs=20;
        //向自由链表申请内存块
        void* chunk=chunk_alloc(nbytes,nobjs);
        void* ret = nullptr;
        //只有一块，返回即可
        if(nobjs==1) return chunk;
        //多于一块，返回一块，并将其它的块挂载在自由链表上面。
        ret=chunk;
        obj* cur_free_list=*(free_lists+get_index(nbytes));
        for(size_t i=1;i<nobjs;++i){
            obj* tmp=cur_free_list;
            cur_free_list = reinterpret_cast<obj* >(chunk)+i*nbytes;
            cur_free_list->next=tmp;
        }
        return ret;
    }
    /**
     * @name simply_alloc
     * 为所用的容器提供空间配置器的接口，通过这个接口调用一级或者二级空间配置器。
     */
    template <class T,class Alloc=default_alloc>
    class simply_alloc{
    public:
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
    public:
        static pointer allocate(size_type n){
            return 0==n ? 0:static_cast<pointer >(Alloc::allocate(n* sizeof(T)));
        }
        static void deallocate(pointer ptr){
            Alloc::deallocate(ptr, sizeof(T));
        }
        static void deallocate(pointer ptr,size_type n){
            if(0!=n)    Alloc::deallocate(ptr,n* sizeof(T));
        }
        static pointer reallocate(pointer ptr,size_type nbytes){
            return 0==nbytes? 0:static_cast<pointer >(Alloc::reallocate(ptr,nbytes));
        }
    };
}
#endif //MYTINYSTL_ALLOC_H
