#include "../vector.h"

void *vector_get (vector v1, uint64_t point){
    void *ret = NULL;
    if (v1->__length < point){
        return ret;
    }

    if (v1->__data0){
        ret = (v1->__data0[point]);
    }else{
        ret = (v1->__data1+v1->__memory_size*point);
    }

    return ret;
}
