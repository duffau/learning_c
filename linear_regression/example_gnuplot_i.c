#include <unistd.h>
#include "gnuplot_i/gnuplot_i.h"

int main() {
	gnuplot_ctrl * h ;
    h = gnuplot_init();
    gnuplot_cmd(h, "set terminal png");
    gnuplot_cmd(h, "set output 'plot.png'");
    gnuplot_cmd(h, "set autoscale xy");
    gnuplot_setstyle(h, "lines");
    double x[] = {1.0, 2.0, 3.0, 4.0};
    double y1[] = {1.0, 4.0, 9.0, 16.0};
    double y2[] = {1.0, 1.5, 2.0, 2.2};
    gnuplot_plot_xy(h, x, y1, 4, "Test Plot 1"); 
    gnuplot_plot_xy(h, x, y2, 4, "Test Plot 2"); 
    gnuplot_close(h);
}