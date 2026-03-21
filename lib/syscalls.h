#ifndef SYSCALLS_H_
#define SYSCALLS_H_
#include "types.h"

extern void sys_write(uint32_t fd, const char* str, size_t len);
extern void sys_exit(uint32_t status);
extern void* sys_mmap(void addr[length], size_t length, int32_t prot, int32_t flags,
                  uint32_t fd, off_t offset);
extern uint32_t sys_munmap(void addr[length], size_t length);

#endif /*SYSCALLS_H_*/
