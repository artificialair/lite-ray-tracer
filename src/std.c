#include "std.h"

int strlen(const char * str) {
	const char * p = str;
	while (*p != '\0') {
		p++;
	}
	return p - str;
}

int atoi(char * str) {
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

char * itoa(int n) {
	int size = 0;
	int temp = n;
	while (temp > 10) {
		temp /= 10;
		size++;
	}

	char* str = malloc(size);
	for (int i = size; i > 0; i--) {
		str[i] = n % 10;
		n = n / 10;
	}

	return str;
}
