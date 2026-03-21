#ifndef STD_H_
#define STD_H_
#include "syscalls.h"

#define STDOUT_FILENO 1

int strlen(const char * str);
int atoi(char * str);
char * itoa(int n);

#endif /*STD_H_*/
