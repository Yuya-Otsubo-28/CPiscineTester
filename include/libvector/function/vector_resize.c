#include "../vector.h"

vector_ret vector_resize(vector v1, uint64_t resize){
    vector_ret ret = VR_NONE;

    if (v1->__free_function != NULL){
        // ポインタ系
        void **a1;
        void **a2;
        void **a3;
        
        if (resize < v1->__size){
            a1 = v1->__data0;
            // 確保されているメモリを一度解放する必要がある
            for (uint64_t j = v1->__size - 1; j >= resize; j --){
                a2 = a1+v1->__memory_size*j;
                if (*a2){
                    v1->__free_function (*a2);
                    *a2 = NULL;
                }
            }

            // 確保されていたメモリを解放する
            free (a1+v1->__memory_size*resize);

        }else{
            // メモリを確保する必要がある
            a1 = (void**)realloc (v1->__data0, v1->__memory_size*resize);
            if (a1 == NULL){
                // メモリ確保に失敗しました
                ret = VRE_ALLOCATE_MEMORY;
                return ret;
            }else if (a1 != v1->__data0){
                v1->__data0 = a1;
            }
            for (uint64_t j = v1->__size; j < resize; j ++){
                a1[j] = NULL;
            }
        }

    }else{
        // 変数系
        void *a1;
        
        a1 = realloc (v1->__data1, v1->__memory_size*resize);

        if (a1 == NULL){
            ret = VRE_ALLOCATE_MEMORY;
            return ret;
        }else if (a1 != v1->__data1){
            v1->__data1 = a1;
        }
    }
    
    v1->__size = resize;
    if (v1->__size < v1->__length){
        v1->__length = v1->__size;
    }

    return ret;
}
