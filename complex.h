#include <stdio.h>
#include <math.h>

/*this struct represent complex number with real and imagine parts*/
typedef struct complex
{
    double real;
    double img;
} complex;

/*get address of complex number and change his value according the parameters*/
void read_comp(complex *c, double real, double img);
/*get complex number and print to screen*/
void print_comp(complex c);
/*add 2 complex numbers and print result*/
void add_comp(complex a, complex b);
/*sub complex number from other and print result*/
void sub_comp(complex a, complex b);
/*mult complex number and real number and print result*/
void mult_comp_real(complex comp_a, double real);
/*mult complex number and img number and print result*/
void mult_comp_img(complex comp_a, double img);
/*mult 2 complex numbers and print result*/
void mult_comp_comp(complex a, complex b);
/*calculate the absolute value of complex number and print result*/
void abs_comp(complex c);







