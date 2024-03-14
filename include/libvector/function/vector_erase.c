#include "../vector.h"

vector_ret vector_erase(vector v1, uint64_t begin, uint64_t end){
    vector_ret ret = VR_NONE;

    if (end == -1){
        end = v1->__length;
    }
    
    if (!(begin < end && end <= v1->__length)){
        ret = VRE_NOPOSITION;
        return ret;
    }

    if (v1->__data0){
        void **a1;
        void **a2;

        for (uint64_t j = begin; j < end; j ++){
            a1 = v1->__data0+j;
            if (*a1){
                v1->__free_function (*a1);
            }
        }

        for (uint64_t j = end, k = begin; j < v1->__length; j ++, k ++){
            a1 = v1->__data0+k;
            a2 = v1->__data0+j;
            *a1 = *a2;
            *a2 = NULL;
        }
    }else{
        memcpy (v1->__data1+begin, v1->__data1+end, (v1->__length-end)*v1->__memory_size);
    }

    v1->__length -= end - begin;

    return ret;
}
