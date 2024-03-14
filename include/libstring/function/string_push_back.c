#include "../string.h"

string_ret string_push_back(string v1, const char v2){
    string_ret ret = SR_NONE;

    if (v1->__size <= v1->__length){
        ret = __string_realloc (v1, v1->__size*2);
        if (ret){
            return ret;
        }
    }

    v1->__data[v1->__length++] = v2;
    v1->__data[v1->__length] = 0;
}
