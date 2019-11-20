/***********************************************************************************************************************
 * Created by caffe on 2019/11/20.
 *
 **********************************************************************************************************************/
#ifndef MYTINYSTL_ALLOC_H
#define MYTINYSTL_ALLOC_H

#include <cstddef>
#include <cstdlib>

namespace mystl{
    /**
     * @name Secondary allocator
     *
     */
     enum {MAXSIZE=128};
     enum {BLOCKSIZE=8};
     enum {FREELISTNUM=16};
    class default_alloc{
    public:
        union obj{
            union obj* next;
            char* val[1];
        };
    private:
        static void* mempool_beg;
        static void* mempool_end;
        static void* heap_size;
        static obj* free_lists[FREELISTNUM];
        static void* refill(size_t nbytes);
        static void* chunk_alloc(size_t nbytes,size_t &nobjs);

    public:
        static void* allocate(size_t nbytes);
        static void* reallocte(void* old_ptr,size_t nbytes);
        static void deallocate(void *ptr,size_t nbytes);
    };
    /**
     * @name Primary allocator
     *
     */
    class molloc_alloc{
    private:
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
    void (*molloc_alloc::oom_handler)()= nullptr;
    /*using C function malloc to allocate nbytes memory and return a void* */
    void *molloc_alloc::allocate(size_t nbytes) {
        void* ret=malloc(nbytes);
        if(ret!=nullptr) return ret;
        else return oom_allocate(nbytes);
    }
    /*using malloc to allocate new nbytes memory and free old memory*/
    void *molloc_alloc::reallocte(void *old_ptr, size_t nbytes) {
        void* ret=malloc(nbytes);
        if(ret!= nullptr){
            free(old_ptr);
            return ret;
        }else return oom_reallocate(old_ptr,nbytes);
    }
    /*using free to deallocate memory*/
    void molloc_alloc::deallocate(void *ptr, size_t nbytes) {
        free(ptr);
    }
    /*out of memory allocate */
    void* molloc_alloc::oom_allocate(size_t nbytes) {
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
    void* molloc_alloc::oom_reallocate(void *old_ptr, size_t nbytes) {
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
     * @name simply_alloc
     *
     */
    template <class T,class Alloc=molloc_alloc>
    class simply_alloc{
    public:
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
    public:
        static pointer allocate(size_type nbytes){
            return static_cast<pointer >(Alloc::allocate(nbytes));
        }
        void deallocate(pointer ptr){
            Alloc::deallocate((void*)ptr,0);
        }

        void deallocate(pointer ptr,size_type n){
            Alloc::deallocate((void*)ptr,n);
        }

        pointer reallocate(pointer ptr,size_type nbytes){
            return static_cast<pointer >(Alloc::reallocate(ptr,nbytes));
        }
    };
}
#endif //MYTINYSTL_ALLOC_H
