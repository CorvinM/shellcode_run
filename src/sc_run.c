#include <stdio.h>
// #include <sys/mman.h>

#include "osdep.h"

size_t load_shellcode(void **sc_buf_ref, const char *path) {
    FILE *sc_file = NULL;
    size_t size = 0;
    void *sc_buf = NULL;

    sc_file = fopen(path, "rb");
    if (sc_file == NULL) {
        perror("[error] fopen");
        goto err;
    }

    if (fseek(sc_file, 0, SEEK_END) == -1) {
        perror("[error] fseek");
        goto err_fclose;
    }
    size = ftell(sc_file);
    if (fseek(sc_file, 0, SEEK_SET) == -1) {
        perror("[error] fseek");
        goto err_fclose;
    }

    sc_buf = sc_alloc(size);
    if (sc_buf == NULL) {
        perror("[error] sc_alloc");
        goto err_fclose;
    }

    if (fread(sc_buf, 1, size, sc_file) != size) {
        perror("[error] fread");
        goto err_munmap;
    }

    // we dont need the file anymore
    if (fclose(sc_file) == EOF) {
        perror("[error] fclose");
    }

    // success
    *sc_buf_ref = sc_buf;
    return size;

    // error
err_munmap:
    if (!sc_free(sc_buf, size)) {
        perror("[error] munmap");
    }
err_fclose:
    if (fclose(sc_file) == EOF) {
        perror("[error] fclose");
    }
err:
    return 0;
}

int main(int argc, char *argv[]) {
    void *sc_buf = NULL;
    size_t sc_buf_size = 0;
    int rv = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s shellcode.bin\n", argv[0]);
        goto err;
    }

    sc_buf_size = load_shellcode(&sc_buf, argv[1]);
    if (sc_buf_size == 0 || sc_buf == NULL) {
        fprintf(stderr, "error loading shellcode\n");
        goto err;
    }

    // run the shellcode
    rv = ((int (*)())sc_buf)();

    // cleanup the shellcode (if it actually returns back to us)
    if (!sc_free(sc_buf, sc_buf_size)) {
        perror("[error] munmap");
        goto err;
    }

    // success
    return rv;

    // error
err:
    return 1;
}