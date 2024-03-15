#include "../osdep.h"
#include <sys/mman.h>

void * sc_alloc(size_t size) {
    void *buf = NULL;

    buf = mmap(NULL, size, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
    if (buf == MAP_FAILED) {
        buf = NULL;
    }

    return buf;
}

bool sc_free(void *buf, size_t size) {
    return munmap(buf, size) != -1;
}