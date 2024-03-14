#include "../string.h"

string_ret string_append(string v1, const char *v2){
    string_ret ret = SR_NONE;
    uint64_t len, sum_len;
    uint64_t extension_size;
    
    len = strlen (v2);
    sum_len = len + v1->__length;

    extension_size = v1->__size;
    if (v1->__size - 1 < sum_len){
        while ((extension_size*=2) < sum_len);
        ret = __string_realloc (v1, extension_size);
        if (ret){
            return ret;
        }
    }

    memcpy (v1->__data+v1->__length, v2, len);
    v1->__length = sum_len;
    v1->__data[v1->__length] = 0;

    return ret;
}
