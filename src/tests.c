#include "tests.h"

bool __attribute__((optimize("O0"))) malloc_test() {
    void* ptr = malloc(MALLOC_SIZE);
    if (ptr == NULL) return true;

    char* arr = (char *)ptr;
    for (int i = 0; i < MALLOC_SIZE; i++) {
        arr[i] = 'A';
        char dummy = arr[i];
    }
    char str[] = {arr[MALLOC_SIZE-1], '\n', '\0'};
    uint32_t num_rows = 5;
    uint32_t num_cols = 5;
    int* array2d = (int*)malloc(sizeof(int)*num_rows*num_cols);
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            array2d[i*num_rows + j] = i*j;
        }
    }/*
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            print(itoa(array2d[i*num_rows + j]));
        }
    }*/
    
    int* dummy = (int *)malloc(1024);
    dummy[0] = 1;
    return false;
}

bool __attribute__((optimize("O0"))) str_tests() {
    const char* str = "hello, world";
    const char* str2 = "A";
    const char* int_str = "123";
    uint32_t num = 123;

    uint32_t len1 = strlen(str);
    if (len1 != 12) return true;

    uint32_t len2 = strlen(str2);
    if (len2 != 1)  return true;

    uint32_t val = atoi(int_str);
    if (val != num) return true;

    const char* num_str = itoa(num);
    if (!streq(num_str, int_str)) return true;

    char* dest = (char *)malloc(len1+1);
    
    strncpy(str, dest, len1);
    const char* c_dest = dest;
    if (!streq(c_dest, str)) return true;

    const char* concat = "hello, worldA";
    const char* concat_test = strcat(str, str2);
    if (!streq(concat, concat_test)) return true;


    return false;
}

bool linalg_tests() {
    Matrix* a = init_matrix(2, 3);
    Matrix* b = init_matrix(3, 2);
    a->matrix[0][0] = 1;
    a->matrix[0][1] = 4;
    a->matrix[0][2] = 3;
    a->matrix[0][0] = 7;
    a->matrix[1][1] = 2;
    a->matrix[2][2] = 9;
    b->matrix[0][0] = 2;
    b->matrix[0][1] = 1;
    b->matrix[1][0] = 5;
    b->matrix[1][1] = 4;
    b->matrix[2][0] = 9;
    b->matrix[2][1] = 6;
    Matrix* d = mult_mm(a, b);
    if (d->matrix[0][0] != 49 || d->matrix[0][1] != 35 || d->matrix[1][0] != 105 || d->matrix[1][1] != 69) {
        return true;
    }
}

void run_tests() {
    uint32_t res;
    res = str_tests();
    print_test_result("String tests", res);
    res = malloc_test();
    print_test_result("Malloc tests", res);
}
