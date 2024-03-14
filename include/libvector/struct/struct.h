#ifndef __INCLUDE_LIBVECTOR_STRUCT_STRUCT_H__
#define __INCLUDE_LIBVECTOR_STRUCT_STRUCT_H__
// ////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Inner library

// ////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Outer library

// ////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Default library
#include <stdint.h>

struct __vector{
    // 構造体が確保しているサイズ
    uint64_t __size;
    // 構造体が利用しているサイズ
    uint64_t __length;
    // 構造体に保持するデータのメモリサイズ
    uint64_t __memory_size;
    // 構造体のデータ(ポインタ系の情報)
    void **__data0;
    // 構造体のデータ(変数系の情報)
    void *__data1;
    
    // ポインタ系のメモリ解放のための情報 (NULLの場合は扱いを変数系とする)
    void (*__free_function) (void *v1);
    // ポインタ系のメモリコピーのための情報 (NULLの場合は扱いを変数系とする)
    void (*__copy_function) (void **v1, void *v2);
    // ポインタ系のメモリ比較のための情報 (NULLの場合は扱いを変数系とする)
    int (*__cmp_function) (void *v1, void *v2);

};

// ////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Structure name to be used in the future
typedef struct __vector* vector;

#endif // __INCLUDE_LIBVECTOR_STRUCT_STRUCT_H__
