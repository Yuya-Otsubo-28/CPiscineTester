#include "../vector.h"

vector_ret vector_copy(vector *v1, vector v2){
    vector_ret ret = VR_NONE;
    void **a1;
    void **a2;
    void *a3;
    void *a4;

    if (*v1){
        vector_free (*v1);
    }
    // 状態を初期化する
    *v1 = vector_init (v2->__memory_size, v2->__free_function, v2->__copy_function, v2->__cmp_function);
    
    // メモリを確保し直す
    ret = vector_resize (*v1, v2->__size);
    if (ret){
        return ret;
    }

    if (v2->__data0){
        // メモリ情報をコピーする
        for (uint64_t j = 0; j < v2->__size; j ++){
            a1 = (*v1)->__data0+j;
            a2 = v2->__data0+j;

            if (*a2){
                v2->__copy_function (a1, *a2);
            }else{
                *a1 = NULL;
            }
        }
    }else{
        // メモリ情報をコピーする
        a3 = (*v1)->__data1;
        a4 = v2->__data1;
        memcpy (a3, a4, v2->__size*v2->__memory_size);
    }

    (*v1)->__length = v2->__length;
    
    return ret;
}