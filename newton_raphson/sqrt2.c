#include <stdio.h>
#include <math.h>
#include "newton_raphson.h"

float square(float x);

float square(float x) {
	return x*x;
}


int main() {
	printf("square(1.41421356237) = %f\n", square(1.41421356237));
	printf("NewtonRaphson square root of 2: %.6f\n", NewtonRaphson(*square, 2.0, 20,  1e-6));
	printf("math square root of 2: %.6f\n", pow(2.0, 0.5));
}