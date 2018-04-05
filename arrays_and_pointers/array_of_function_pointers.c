#include <stdio.h>
#include <stdlib.h>

void FitPredict(double array[], double y_preds[], const int n_observations, double (*functions[])(double), int n_functions);

double identity(double x);
double square(double x);
double cube(double x);



int main() {
	double array[] = {1,2,3,4,5,6};
	double y_preds[6];
	double (*functions[])(double) = {identity, square, cube};

	FitPredict(array, y_preds, 6, functions, 3);

}

double identity(double x) {
	return x;
}

double square(double x) {
	return x*x;
}

double cube(double x) {
	return x*x*x;
}


void FitPredict(double array[], double y_preds[], const int n_observations, double (*functions[])(double), int n_functions) {

	int i, j;
	double xi, fxi, y_pred;

	// static double *y_preds = malloc(n_observations * sizeof *y_preds);

	// static double y_preds[n_observations];

	
	for (i = 0; i < n_observations; i++) {
		y_pred = 0.0;
		xi = array[i];
		for (j = 0; j<n_functions;  j++) {
			fxi = (*functions[j])(xi);
			y_pred += fxi;
			printf ("xi = %g f_%d(xi)=%g y_pred = %g\n", xi, j, fxi, y_pred);
		}
		y_preds[i] = y_pred;
	}

}
