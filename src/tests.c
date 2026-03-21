#include "tests.h"

bool malloc_test() {
    print("before\n");
    void* ptr = malloc(MALLOC_SIZE);
    print("after\n");
    if (ptr == NULL) return true;
    char* arr = (char *)ptr;
    for (int i = 0; i < MALLOC_SIZE; i++) {
        arr[i] = 'A';
        char dummy = arr[i];
    }
    char str[] = {arr[MALLOC_SIZE-1], '\n', '\0'};
    print(str);
    return false;
}

bool str_tests() {
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
    /*const char* num_str = itoa(num);
    if (num_str != int_str) return true;
    print("test5");*/
    return false;
}

void run_tests() {
    uint32_t res = malloc_test();
    print_test_result(res);
    res = str_tests();
    print_test_result(res);
}
