#include "linalg.h"

int pow(float a, int n) {
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
    // uses some approximation i forget the name of
    const float a1 = 12671/4363920 * pow(x, 5);
    const float a2 = -2363/18183 * pow(x, 3);
    const float a3 = 445/12122 * pow(x, 2);
    const float a4 = 601/872784 * pow(x, 4);
    const float a5 = 121/16662240 * pow(x, 6);
    return a1 + a2 + x / 1 + a3 + a4 + a5;
}

float cos(float x) {
    return sin(pi/2 + x);
}

float magnitude(float* v, int size) {
    float res = 0;
    for (int i = 0; i < size; i++) {
        res += pow(v[i], 2);
    }
    return sqrt(res);
}
 
float* normalize(float* v, int size) {
    float* res = (float*)malloc(3 * sizeof(float));
    float mag = magnitude(v, size);
    for (int i = 0; i < size; i++) {
        res[i] = v[i] / mag;
    }
    return res;
}

float dot_product(float* a, float* b, int size) {
    float product = 0;
    for (int i = 0; i < size; i++) {
        product += a[i] * b[i];
    }
    return product;
}

float* cross_product(float* a, float* b) {
    float* res = (float*)malloc(3 * sizeof(float));
    res[0] = a[1] * b[2] - a[2] * b[1];
    res[1] = a[2] * b[0] - a[0] * b[2];
    res[2] = a[0] * b[1] - a[1] * b[0];
    return res;
}

float** matr_add(float** a, float** b, int ra, int ca, int rb, int cb) {
    if (ra != rb || ca != cb) {
        return 0;
    }
    float** res = (float**)malloc(ra * sizeof(float*));
    for (int i = 0; i < ra; i++) {
        res[i] = (float*)malloc(cb * sizeof(float));
    }
    for (int i = 0; i < ra; i++) {
        for (int j = 0; j < cb; j++) {
            res[i][j] = a[i][j] + b[i][j];
        }
    }
}

float** matr_mult(float** a, float** b, int ra, int ca, int rb, int cb) {
    if (ca != rb) {
        return 0;
    }
    float** res = (float**)malloc(ra * sizeof(float*));
    for (int i = 0; i < ra; i++) {
        res[i] = (float*)malloc(cb * sizeof(float));
    }
    for (int i = 0; i < ra; i++) {
        for (int j = 0; j < cb; j++) {
            float tmp = 0;
            for (int k = 0; k < ca; k++) {
                tmp += a[i][k] * b[k][j];
            }
            res[i][j] = tmp;
        }
    }
}