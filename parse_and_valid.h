#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*state of validation command*/
#define ERROR -1
#define SUCCESS 1

/*state of command*/
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


/*split the string into tokens by space and '\t' and store them in the str_array*/
void split_input(char *str, char *str_array[], int size);
/*according to state_cmd checking the pattern in tokens array. return success or error*/
int check_pattern(int state_cmd, char *tokens_array[]);
/*checks if the name of the complex variable is legal*/
int is_a_valid_complex_name(char *str);
/*checks if the string is a comma*/
int is_a_valid_comma(char *str);
/*checks if the string is a valid floating number*/
int is_a_valid_num(char *str);
/*checks if the string is a null*/
int is_a_null(char *str);





