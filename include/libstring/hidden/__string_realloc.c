#include "../string.h"

string_ret __string_realloc(string v1, uint64_t size){
    string_ret ret = SR_NONE;
    char *a1 = NULL;

    a1 = (char*)realloc (v1->__data, size);
    if (a1 == NULL){
        ret = SRE_ALLOCATE_MEMORY;
    }else{
        if (a1 != v1->__data){
            v1->__data = a1;
        }

        v1->__size = size;

        if (v1->__size - 1 < v1->__length){
            v1->__length = v1->__size;
        }

        v1->__data[v1->__length] = 0;
    }

    return ret;
}
