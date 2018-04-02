#include <stdio.h>

int factorial(int n);

int main() {
	printf("factorial(1): %d\n", factorial(1));
	printf("factorial(2): %d\n", factorial(2));
	printf("factorial(3): %d\n", factorial(3));
	printf("factorial(8): %d\n", factorial(8));

}

int factorial(int n) {
	if (n ==1 ) {
		return 1;
	} else {
		return n*factorial(n-1);
	}
}