#ifndef SHELLCODE_RUN_OSDEP_H
#define SHELLCODE_RUN_OSDEP_H

#include <stddef.h>
#include <stdbool.h>

/*
Allocates RWX buffer of at least size.
size    [in] minimum size of buffer to allocate.
return  [out] start address of the allocated region on success, or NULL on failure.
*/
void * sc_alloc(size_t size);

/*
Deallocates RWX buffer previously allocated by sc_alloc.
buf     [in] start address of buffer.
size    [in] size of buffer.
return  [out] true on success, false on failure.
*/
bool sc_free(void *buf, size_t size);

#endif