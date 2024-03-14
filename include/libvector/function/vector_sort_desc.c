#include "../vector.h"

vector_ret vector_sort_desc(vector v1){
    vector_ret ret = VR_NONE;

    if (v1->__data0){
        void **a1 = (void**)malloc (v1->__length*v1->__memory_size);
        if (!a1){
            ret = VRE_ALLOCATE_MEMORY;
            return ret;
        }

        __vector_pointer_quick_sort_desc (v1->__data0, a1, v1->__length, v1->__cmp_function);

        free (a1);
    }else{
        void *a1 = (void*)malloc (v1->__memory_size*v1->__length);
        if (!a1){
            ret = VRE_ALLOCATE_MEMORY;
            return ret;
        }

        __vector_value_quick_sort_desc (v1->__data1, a1, v1->__memory_size, v1->__length, v1->__cmp_function);

        free (a1);
    }

    return ret;
}
