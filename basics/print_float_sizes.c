#include <stdio.h>
#include <float.h>

int main() {
	printf("Size of float: %zu \n", sizeof(float));
	printf("Size of double: %zu \n", sizeof(double));
	printf("Size of long double: %zu \n", sizeof(long double));
	printf("Minimum value of a float: %E \n", FLT_MIN);
	printf("Maximum value of a float: %E \n", FLT_MAX);
	return 0;
}