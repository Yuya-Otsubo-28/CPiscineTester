#include "../vector.h"

vector_ret vector_sort_asc(vector v1){
    vector_ret ret = VR_NONE;

    if (v1->__data0){
        void **a1 = (void**)malloc (v1->__length*v1->__memory_size);
        void **a2 = (void**)malloc (v1->__length*v1->__memory_size);
        if (!a1 || !a2){
            ret = VRE_ALLOCATE_MEMORY;
            return ret;
        }

        for (uint64_t j = 0; j < v1->__length; j ++){
            a1[j] = v1->__data0[j];
        }

        __vector_pointer_quick_sort_asc (a1, a2, v1->__length, v1->__cmp_function);

        for (uint64_t j = 0; j < v1->__length; j ++){
            v1->__data0[j] = a1[j];
        }

        free (a1);
        free (a2);
    }else{
        void *a1 = (void*)malloc (v1->__memory_size*v1->__length);

        __vector_value_quick_sort_asc (v1->__data1, a1, v1->__memory_size, v1->__length, v1->__cmp_function);

        free (a1);
    }

    return ret;
}
