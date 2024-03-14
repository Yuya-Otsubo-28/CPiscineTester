#include "../string.h"

uint64_t string_search_end(string v1, uint64_t begin, uint64_t end, const char * sp_begin, const char * sp_end){
    uint8_t flag = 0x0;
    uint64_t ret = 0xffffffff;
    uint64_t sp_len;


    if (sp_end == NULL){
        sp_end = sp_begin+strlen (sp_begin);
    }

    if (sp_end <= sp_begin){
        return ret;
    }

    sp_len = sp_end - sp_begin;

    if (end == -1){
        end = v1->__length;
    }

    if (begin < end && v1->__length < end){
        return ret;
    }

    for (const char *buf = v1->__data + end - sp_len, *point = sp_begin; buf >= v1->__data + begin + sp_len;){
        if (*buf == *point){
            while (1){
                if (point == sp_end - 1){
                    ret = buf - v1->__data - sp_len + 1;
                    flag = 1;
                    break;
                }else{
                    buf ++;
                    point ++;
                }
                if (*buf != *point){
                    break;
                }
            }
            if (flag){
                break;
            }else{
                buf -= point - sp_begin + 1;
                point = sp_begin;
            }
        }else{
            buf--;
        }
    }

    return ret;
}
