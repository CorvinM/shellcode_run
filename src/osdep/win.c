#include "../osdep.h"

#include <windows.h>
#include <memoryapi.h>

void * sc_alloc(size_t size) {
    void *buf = NULL;

    buf = VirtualAlloc(NULL, size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

    return buf;
}

bool sc_free(void *buf, size_t size) {
    return VirtualFree(buf, 0, MEM_RELEASE) != 0;
}