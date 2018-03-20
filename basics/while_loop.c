#include <stdio.h>

int main() {
	int n = 0;
	
	while (n<10) {
		n++;
		printf("n = %d\n", n);
	}


	n = 0;
	while (1) {
		n++;
		printf("n = %d\n", n);

		if (n == 10) {
			printf("breaking loop\n");
			break;
		}
	}

	n = 0;
	while (n<10) {
		n++;
		printf("n = %d\n", n);

		if (n % 2 == 1) {
			printf("n is odd\n");
			continue;
		}

		printf("End of loop iteration %d\n", n);
	}

	return 0;
}