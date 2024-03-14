#include "../vector.h"

int vector_cmp_uint32_t (uint32_t *v1, uint32_t *v2){
    int ret;

    if (*v1 < *v2){
        ret = -1;
    }else if (*v1 > *v2){
        ret = 1;
    }else{
        ret = 0;
    }

    return ret;
}
