#ifndef LINALG_H_
#define LINALG_H_
#include "syscalls.h"
#include "mem.h"

int pow(double a, int n);
double sin(double x);
double cos(double x);
double dot_product(double* a, double* b, int size);
double* cross_product(double* a, double* b);
double** matr_add(double** a, double** b, int ra, int ca, int rb, int cb);
double** matr_mult(double** a, double** b, int ra, int ca, int rb, int cb);

#endif /*LINALG_H_*/
