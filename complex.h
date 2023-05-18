#include <stdio.h>
#include <math.h>

typedef struct complex
{
    double real;
    double img;
} complex;


void read_comp(complex *c, double real, double img);
void print_comp(complex c);
void add_comp(complex a, complex b);
void sub_comp(complex a, complex b);
void mult_comp_real(complex comp_a, double real);
void mult_comp_img(complex comp_a, double img);
void mult_comp_comp(complex a, complex b);
void abs_comp(complex c);
void stop();






