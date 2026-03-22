#ifndef SYSCALLS_H_
#define SYSCALLS_H_
#include "types.h"
#include "std.h"

#define SYS_READ   0
#define SYS_WRITE  1
#define SYS_OPEN   2
#define SYS_MUNMAP 11
#define SYS_DUP    32
#define SYS_DUP2   33
#define SYS_FORK   57
#define SYS_EXIT   60


extern void* syscall_wrapper(void* arg1, void* arg2, void* arg3, uint32_t syscall_num);
extern void* sys_mmap(void* addr, size_t length, int32_t prot, int32_t flags,
                  uint32_t fd, off_t offset);

#define exit(status) sys_exit(status)
#define mmap(addr, length, prot, flags, fd, offset) sys_mmap(addr, length, prot, flags, fd, offset)

void print(const char* str);
void* malloc(size_t size);
void munmap(void* addr, size_t len);

#endif /*SYSCALLS_H_*/
