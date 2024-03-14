#include "../string.h"

const char *string_c_str(string v1){
    if (!v1){
        return "";
    }
    return v1->__data;
}