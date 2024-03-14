#include "../string.h"

int string_cmp(string v1, string v2){
    int ret;
    uint64_t a1;
    int64_t a2;

    a1 = ((a2 = (v1->__length - v2->__length)) < 0 ? v1->__length : v2->__length);
    ret = memcmp (v1->__data, v2->__data, a1);
    if (!ret){
        ret = a2;
    }

    return ret;
}
