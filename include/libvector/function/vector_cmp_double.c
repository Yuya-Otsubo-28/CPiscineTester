#include "../vector.h"

int vector_cmp_double (double *v1, double *v2){
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
