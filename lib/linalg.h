#ifndef LINALG_H_
#define LINALG_H_
#include "syscalls.h"
#include "mem.h"

#define PI 3.14159265358979323

typedef struct {
    float*  vector;
    int32_t     elements;
} Vector;

typedef struct {
    float** matrix;
    int32_t     row;
    int32_t     col;
} Matrix;

Vector* init_vector(int32_t l);
Matrix* init_matrix(int32_t r, int32_t c);
int32_t pow(float a, int32_t n);
float sqrt(float x);
float invsqrt(float x);
float sin(float x);
float cos(float x);
float magnitude(Vector* v);
Vector* normalize(Vector* v);
float dot_product(Vector* a, Vector* b);
Vector* cross_product(Vector* a, Vector* b);
Matrix* matr_add(Matrix* a, Matrix* b);
Matrix* matr_mult(Matrix* a, Matrix* b);
#endif /*LINALG_H_*/
