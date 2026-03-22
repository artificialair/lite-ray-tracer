#include "std.h"

int strlen(const char * str) {
	const char * p = str;
	while (*p != '\0') {
		p++;
	}
	return p - str;
}

int atoi(const char * str) {
	int result = 0;
	int sign = 1;
	int i = 0;

	if (str[i] == '-') {
		sign = -1;
		i++;
	}

	while (str[i] >= '0' && str[i] <= '9') {
		result = result * 10 + (str[i] - '0');
		i++;
	}

	return result * sign;
}

const char * itoa(int n) {
	int size = 1;
	int temp = n;
	while (temp > 10) {
		temp /= 10;
		size++;
	}

    char* str = (char*)malloc(100);
	for (int i = size-1; i >= 0; i--) {
		char ascii_int = ((n % 10) + '0');
        str[i] = ascii_int;
		n = n / 10;
	}
    str[size] = '\0';
	return str;
}

void print_test_result(const char* title, bool result) {
    if (result) {
        print("\e[0;31m");
        print(title);
        print(": FAILED\e[0m\n");
        return;
    }
    print("\e[0;32m");
    print(title);
    print(": PASSED\e[0m\n");
}

bool streq(const char *s1, const char *s2) {
    uint32_t s1_len = strlen(s1);
    uint32_t s2_len = strlen(s2);
    if (s1_len != s2_len) return false;
    for (int i = 0; i < s1_len; i++) {
        if (s1[i] != s2[i]) return false;
    }
    return true;
}

/*
 * Memory leak!!!
 */
void strncpy(const char* s, char* dest, size_t size) {
    for (int i = 0; i < size; i++) {
        dest[i] = s[i];
    }
}

const char* strcat(const char* s1, const char* s2) {
    uint32_t s1len = strlen(s1);
    uint32_t s2len = strlen(s2);
    char* new_str  = (char *)malloc(s2len+s2len+1);
    strncpy(s1, new_str, s1len);
    strncpy(s2, new_str + s1len, s2len);
    new_str[s1len+s2len] = '\0';
    return (const char*) new_str;
}

float abs(float val) {
    return val < 0 ? -(val) : val;
}

bool float_eq(float f1, float f2) {
    return abs(f1 - f2) < FPT_ERR;
} 

const char* byte_to_hex(uint32_t num) { 
    const char hex_lookup[] = "0123456789abcdef";
    int len = 8;
    char* s = (char *)malloc(len+1);

    if (len & 1) {
        *s++ = '0';
    }
    s[len] = '\0';

    for (--len; len >= 0; num >>= 4, --len) {
        s[len] = hex_lookup[num & 0xf];
    }
    return s;
}
