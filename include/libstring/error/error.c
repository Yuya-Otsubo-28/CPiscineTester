#include "error.h"

// ////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Messages

static const char *emsg_none_ = "No errors occurred.";
static const char *emsg_allocate_memory_ = "Memory allocation failed.";
static const char *emsg_noposition_ = "When inserting, the specified position is empty.";

static const char *emsg_unexpected_ = "An unexpected error has occurred.";

// ////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Function
const char *string_ret_msg (string_ret v1){
    const char *msg;

    switch (v1){
        case (SR_NONE):
            msg = emsg_none_;

            break;
        
        case (SRE_ALLOCATE_MEMORY):
            msg = emsg_allocate_memory_;

            break;
        
        case (SRE_NOPOSITION):
            msg = emsg_noposition_;

            break;
        
        default:
            msg = emsg_unexpected_;
    }

    return msg;
}
