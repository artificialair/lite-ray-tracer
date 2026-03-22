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
    int     row;
    int     col;
} Matrix;

Vector* init_vector(int l);
Matrix* init_matrix(int r, int c);
int pow(float a, int n);
float sqrt(float x);
float invsqrt(float x);
float sin(float x);
float cos(float x);
float magnitude(Vector* v);
Vector* normalize(Vector* v);
float dot_product(Vector* a, Vector* b);
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
#endif /*LINALG_H_*/
