#include "../string.h"

uint64_t string_find(string v1, uint64_t begin, uint64_t end, const char v2){
    uint64_t ret = 0xffffffff;
    uint64_t extension_size;

    if (end == -1){
        end = v1->__length;
    }

    if (begin < end && v1->__length < end){
        return ret;
    }

    for (const char *j = v1->__data+begin; j < v1->__data+end; j ++){
        if (*j == v2){
            ret = j - v1->__data;
            break;
        }
    }

    return ret;
}
