#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>



typedef struct comp
{
    float real;
    float img;
} complex;

void read_comp(complex *c, float real, float img);
void print_comp(complex c);
void add_comp(complex a, complex b);
void sub_comp(complex a, complex b);
void mult_comp_real(complex comp_a, float real);
void mult_comp_img(complex comp_a, float img);
void mult_comp_comp(complex a, complex b);
void abs_comp(complex c);
