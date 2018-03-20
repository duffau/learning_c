#include <stdio.h>

int main() {
	int i;
	int sum = 0;

	for (i = 0; i <10; i++) {
		sum += i;
		printf("%d\n", i);
	}
	printf("sum = %d\n", sum);
	printf("sum closed form = %d\n", ((i-1)*(i-1) + i-1)/2);
	return 0;
}