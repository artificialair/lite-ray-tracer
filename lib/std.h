#ifndef STD_H_
#define STD_H_
#include "syscalls.h"

#define STDOUT_FILENO 1
#define NULL 0
#define MALLOC_SIZE 1024

int strlen(const char * str);
int atoi(const char * str);
const char * itoa(int32_t n);
void print_test_result(bool result);

#endif /*STD_H_*/
