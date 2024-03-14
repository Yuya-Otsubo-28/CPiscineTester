#include "../vector.h"

// static void thread_sort(void *arg);

void __vector_pointer_quick_sort_asc(void **v1, void **v2, uint64_t length, int(* cmp_function)(void *v1, void *v2)){
    if (length < 2) {
        return; // 配列の要素が1以下の場合は何もしない
    }

    void *a1 = *v1;
    uint64_t p_begin = 0;
    uint64_t p_end = length - 1;
    int res;
    // thrd_t th1, th2;

    if (cmp_function) {
        for (uint64_t j = 1; j < length; j++) {
            res = cmp_function(a1, v1[j]);
            if (res <= 0) {
                v2[p_end--] = v1[j];
            } else {
                v2[p_begin++] = v1[j];
            }
        }
    } else {
        for (uint64_t j = 1; j < length; j++) {
            res = memcmp(a1, v1[j], sizeof(a1));
            if (res <= 0) {
                v2[p_end--] = v1[j];
            } else {
                v2[p_begin++] = v1[j];
            }
        }
    }

    v2[p_begin] = a1;
    
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

        __vector_pointer_quick_sort_asc (v2, v1, p_begin++, cmp_function);
        __vector_pointer_quick_sort_asc (v2+p_begin, v1+p_begin, length-p_begin, cmp_function);
    }

    for (uint64_t j = 0; j < length; j ++){
        v1[j] = v2[j];
    }
}

// void thread_sort(void *arg) {
//     struct {
//         void **v1;
//         void **v2;
//         uint64_t length;
//         int(* cmp_function)(void *v1, void *v2);
//     } *data = (struct {void **v1; void **v2; uint64_t length; int(* cmp_function)(void *v1, void *v2); } *)arg;

//     __vector_pointer_quick_sort_asc(data->v1, data->v2, data->length, data->cmp_function);
// }
