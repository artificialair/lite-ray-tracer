#ifndef SYSCALLS_H_
#define SYSCALLS_H_
#include "types.h"
#include "std.h"

extern void sys_write(uint32_t fd, const char* str, size_t len);
extern void sys_exit(uint32_t status);
extern void* sys_mmap(void* addr, size_t length, int32_t prot, int32_t flags,
                  uint32_t fd, off_t offset);
extern uint32_t sys_munmap(void* addr, size_t length);

#define exit(status) sys_exit(status)
#define mmap(addr, length, prot, flags, fd, offset) sys_mmap(addr, length, prot, flags, fd, offset)

void print(const char* str);
void* malloc(size_t size);

#endif /*SYSCALLS_H_*/
