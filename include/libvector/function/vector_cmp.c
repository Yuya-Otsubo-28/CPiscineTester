#include "../vector.h"

int vector_cmp(vector v1, vector v2){
    void **a1;
    void **a2;
    int ret;
    uint64_t min_size;

    if (!v1){
        if (!v2){
            return 0;
        }else{
            return v2->__length;
        }
    }else if (!v2){
        return v1->__length*(-1);
    }
    
    if (v1->__data0 && v2->__data0){
        min_size = (v1->__length < v2->__length ? v1->__length : v2->__length);

        if (v1->__cmp_function != v2->__cmp_function){
            return (int)v1->__length - min_size;
        }

        for (uint64_t j = 0; j < min_size; j ++){
            a1 = &v1->__data0[j];
            a2 = &v2->__data0[j];
            ret = v1->__cmp_function (*a1, *a2);
            if (ret){
                return (ret < 0 ? -1*(j+1) : (j+1));
            }
        }
    }else if (v1->__data1 && v2->__data1){
        min_size = (v1->__length < v2->__length ? v1->__length : v2->__length);
        ret = memcmp (v1->__data1, v2->__data1, min_size);
        if (ret){
            return ret;
        }
    }

    if (v1->__length == v2->__length){
        return ret;
    }
    return (int)v1->__length - min_size;
}
