#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define FIRST_SIZE 15
#define ENLARGE_SIZE(X) (X+=10)
#define TOKENS_ARRAY_SIZE 7
#define CMD_ARR_SIZE 9
#define ERROR -1
#define SUCCESS 1

#define READ_COMP 0
#define PRINT_COMP 1
#define ADD_COMP 2
#define SUB_COMP 3
#define MULT_COMP_REAL 4
#define MULT_COMP_IMG 5
#define MULT_COMP_COMP 6
#define ABS_COMP 7
#define STOP 8
#define UNDEFINED_CMD 9


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

char *read_line_and_add_spaces(char *str, int actual_size);
void split_input(char *str, char *str_array[], int size);
int check_pattern(int state_cmd, char *tokens_array[]);
int is_a_valid_complex_name(char *str);
int is_a_valid_comma(char *str);
int is_a_valid_num(char *str);
int is_a_null(char *str);

complex get_curr_comp(char c, complex comp_arr[]);




