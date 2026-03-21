#ifndef LINALG_H_
#define LINALG_H_
#include "syscalls.h"

const float pi = 3.14159265359;

int pow(float a, int n);
float sqrt(float x);
float invsqrt(float x);
float sin(float x);
float cos(float x);
float magnitude(float* v, int size);
float normalize(float* v, int size);
float dot_product(float* a, float* b, int size);
float* cross_product(float* a, float* b);
float** matr_add(float** a, float** b, int ra, int ca, int rb, int cb);
float** matr_mult(float** a, float** b, int ra, int ca, int rb, int cb);

#endif /*LINALG_H_*/
