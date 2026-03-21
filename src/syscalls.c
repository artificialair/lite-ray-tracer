#include "types.h"
#include "syscalls.h"

/*
extern void sys_write(uint32_t fd, const char* str, size_t len);
extern void sys_exit(uint32_t status);
extern void* sys_mmap(void addr[length], size_t length, int32_t prot, int32_t flags,
                  uint32_t fd, off_t offset);
extern uint32_t sys_munmap(void addr[length], size_t length);
*/


void print(const char* str) {
    size_t len = strlen(str);
    sys_write(STDOUT_FILENO, str, len);
}

void* malloc(size_t size) {
    void* malloc_world = sys_mmap(0, size, 3, 32, -1, 0);
    return malloc_world;
}
