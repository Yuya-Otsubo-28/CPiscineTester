#include "vector.h"

vector vector_init (uint64_t memory_size, void (*free_function) (void *v1), void (*copy_function) (void **v1, void *v2), int (*cmp_function) (void *v1, void *v2)){
    vector_ret ret = VR_NONE;
    vector v1;

    v1 = NULL;
    v1 = (vector)malloc (sizeof (struct __vector));
    if (v1 == NULL){
        return v1;
    }

    // ////////////////////////////////////////////////////////////////////////////////////////////
    // 
    // If you need to allocate internal memory, please substitute the source code
    v1->__length = 0;
    v1->__size = 0;
    v1->__data0 = 0;
    v1->__data1 = 0;
    v1->__memory_size = memory_size;
    v1->__free_function = free_function;
    v1->__copy_function = copy_function;
    v1->__cmp_function = cmp_function;

    ret = vector_resize (v1, __DEFAULT_VECTOR_SIZE__);
    if (ret){
        // メモリ確保に失敗しました
        vector_free (v1);
        v1 = NULL;
    }
    // ////////////////////////////////////////////////////////////////////////////////////////////
    return v1;
}

void vector_free (vector v1){
    // ////////////////////////////////////////////////////////////////////////////////////////////
    // 
    // If you need to release internal memory, please assign the source code
    if (v1->__data0 != NULL){
        void **a1;

        for (uint64_t j = 0; j < v1->__size; j ++){
            a1 = v1->__data0+j;
            if (*a1){
                v1->__free_function (*a1);
            }
        }

        free (v1->__data0);
    }

    if (v1->__data1 != NULL){
        free (v1->__data1);
    }

    // ////////////////////////////////////////////////////////////////////////////////////////////
    free (v1);
    v1 = NULL;
}
