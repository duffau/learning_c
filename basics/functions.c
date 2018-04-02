#include <stdio.h>
#include <math.h>

int factorial(int n);
float eulersConstant(int iterations);
float poissonPMF(int k, float lambda);


int factorial(int n) {
	int i=0; 
	int fac=1;
	while (i<n) {
		fac *= i+1;
		i++;
	}
	return fac;
}

float eulersConstant(int iterations) {
	int n = 0;
	float e = 0.0;
	while(n < iterations) {
		e += 1.0/factorial(n);
		n++;
	}
	return e;
}

#define EULERS_E eulersConstant(32)


float poissonPMF(int k, float lambda) {
	return pow(lambda, k)*pow(EULERS_E, -lambda)/factorial(k);
}


int main() {
	int i, k;
	for(i=0; i < 10; i++) {
		printf("factorial(%d) = %d\n", i, factorial(i));
	}
	for(i=0; i < 10; i++) {
		printf("eulersConstant(%d) = %.8f\n", i, eulersConstant(i));
	}
	printf("EULERS_E:%.10f\n", EULERS_E);
	const float lambda = 1.0;

	for(k=0; k< 10; k++) {
		printf("poissonPMF(%d, %f) = %f\n", k, lambda, poissonPMF(k, lambda));
	}
}