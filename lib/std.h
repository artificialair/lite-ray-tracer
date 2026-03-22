#ifndef STD_H_
#define STD_H_
#include "syscalls.h"

#define STDOUT_FILENO 1
#define NULL 0
#define MALLOC_SIZE 1024

int strlen(const char * str);
int atoi(const char * str);
const char * itoa(int32_t n);
void print_test_result(const char* title, bool result);
bool streq(const char* s1, const char* s2);
void strncpy(const char* s, char* dest, size_t size);
const char* strcat(const char* s1, const char* s2);

#endif /*STD_H_*/
