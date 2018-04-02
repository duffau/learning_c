#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float randfloat();
float mean(float x);

int main() {
	srand(time(NULL));

	int i;
	float x, m;

	for (i=1; i < 151; i++) {
		x = randfloat();
		m = mean(x);
		printf("i = %d, x = %.3f, current mean = %.3f\n", i, x, m);
	}

	return 0;
}

float randfloat() {
	return (float)rand()/(float)RAND_MAX;
}

float mean(float x) {
	static float current_mean = 0.0;
	static int count = 0;
	current_mean += (x - current_mean)/(count+1);
	count++;
	return current_mean;
}