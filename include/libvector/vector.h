#ifndef __INCLUDE_LIBVECTOR_VECTOR_H__
#define __INCLUDE_LIBVECTOR_VECTOR_H__
// ////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Inner library
#include "struct/struct.h"
#include "error/error.h"

// ////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Outer library

// ////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Default library
#include <stdlib.h>
#include <memory.h>
#include <threads.h>

// 初期化する際のメモリ確保
#define __DEFAULT_VECTOR_SIZE__ 0x10

// Function to initialize structure.
// 1: uint64_t -> 変数のメモリサイズ
// 2: ポインタ系のメモリ解放のための情報 (NULLの場合は扱いを変数系とする)
// 3: ポインタ系のメモリコピーのための情報 (NULLの場合は扱いを変数系とする)
// 4: ポインタ系のメモリ比較のための情報 (NULLの場合は扱いを変数系とする)
// r: vector -> NULL=>Memory allocation failure
vector vector_init (uint64_t memory_size, void (*free_function) (void *v1), void (*copy_function) (void **v1, void *v2), int (*cmp_function) (void *v1, void *v2));

// 構造体に情報を挿入するための関数
// 1: vector -> 情報を保持する構造体
// 2: uint64_t -> 挿入する場所
// 3: vector -> 挿入する構造体
// r: vector_ret -> VR_NONE=>処理成功 / それ以外=>処理失敗
vector_ret vector_insert (vector v1, uint64_t point, vector v2);

// 末尾に情報をプッシュするための関数
// 1: vector -> 情報を保持する構造体
// 2: void* -> 情報の先頭ポインタ
// r: vector_ret -> VR_NONE=>処理成功 / それ以外=>処理失敗
vector_ret vector_push_back (vector v1, void *begin);

// 情報を取得するための関数
// 1: vector -> 情報を保持する構造体
// 2: uint64_t -> 取得位置
// r: void* -> NULL=>情報を取得することができませんでした / それ以外=>情報取得成功
void *vector_get (vector v1, uint64_t point);

// 情報を削除するための関数
// 1: vector -> 情報を保持する構造体
// 2: uint64_t -> 削除開始位置
// 3: uint64_t -> 削除終了位置
// r: void* -> NULL=>情報を取得することができませんでした / それ以外=>情報取得成功
vector_ret vector_erase (vector v1, uint64_t begin, uint64_t end);

// 情報を背の順で並び替える関数
// 1: vector -> 情報を保持する構造体
// r: vector_ret -> VR_NONE=>処理成功 / それ以外=>処理失敗
vector_ret vector_sort_asc (vector v1);

// 情報を背の順で並び替える関数
// 1: vector -> 情報を保持する構造体
// r: vector_ret -> VR_NONE=>処理成功 / それ以外=>処理失敗
vector_ret vector_sort_desc (vector v1);

// 情報を背の順で並び替える関数
// 1: vector -> 情報を保持する構造体
// r: vector_ret -> VR_NONE=>処理成功 / それ以外=>処理失敗
vector_ret vector_sort_asc (vector v1);

// 情報を背の順で並び替える関数
// 1: vector -> 情報を保持する構造体
// r: vector_ret -> VR_NONE=>処理成功 / それ以外=>処理失敗
vector_ret vector_sort_desc (vector v1);

// 構造体のサイズを取得するための関数
// 1: vector -> 情報を保持する構造体
// r: uint64_t -> 構造体の利用している長さを取得する
uint64_t vector_size (vector v1);

// 構造体の最大サイズを取得するための関数
// 1: vector -> 情報を保持する構造体
// r: uint64_t -> 構造体の利用している長さを取得する
uint64_t vector_max_size (vector v1);

// 構造体情報をリサイズする関数
// 1: vector -> 情報を保持する構造体
// 2: uint64_t -> リサイズしたいサイズ
// r: vector_ret -> VR_NONE=>処理成功 / それ以外=>処理失敗
vector_ret vector_resize (vector v1, uint64_t resize);


// 構造体情報のコピーする関数
// 1: vector -> コピー先
// 2: vector -> コピー元
// r: vector_ret -> VR_NONE=>処理成功 / それ以外=>処理失敗
vector_ret vector_copy (vector *v1, vector v2);

// 構造体情報を比較する関数
// 1: vector -> 比較先
// 2: vector -> 比較元
// r: vector_ret -> VR_NONE=>処理成功 / それ以外=>処理失敗
int vector_cmp (vector v1, vector v2);

// Function to clear structure.
// 1: vector -> Variable you want to clear.
void vector_free (vector v1);

