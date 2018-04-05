#include <stdio.h>
#include <stdlib.h>
//#include "fit_predict.h"

#define MAX_SIZE 1000

int numberOfLines(char * filename);


int main(int argc, char** argv) {
	int i, n_lines;
	
	FILE *gnuplot = popen("gnuplot", "w");
	fprintf(gnuplot, "set terminal png\n");
	fprintf(gnuplot, "set title 'Worst case timings'\n");
	fprintf(gnuplot, "set xlabel 'Array size'\n");
	fprintf(gnuplot, "set ylabel 'Average execution time'\n");
	fprintf(gnuplot, "set output 'plot.png'\n");

	int n_files = argc - 1;

	if (n_files == 1) {
		n_lines = numberOfLines(argv[1]);
		printf("%d lines in file: %s\n",n_lines, argv[1]);
		fprintf(gnuplot, "plot '%s' using 1:2 title '%s' with lines", argv[1], argv[1]);
	} else {
		for (i = 1; i < argc; i++) {
		    if (i == 1) {
		    	fprintf(gnuplot, "plot '%s' using 1:2 title '%s' with lines,", argv[i], argv[i]);
		    } else if (i < argc - 1) {
		    	fprintf(gnuplot, "'%s' using 1:2 title '%s' with lines,", argv[i], argv[i]);
		    } else  if (i == argc - 1) {
		    	fprintf(gnuplot, "'%s' using 1:2 title '%s' with lines", argv[i], argv[i]);
		    }
		}

	}

	fflush(gnuplot);
}

int numberOfLines(char * filename) {
	char line[MAX_SIZE];
	FILE * in_file = fopen(filename, "r");
    if(in_file == NULL){
        fprintf(stderr, "Unable to open file");
        return 0;
    }
    int counter = 0; /*Number of lines*/

    while(fgets(line, sizeof(line), in_file) != NULL){
        counter++;
    }
    return counter;
}
