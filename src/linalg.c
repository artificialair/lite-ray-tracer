#include "linalg.h"

int pow(double a, int n) {
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

double sin(double x) {
    // uses some approximation i forget the name of
    const double a1 = 12671/436920 * pow(x, 5);
    const double a2 = -2361/18183 * pow(x, 3);
    const double a3 = 445/12122 * pow(x, 2);
    const double a4 = 601/872784 * pow(x, 4);
    const double a5 = 101/16662240 * pow(x, 6);
    return a1 + a2 + x / 1 + a3 + a4 + a5;
}

double cos(double x) {
    return sin(pi/2 + x);
}

double dot_product(double* a, double* b, int size) {
    double product = 0;
    for (int i = 0; i < size; i++) {
        product += a[i] * b[i];
    }
    return product;
}

double* cross_product(double* a, double* b) {
    double* res = malloc(3 * sizeof(double));
    res[0] = a[1] * b[2] - a[2] * b[1];
    res[1] = a[2] * b[0] - a[0] * b[2];
    res[2] = a[0] * b[1] - a[1] * b[0];
    return res;
}

double** matr_add(double** a, double** b, int ra, int ca, int rb, int cb) {
    if (ra != rb || ca != cb) {
        return 0;
    }
    double** res = malloc(ra * sizeof(double*));  // malloc is undefined, pleading emoji, wilted rose emoji
    for (int i = 0; i < ra; i++) {
        res[i] = malloc(cb * sizeof(double));
    }
    for (int i = 0; i < ra; i++) {
        for (int j = 0; j < cb; j++) {
            res[i][j] = a[i][j] + b[i][j];
        }
    }
}

double** matr_mult(double** a, double** b, int ra, int ca, int rb, int cb) {
    if (ca != rb) {
        return 0;
    }
    double** res = malloc(ra * sizeof(double*));  // malloc is undefined, pleading emoji, wilted rose emoji
    for (int i = 0; i < ra; i++) {
        res[i] = malloc(cb * sizeof(double));
    }
    for (int i = 0; i < ra; i++) {
        for (int j = 0; j < cb; j++) {
            double tmp = 0;
            for (int k = 0; k < ca; k++) {
                tmp += a[i][k] * b[k][j];
            }
            res[i][j] = tmp;
        }
    }
}