// uint8_tの型を比較する際に利用するcmp関数
// 1: uint8_t* -> 比較元
// 2: uint8_t* -> 比較先
// r: int -> -1=>比較元のほうが軽い / 0=>等しい / 1=>比較先のほうが軽い
int vector_cmp_uint8_t (uint8_t *v1, uint8_t *v2);

// uint16_tの型を比較する際に利用するcmp関数
// 1: uint16_t* -> 比較元
// 2: uint16_t* -> 比較先
// r: int -> -1=>比較元のほうが軽い / 0=>等しい / 1=>比較先のほうが軽い
int vector_cmp_uint16_t (uint16_t *v1, uint16_t *v2);

// uint32_tの型を比較する際に利用するcmp関数
// 1: uint32_t* -> 比較元
// 2: uint32_t* -> 比較先
// r: int -> -1=>比較元のほうが軽い / 0=>等しい / 1=>比較先のほうが軽い
int vector_cmp_uint32_t (uint32_t *v1, uint32_t *v2);

// uint64_tの型を比較する際に利用するcmp関数
// 1: uint64_t* -> 比較元
// 2: uint64_t* -> 比較先
// r: int -> -1=>比較元のほうが軽い / 0=>等しい / 1=>比較先のほうが軽い
int vector_cmp_uint64_t (uint64_t *v1, uint64_t *v2);

// int8_tの型を比較する際に利用するcmp関数
// 1: int8_t* -> 比較元
// 2: int8_t* -> 比較先
// r: int -> -1=>比較元のほうが軽い / 0=>等しい / 1=>比較先のほうが軽い
int vector_cmp_int8_t (int8_t *v1, int8_t *v2);

// int16_tの型を比較する際に利用するcmp関数
// 1: int16_t* -> 比較元
// 2: int16_t* -> 比較先
// r: int -> -1=>比較元のほうが軽い / 0=>等しい / 1=>比較先のほうが軽い
int vector_cmp_int16_t (int16_t *v1, int16_t *v2);

// int32_tの型を比較する際に利用するcmp関数
// 1: int32_t* -> 比較元
// 2: int32_t* -> 比較先
// r: int -> -1=>比較元のほうが軽い / 0=>等しい / 1=>比較先のほうが軽い
int vector_cmp_int32_t (int32_t *v1, int32_t *v2);

// int64_tの型を比較する際に利用するcmp関数
// 1: int64_t* -> 比較元
// 2: int64_t* -> 比較先
// r: int -> -1=>比較元のほうが軽い / 0=>等しい / 1=>比較先のほうが軽い
int vector_cmp_int64_t (int64_t *v1, int64_t *v2);

// floatの型を比較する際に利用するcmp関数
// 1: float* -> 比較元
// 2: float* -> 比較先
// r: int -> -1=>比較元のほうが軽い / 0=>等しい / 1=>比較先のほうが軽い
int vector_cmp_float (float *v1, float *v2);

// doubleの型を比較する際に利用するcmp関数
// 1: double* -> 比較元
// 2: double* -> 比較先
// r: int -> -1=>比較元のほうが軽い / 0=>等しい / 1=>比較先のほうが軽い
int vector_cmp_double (double *v1, double *v2);

// ソートアルゴリズム
// 1: void** -> ソート前データのポインタ情報
// 2: void** -> ヒープ領域
// 3: uint64_t -> データの数
// 4: int (*cmp_function) (void *v1, void *v2) -> 比較関数ポインタ (NULL=>変数系の比較方式を利用)
void __vector_pointer_quick_sort_asc(void **v1, void **v2, uint64_t length, int(* cmp_function)(void *v1, void *v2));

// ソートアルゴリズム
// 1: void** -> ソート前データのポインタ情報
// 2: void** -> ヒープ領域
// 3: uint64_t -> データの数
// 4: int (*cmp_function) (void *v1, void *v2) -> 比較関数ポインタ (NULL=>変数系の比較方式を利用)
void __vector_pointer_quick_sort_desc (void **v1, void **v2, uint64_t length, int(* cmp_function)(void *v1, void *v2));

// ソートアルゴリズム
// 1: void* -> ソート前データのポインタ情報
// 2: void* -> ヒープ領域
// 3: uint64_t -> メモリサイズ
// 4: uint64_t -> データの数
void __vector_value_quick_sort_asc (void *v1, void *v2, uint64_t mem_size, uint64_t length, int(* cmp_function)(void *v1, void *v2));

// ソートアルゴリズム
// 1: void* -> ソート前データのポインタ情報
// 2: void* -> ヒープ領域
// 3: uint64_t -> メモリサイズ
// 4: uint64_t -> データの数
void __vector_value_quick_sort_desc (void *v1, void *v2, uint64_t mem_size, uint64_t length, int(* cmp_function)(void *v1, void *v2));

#endif // __INCLUDE_LIBVECTOR_VECTOR_H__
