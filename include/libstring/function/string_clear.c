#include "../string.h"

void string_clear(string v1){
    v1->__length = 0;
    v1->__data[v1->__length] = 0;
}
