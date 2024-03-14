#include "../vector.h"

vector_ret vector_push_back(vector v1, void *begin){
    vector_ret ret = VR_NONE;
    void *a1;
    void **a2;

    if (v1->__size <= v1->__length+1){
        ret = vector_resize (v1, v1->__size*2);
        if (ret){
           return ret; 
        }
    }

    if (v1->__data0){
        a2 = (v1->__data0+v1->__length);
        v1->__copy_function (a2, begin);
    }else{
        a1 = (v1->__data1+v1->__length*v1->__memory_size);
        memcpy (a1, begin, v1->__memory_size);
    }

    v1->__length++;

    return ret;
}
