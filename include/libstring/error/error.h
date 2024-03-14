#ifndef __INCLUDE_LIBSTRING_ERROR_ERROR_H__
#define __INCLUDE_LIBSTRING_ERROR_ERROR_H__

typedef enum __STRING_RET{
    SR_NONE = 0,           // No error occurred.
    SRE_ALLOCATE_MEMORY,   // Memory allocation failed.
    SRE_NOPOSITION,        // When inserting, the specified position is empty.

}string_ret;

// Function to get error code message.
// 1: STRING_RET -> Error message code.
// r: const char* -> Error message.
const char *string_ret_msg (string_ret v1);

#endif // __INCLUDE_LIBSTRING_ERROR_ERROR_H__
