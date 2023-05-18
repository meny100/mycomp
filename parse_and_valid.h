#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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


void split_input(char *str, char *str_array[], int size);
int check_pattern(int state_cmd, char *tokens_array[]);
int is_a_valid_complex_name(char *str);
int is_a_valid_comma(char *str);
int is_a_valid_num(char *str);
int is_a_null(char *str);





