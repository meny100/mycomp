#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define FIRST_SIZE 15
#define FREE_SPACES 3
#define ENLARGE_SIZE(X) (X+=5)

#define TOKENS_ARRAY_SIZE 7

#define SUCCESS 1
#define ERROR_EOF -1
#define ERROR_ALLOCATION -2
#define ERROR -3

typedef struct complex
{
    float real;
    float img;
} complex;

/*typedef struct parseRes
	{
		int error; // 0 is valid, 1 arg1 missing, 2 command not valid. instead this attribute you can creat method to analyze the parse result.
		char command[SIZE_TOK];
		char arg1[SIZE_TOK];
		char arg2[SIZE_TOK];
		char arg3[SIZE_TOK];
	}parseRes;*/

void read_comp(complex *c, float real, float img);
void print_comp(complex c);
void add_comp(complex a, complex b);
void sub_comp(complex a, complex b);
void mult_comp_real(complex comp_a, float real);
void mult_comp_img(complex comp_a, float img);
void mult_comp_comp(complex a, complex b);
void abs_comp(complex c);

void stop();

int read_line_and_add_spaces(char *str);
void split_input(char *str, char *str_array[], int size);

/*struct {
		char *name;
		void(*func)();
	}  cmd[10] =  {
			{"read_comp",read_comp},
			{"print_comp",print_comp},
			{"add_comp",add_comp},
			{"sub_comp",sub_comp},
			{"mult_comp_real",mult_comp_real},
			{"mult_comp_img",mult_comp_img},
			{"mult_comp_comp",mult_comp_comp},
			{"abs_comp",abs_comp},
			{"stop",stop},
			{'not_valid', NULL}
		};*/
