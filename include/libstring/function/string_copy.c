#include "../string.h"

string_ret string_copy(string *v1, string v2){
    string_ret ret = SR_NONE;
    
    if (!(*v1)){
        *v1 = string_init ();
    }

    if ((*v1)->__size < v2->__size){
        ret = __string_realloc (*v1, v2->__size);
        if (ret){
            return ret;
        }
    }
    
    (*v1)->__length = v2->__length;
    memcpy ((*v1)->__data, v2->__data, v2->__length);
    (*v1)->__data[v2->__length] = 0;
}
