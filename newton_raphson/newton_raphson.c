#include <stdio.h>
#include "newton_raphson.h"


float absolute(float x) {
	if (x < 0) {
		return -x;
	} else {
		return x;
	}
}

float numDerivative(float (*func)(float), float x, float h) {
	return ((*func)(x + h) - (*func)(x))/h;
}

float NewtonRaphson(float (*func)(float), float target, int maxIterations, float threshold) {
	float x_solution = 1.0;
	float func_deviance; 
	int n_iter = 0;
	while(1) {
		func_deviance = (*func)(x_solution) - target;
		printf("func_deviance = %f\n", func_deviance);
		if (absolute(func_deviance) < threshold) {
			printf("Solution found! Function deviation less than threshold: %f\n", threshold);
			break;
		}
		if (n_iter > maxIterations) {
			printf("maxIterations reached.\n");
			break;
		}
		x_solution -= func_deviance/numDerivative(func, x_solution, 0.0001);
		n_iter++;
	}
	return x_solution;
}



