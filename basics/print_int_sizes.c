#include <stdio.h>
#include <limits.h>

int main() {
	printf("Size of char: %zu \n", sizeof(char));
	printf("Size of unsigned char: %zu \n", sizeof(unsigned char));
	printf("Size of signed char: %zu \n", sizeof(signed char));
	printf("Size of int: %zu \n", sizeof(int));
	printf("Size of unsigned int: %zu \n", sizeof(unsigned int));
	printf("Size of short: %zu \n", sizeof(short));
	printf("Size of unsigned short: %zu \n", sizeof(unsigned short));
	printf("Size of long: %zu \n", sizeof(long));
	printf("Size of unsigned long: %zu \n", sizeof(unsigned long));
	return 0;
}