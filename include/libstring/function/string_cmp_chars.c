#include "../string.h"

int string_cmp_chars(string v1, const char * v2){
    int ret;
    uint64_t a1;
    int64_t a2;
    uint64_t v2_len;

    v2_len = strlen (v2);

    a1 = ((a2 = (v1->__length - v2_len)) < 0 ? v1->__length : v2_len);
    ret = memcmp (v1->__data, v2, a1);
    if (!ret){
        ret = a2;
    }

    return ret;
}