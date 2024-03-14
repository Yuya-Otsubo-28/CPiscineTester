#include "../vector.h"

void __vector_value_quick_sort_desc(void *v1, void *v2, uint64_t mem_size, uint64_t length, int(* cmp_function)(void *v1, void *v2)){
    if (length < 2) {
        return; // 配列の要素が1以下の場合は何もしない
    }

    void *a1 = v1;
    uint64_t p_begin = 0;
    uint64_t p_end = length - 1;
    int res;

    void **b1, **b2;
    // thrd_t th1, th2;

    if (cmp_function) {
        for (uint64_t j = 1; j < length; j++) {
            res = cmp_function (a1, v1+mem_size*j);
            if (res >= 0) {
                memcpy (v2+mem_size*p_end--, v1+mem_size*j, mem_size);
            } else {
                memcpy (v2+mem_size*p_begin++, v1+mem_size*j, mem_size);
            }
        }
    } else {
        for (uint64_t j = 1; j < length; j++) {
            res = memcmp(a1, v1+mem_size*j, mem_size);
            if (res >= 0) {
                memcpy (v2+mem_size*p_end--, v1+mem_size*j, mem_size);
            } else {
                memcpy (v2+mem_size*p_begin++, v1+mem_size*j, mem_size);
            }
        }
    }

    memcpy (v2+mem_size*p_begin, a1, mem_size);

    // printf ("begin: %d\n", p_begin);
    // printf ("end: %d\n", p_end);

    // for (uint64_t j = 0; j < length; j ++){
    //     printf ("%d: %d\n", j, *(int*)*v2+mem_size*j);
    // }
    
    if (length != 2) {
        // // スレッドのデータ
        // struct {
        //     void **v1;
        //     void **v2;
        //     uint64_t length;
        //     int(* cmp_function)(void *v1, void *v2);
        // } data1 = { v2, v1, p_begin++, cmp_function };

        // struct {
        //     void **v1;
        //     void **v2;
        //     uint64_t length;
        //     int(* cmp_function)(void *v1, void *v2);
        // } data2 = { v2+p_begin, v1+p_begin, length-p_begin, cmp_function };

        // // スレッド1の作成
        // if (thrd_create(&th1, thread_sort, &data1) != thrd_success) {
        //     return;
        // }

        // // スレッド2の作成
        // if (thrd_create(&th2, thread_sort, &data2) != thrd_success) {
        //     return;
        // }

        // // 同期処理
        // if (thrd_join(th1, &res) != thrd_success) {
        //     return;
        // }
        // if (thrd_join(th2, &res) != thrd_success) {
        //     return;
        // }

        __vector_value_quick_sort_desc (v2, v1, mem_size, p_begin++, cmp_function);
        __vector_value_quick_sort_desc (v2+mem_size*p_begin, v1+mem_size*p_begin, mem_size, length-p_begin, cmp_function);
    }

    memcpy (v1, v2, length*mem_size);
}
