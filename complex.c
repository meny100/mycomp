#include "complex.h"


void read_comp(complex *c, float real, float img)
{
	(*c).real = real;
	(*c).img = img;
}

void print_comp(complex comp)
{
	char sign = comp.img >= 0 ? '+':' ';
	printf("%.2f %c (%.2f)i \n", comp.real, sign, comp.img);
}

void add_comp(complex a, complex b)
{
	complex result;
	result.real = a.real + b.real;
	result.img = a.img + b.img;
	print_comp(result);
}

void sub_comp(complex a, complex b)
{
	complex result;
	result.real = a.real - b.real;
	result.img = a.img - b.img;
	print_comp(result);
}

void mult_comp_real(complex comp, float real)
{
	complex result;
	result.real = comp.real*real;
	result.img = comp.img*real;
	print_comp(result);
}

void mult_comp_img(complex comp, float img)
{
	complex result;
	result.real = -(img*comp.img);
	result.img = comp.real*img;
	print_comp(result);
}

void mult_comp_comp(complex a, complex b)
{
	complex result;
	result.real = a.real*b.real - a.img*b.img;
	result.img = a.real*b.img + a.img*b.real;
	print_comp(result);
}

void abs_comp(complex comp)
{
	float result = sqrt(pow(comp.real, 2) + pow(comp.img, 2));
	printf("%.2f", result);
}