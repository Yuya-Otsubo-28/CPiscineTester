#include "../vector.h"

int vector_cmp_int64_t (int64_t *v1, int64_t *v2){
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
