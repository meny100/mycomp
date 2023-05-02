#include "complex.h"

void read_comp(complex *c, float real, float img)
{
	(*c).real = real;
	(*c).img = img;
}

void print_comp(complex c)
{
	printf("%.2f + (%.2f)i \n", c.real, c.img);
}

void add_comp(complex a, complex b)
{
	complex new;
	new.real = a.real + b.real;
	new.img = a.img + b.img;
	print_comp(new);
}

void sub_comp(complex a, complex b)
{
	complex new;
	new.real = a.real - b.real;
	new.img = a.img - b.img;
	print_comp(new);
}

void mult_comp_real(complex comp_a, float real)
{
	complex new;
	new.real = comp_a.real*real;
	new.img = comp_a.img*real;
	print_comp(new);
}

void mult_comp_img(complex comp_a, float img)
{
	complex new;
	new.real = -(img*comp_a.img);
	new.img = comp_a.real*img;
	print_comp(new);
}

void mult_comp_comp(complex a, complex b)
{
	complex new;
	new.real = a.real*b.real - a.img*b.img;
	new.img = a.real*b.img + a.img*b.real;
	print_comp(new);
}

void abs_comp(complex c)
{
	float result = sqrt(pow(c.real, 2) + pow(c.img, 2));

	printf("%.2f", result);
}