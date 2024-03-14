#ifndef __INCLUDE_LIBSTRING_STRING_H__
#define __INCLUDE_LIBSTRING_STRING_H__
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
#include <string.h>

#define __STRING_DEFAULT_SIZE 0x10

// Function to initialize structure.
// 1: string -> Variable you want to initialize.
// r: string -> NULL=>Memory allocation failure
string string_init (void);

// Function to clear structure.
// 1: string -> Variable you want to clear.
void string_free (string v1);

// 文字列を代入するための関数
// 1: string -> 情報を保持する構造体
// 2: const char* -> 代入したい文字列
// r: string_ret -> SR_NONE=>処理成功
string_ret string_set (string v1, const char *v2);

// 文字列を取得するための関数
// 1: string -> 情報を保持する構造体
// r: const char* -> 文字列
const char *string_c_str (string v1);

// 構造体が確保しているメモリサイズを取得するための関数
// 1: string -> 情報を保持する構造体
// r: uint64_t -> 確保しているメモリサイズ
uint64_t string_size (string v1);

// 文字列の長さを取得するための関数
// 1: string -> 情報を保持する構造体
// r: uint64_t -> 文字列の長さ
uint64_t string_length (string v1);

// 構造体のメモリを再確保するための関数
// 1: string -> 情報を保持する構造体
// 2: uint64_t -> リサイズしたいサイズ
// r: string_ret -> SR_NONE=>処理成功
string_ret string_resize (string v1, uint64_t resize);


// 文字を末尾に追加する関数
// 1: string -> 情報を保持する構造体
// 2: const char -> 末尾に追加したい文字
// r: string_ret -> SR_NONE=>処理成功
string_ret string_push_back (string v1, const char v2);

// 文字列を末尾に追加する関数
// 1: string -> 情報を保持する構造体
// 2: const char* -> 末尾に追加したい文字列
// r: string_ret -> SR_NONE=>処理成功
string_ret string_append (string v1, const char *v2);

// 文字列を挿入する関数
// 1: string -> 情報を保持する構造体
// 2: uint64_t -> 文字列を挿入するポイント
// 3: const char* -> 挿入したい文字列
// r: string_ret -> SR_NONE=>処理成功
string_ret string_insert (string v1, uint64_t v2, const char *v3);

// 文字列を削除する関数
// 1: string -> 情報を保持する構造体
// 2: uint64_t -> 削除開始位置
// 3: uint64_t -> 削除終了位置 (-1の場合は末尾まで削除という意味)
// r: string_ret -> SR_NONE=>処理成功
string_ret string_erase (string v1, uint64_t begin, uint64_t end);

// 構造体と構造体の文字列の情報を比較する
// 1: string -> 情報を保持する構造体
// 2: string -> 情報を保持する構造体
// r: int -> 0=>等しい / 0未満=>一つめの引数が軽い / 0超過=>二つめの引数が軽い
int string_cmp (string v1, string v2);

// 構造体と文字列の情報を比較する
// 1: string -> 情報を保持する構造体
// 2: const char* -> 文字列
// r: int -> 0=>等しい / 0未満=>一つめの引数が軽い / 0超過=>二つめの引数が軽い
int string_cmp_chars (string v1, const char *v2);

// 構造体情報をクリアする
// 1: string -> 情報を保持する構造体
void string_clear (string v1);

// 構造体をコピーする
// 1: string -> コピー先
// 2: string -> コピー元
// r: string_ret -> SR_NONE=>処理成功
string_ret string_copy (string *v1, string v2);

// 文字を検索する (先頭から)
// 1: string -> 情報を保持する構造体
// 2: uint64_t -> 検索開始位置
// 3: uint64_t -> 検索終了位置 (-1の場合は末尾まで検索という意味)
// 4: const char -> 検索したい文字
// r: uint64_t -> 0xffffffff=>検索失敗 / それ以外=>その数値の場所に文字が存在する
uint64_t string_find (string v1, uint64_t begin, uint64_t end, const char v2);

// 文字を検索する (末尾から)
// 1: string -> 情報を保持する構造体
// 2: uint64_t -> 検索開始位置
// 3: uint64_t -> 検索終了位置 (-1の場合は末尾まで検索という意味)
// 4: const char -> 検索したい文字
// r: uint64_t -> 0xffffffff=>検索失敗 / それ以外=>その数値の場所に文字が存在する
uint64_t string_find_end (string v1, uint64_t begin, uint64_t end, const char v2);

// 文字列を探索する (先頭から)
// 1: string -> 情報を保持する構造体
// 2: uint64_t -> 検索開始位置
// 3: uint64_t -> 検索終了位置
// 4: const char* -> 検索したい文字列の先頭アドレス
// 5: const char* -> 検索したい文字列の末尾アドレス (NULLの場合は先頭アドレスから次のNULL値まで検索する)
// r: uint64_t -> 0xffffffff=>検索失敗 / それ以外=>その数値の場所に文字列の先頭が存在する
uint64_t string_search (string v1, uint64_t begin, uint64_t end, const char *sp_begin, const char *sp_end);

// 文字列を探索する (末尾から)
// 1: string -> 情報を保持する構造体
// 2: uint64_t -> 検索開始位置
// 3: uint64_t -> 検索終了位置
// 4: const char* -> 検索したい文字列の先頭アドレス
// 5: const char* -> 検索したい文字列の末尾アドレス (NULLの場合は先頭アドレスから次のNULL値まで検索する)
// r: uint64_t -> 0xffffffff=>検索失敗 / それ以外=>その数値の場所に文字列の先頭が存在する
uint64_t string_search_end (string v1, uint64_t begin, uint64_t end, const char *sp_begin, const char *sp_end);


// string構造体のメモリを確保する
// 1: string -> 情報を保持する構造体
// 2: uint64_t -> 変更したいサイズ
string_ret __string_realloc (string v1, uint64_t size);

#endif // __INCLUDE_LIBSTRING_STRING_H__
