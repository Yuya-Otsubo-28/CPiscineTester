#include "string.h"

string string_init (void){
    string v1;
    string_ret ret;
    v1 = NULL;
    v1 = (string)malloc (sizeof (struct __string));
    if (v1 == NULL){
        return v1;
    }

    // ////////////////////////////////////////////////////////////////////////////////////////////
    // 
    // If you need to allocate internal memory, please substitute the source code
    v1->__length = 0;
    v1->__data = NULL;

    // メモリを確保する
    ret = __string_realloc (v1, __STRING_DEFAULT_SIZE);
    if (ret){
        // 初期化中に何かしらの問題が発生しました
        string_free (v1);
    }

    // ////////////////////////////////////////////////////////////////////////////////////////////
    return v1;
}

void string_free (string v1){
    // ////////////////////////////////////////////////////////////////////////////////////////////
    // 
    // If you need to release internal memory, please assign the source code
    if (v1){
        v1->__size = 0;
        v1->__length = 0;
        free (v1->__data);

        free (v1);
    }
}
