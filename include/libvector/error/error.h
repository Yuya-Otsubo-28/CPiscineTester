#ifndef __INCLUDE_LIBVECTOR_ERROR_ERROR_H__
#define __INCLUDE_LIBVECTOR_ERROR_ERROR_H__

typedef enum __VECTOR_RET{
    VR_NONE = 0,            // No error occurred
    VRE_ALLOCATE_MEMORY,    // Memory allocation failed
    VRE_NOPOSITION,         // When inserting, the specified position is empty.

}vector_ret;

// Function to get error code message.
// 1: VECTOR_RET -> Error message code.
// r: const char* -> Error message.
const char *vector_ret_msg (vector_ret v1);

#endif // __INCLUDE_LIBVECTOR_ERROR_ERROR_H__
