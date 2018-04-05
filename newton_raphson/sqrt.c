#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "newton_raphson.h"

float square(float x);

float square(float x) {
	return x*x;
}


int main(int argc, char **argv) {
	if(argc == 2) {
		float x = atof(argv[1]);
		printf("NewtonRaphson square root of %f: %.6f\n", x,NewtonRaphson(*square, x, 20,  1e-6));		
	} else {
		printf("Need to pass exactly one numerical argument.\n");
	}
	return 0;
}