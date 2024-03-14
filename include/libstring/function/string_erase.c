#include "../string.h"

string_ret string_erase(string v1, uint64_t begin, uint64_t end){
    string_ret ret = SR_NONE;
    uint64_t extension_size;
    
    if (end == -1){
        end = v1->__length;
    }

    if (begin < end && v1->__length < end){
        ret = SRE_NOPOSITION;
        return ret;
    }

    memcpy (v1->__data+begin, v1->__data+end, v1->__length-end);
    
    v1->__length = v1->__length-(end-begin);
    v1->__data[v1->__length] = 0;
    
    return ret;
}