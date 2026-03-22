#ifndef LINALG_H_
#define LINALG_H_
#include "syscalls.h"
#include "mem.h"

#define PI 3.14159265358979323

typedef struct {
    float*  vector;
    int     size;
} Vector;

typedef struct {
    float** matrix;
    int32_t     row;
    int32_t     col;
} Matrix;

Vector* init_vector(int32_t l);
Matrix* init_matrix(int32_t r, int32_t c);
int32_t pow(float a, int32_t n);
float   sqrt(float x);
float   invsqrt(float x);
float   sin(float x);
float   cos(float x);
float   magnitude(Vector* v);
Vector* normalize(Vector* v);
float   dot_product(Vector* a, Vector* b);
Vector* cross_product(Vector* a, Vector* b);
Vector* add_sv(float a, Vector* b);
Matrix* add_sm(float a, Matrix* b);
Vector* add_vv(Vector* a, Vector* b);
Matrix* add_mm(Matrix* a, Matrix* b);
Vector* mult_sv(float a, Vector* b);
Matrix* mult_sm(float a, Matrix* b);
Matrix* mult_vm(Vector* a, Matrix* b);
Vector* mult_mv(Matrix* a, Vector* b);
Matrix* mult_mm(Matrix* a, Matrix* b);
void    fill_mat(Matrix* mat, uint32_t rows, uint32_t cols);
#endif /*LINALG_H_*/
