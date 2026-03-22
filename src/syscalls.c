#include "syscalls.h"

/*
extern void sys_write(uint32_t fd, const char* str, size_t len);
extern void sys_exit(uint32_t status);
extern void* sys_mmap(void addr[length], size_t length, int32_t prot, int32_t flags,
                  uint32_t fd, off_t offset);
extern uint32_t sys_munmap(void addr[length], size_t length);
*/
#pragma GCC diagnostic error "-Wint-to-pointer-cast"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"
void write(uint32_t fd, const char* buf, size_t count) {
    syscall_wrapper((void*) fd, (void*) buf, (void*) count, SYS_WRITE);
}

void read(uint32_t fd, char* buf, size_t count) {
    syscall_wrapper((void*) fd, (void*) buf, (void*) count, SYS_READ);
}

uint32_t open(const char* filename, int32_t flags, int32_t mode) {
    uint32_t* ptr = (uint32_t *)syscall_wrapper((void*) filename, (void *) flags, (void *) mode, SYS_OPEN);
    return *ptr;
}

void munmap(void* addr, size_t len) {
    syscall_wrapper((void*) addr, (void*) len, NULL, SYS_MUNMAP);
}

void print(const char* str) {
    size_t len = strlen(str);
    write(STDOUT_FILENO, str, len);
}

void exit(uint32_t code) {
    syscall_wrapper((void*) code, NULL, NULL, SYS_EXIT);
}

#pragma GCC diagnostic pop
