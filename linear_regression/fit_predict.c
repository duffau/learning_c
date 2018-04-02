#include <stdio.h>
#include <gsl/gsl_multifit.h>
#include "fit_predict.h"

void FitPredict(char *filename, double y_preds ,int n_observations, double (*functions[])(double), int n_functions) {

	int i, j;
	double xi, y_pred, fxi, yi, chisq;
	gsl_matrix *X, *cov;
	gsl_vector *y, *c;


	int n_dim = n_functions + 1;
	X = gsl_matrix_alloc(n, n_dim);
	y = gsl_vector_alloc(n);
	c = gsl_vector_alloc(n_dim);
	cov = gsl_matrix_alloc(n_dim, n_dim);
	
	fp = fopen (filename, "r");
	
	for (i = 0; i < n_observations; i++) {
		int count = fscanf (fp, "%lg %lg", &xi, &yi);
		if(count != 2){
			fprintf (stderr, "error reading file\n");
			exit(-1);
		}
		printf ("%g %g\n", xi, yi);
		gsl_vector_set (y, i, yi);
		gsl_matrix_set (X, i, 0, 1.0);
		for (j = 0; j<n_functions;  j++) {
			fxi = (*functions[j])(xi);
			gsl_matrix_set(X, i, j+1, fxi);
		}
	}

	// Defining workspace for linear regression and fitting model
	{
		gsl_multifit_linear_workspace *work = gsl_multifit_linear_alloc (n, 3);
		gsl_multifit_linear(X, y, c, cov, &chisq, work);
		gsl_multifit_linear_free(work);
	}

	#define C(i) (gsl_vector_get(c,(i)))

	{
		printf ("# best fit: Y = ");
		for ( i=0; i<n_functions; i++ ) {
			printf("+ %g f_%d(x)\n", C(i), i);
			printf("\n");
		}

		for (i = 0; i<n_observations; i++) {
			y_pred = C(0);
			for (j = 0; j<n_functions;  j++) {
				fxi = (*functions[j])(xi);
				y_pred += C(j+1) * fxi;
			}
			y_preds[i] = y_pred;

		}
	}
	gsl_matrix_free (X);
	gsl_vector_free (y);
	gsl_vector_free (c);
	gsl_matrix_free (cov);

}



	


