#include "../string.h"

string_ret string_resize(string v1, uint64_t resize){
    return __string_realloc (v1, resize);
}
