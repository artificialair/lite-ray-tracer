#ifndef TESTS_H_
#define TESTS_H_

#include "types.h"
#include "std.h"
#include "syscalls.h"
#include "linalg.h"
#include "mem.h"

volatile bool malloc_test();
volatile bool str_tests();
void run_tests();

#endif /*TESTS_H_*/
