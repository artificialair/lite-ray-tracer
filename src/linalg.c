#include "linalg.h"

Vector* init_vector(int32_t l) {
    float* res_vector = (float*)malloc(l * sizeof(float*));
    Vector* vec   = malloc(sizeof(Vector));
    vec->vector   = res_vector;
    vec->elements = l;
    return vec;
}

Matrix* init_matrix(int32_t r, int32_t c) {
    float** res_matrix = (float**)malloc(r * sizeof(float*));
    for (int32_t i = 0; i < r; i++) {
        res_matrix[i] = (float*)malloc(c * sizeof(float));
    }
    Matrix* res = malloc(sizeof(Matrix));
    res->matrix = res_matrix;
    res->row    = r;
    res->col    = c;
    return res;
}

int32_t pow(float a, int32_t n) {
  if (n == 0) {
    return 1;
  }
  if (n == 1) {
    return a;
  }
  if (n % 2 == 0) {
    return pow(a * a, n / 2);
  } else {
    return a * pow(a, n - 1);
  }
}

float sqrt(float x) {
    return 1 / invsqrt(x);
}

float invsqrt(float x) {
    // thank you quake for this masterpiece
    // i might use a better approx later that works with doubles (if i care)
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = x * 0.5F;
	y  = x;
	i  = * ( long * ) &y;                       
	i  = 0x5f3759df - ( i >> 1 );    
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );

	return y;
}

float sin(float x) {
    // 6th order Pade Approximation for sin
    const float a1 = 12671/4363920 * pow(x, 5);
    const float a2 = -2363/18183 * pow(x, 3);
    const float a3 = 445/12122 * pow(x, 2);
    const float a4 = 601/872784 * pow(x, 4);
    const float a5 = 121/16662240 * pow(x, 6);
    return a1 + a2 + x / 1 + a3 + a4 + a5;
}

float cos(float x) {
    return sin(PI/2 + x);
}

float magnitude(Vector* v) {
    float res = 0;
    for (int32_t i = 0; i < v->elements; i++) {
        res += pow(v->vector[i], 2);
    }
    return sqrt(res);
}
 
Vector* normalize(Vector* v) {
    Vector* res = init_vector(3);
    float mag = magnitude(v);
    for (int32_t i = 0; i < v->elements; i++) {
        res->vector[i] = v->vector[i] / mag;
    }
    return res;
}

float dot_product(Vector* a, Vector* b) {
    if (a->elements != b->elements) {
        return 0;  // todo: error handle
    }
    float product = 0;
    for (int32_t i = 0; i < a->elements; i++) {
        product += a->vector[i] * b->vector[i];
    }
    return product;
}

Vector* cross_product(Vector* a, Vector* b) {
    Vector* res = init_vector(3);
    res->vector[0] = a->vector[1] * b->vector[2] - a->vector[2] * b->vector[1];
    res->vector[1] = a->vector[2] * b->vector[0] - a->vector[0] * b->vector[2];
    res->vector[2] = a->vector[0] * b->vector[1] - a->vector[1] * b->vector[0];
    return res;
}

Matrix* matr_add(Matrix* a, Matrix* b) {
    if (a->row != b->row || a->col != b->col) {
        return 0;
    }
    Matrix* res = init_matrix(a->row, a->col);
    for (int32_t i = 0; i < a->row; i++) {
        for (int32_t j = 0; j < a->col; j++) {
            res->matrix[i][j] = a->matrix[i][j] + b->matrix[i][j];
        }
    }
    return res;
}

Matrix* matr_mult(Matrix* a, Matrix* b) {
    if (a->col != b->row) {
        return 0;  // todo: error handle
    }
    Matrix* res = init_matrix(a->row, b->col);
    for (int32_t i = 0; i < a->row; i++) {
        for (int32_t j = 0; j < b->col; j++) {
            float tmp = 0;
            for (int32_t k = 0; k < a->col; k++) {
                tmp += a->matrix[i][k] * b->matrix[k][j];
            }
            res->matrix[i][j] = tmp;
        }
    }
}
