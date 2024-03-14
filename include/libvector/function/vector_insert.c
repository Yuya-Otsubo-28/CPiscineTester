#include "../vector.h"

vector_ret vector_insert(vector v1, uint64_t point, vector v2){
    vector_ret ret = VR_NONE;
    void *a1;
    void **a2;
    void **a3;
    uint64_t len, sum_len;
    uint64_t extension_size;
    
    if (v1->__length < point){
        ret = VRE_NOPOSITION;
        return ret;
    }

    if (!v2){
        
        return ret;
    }

    sum_len = v1->__length+v2->__length;
    if (v1->__size <= sum_len){
        extension_size=v1->__size;
        while (extension_size*=2 < sum_len);

        ret = vector_resize (v1, extension_size);
        if (ret){
           return ret; 
        }
    }

    if (v1->__data0){
        if (v1->__length != point){
            for (uint64_t j = 0; j < v1->__length-point; j ++){
                a2 = v1->__data0+v2->__length+point+j;
                a3 = v1->__data0+point+j;
                *a2 = *a3;
                *a3 = NULL;
            }
        }
        for (uint64_t j = point, k = 0; k < v2->__length; j ++, k ++){
            a2 = (v1->__data0+j);
            a3 = (v2->__data0+k);
            v1->__copy_function (a2, *a3);
        }
        
    }else{
        if (v1->__length != point){
            memcpy (v1->__data1+(v2->__length*v2->__memory_size+point*v1->__memory_size), v1->__data1+point*v1->__memory_size, v1->__length*v1->__memory_size-point*v1->__memory_size);
        }

        memcpy (v1->__data1+(point*v1->__memory_size), v2->__data1, v2->__length*v2->__memory_size);
    }

    v1->__length += v2->__length;

    return ret;
}
