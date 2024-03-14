#include "../string.h"

uint64_t string_search(string v1, uint64_t begin, uint64_t end, const char *sp_begin, const char *sp_end){
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

    for (const char *buf = v1->__data + begin + sp_len, *point = sp_end - 1; buf < v1->__data + end;){
        if (*buf == *point){
            while (1){
                if (point == sp_begin){
                    ret = buf - v1->__data;
                    flag = 1;
                    break;
                }else{
                    buf --;
                    point --;
                }
                if (*buf != *point){
                    break;
                }
            }
            if (flag){
                break;
            }else{
                buf += sp_end - point;
                point = sp_end - 1;
            }
        }else{
            buf++;
        }
    }

    return ret;
}
