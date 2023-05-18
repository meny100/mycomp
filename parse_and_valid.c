#include "parse_and_valid.h"

void split_input(char *str, char *str_array[], int size)
{
	int i = 0;
	str_array[i] = strtok(str, " \t\n");
	for(i = 1; i < size; i++)
		str_array[i] = strtok(NULL, " \t\n");
}

int check_pattern(int state_cmd, char *tokens_array[])
{
	/*to each command there is a special valid pattern, we deciding this by state_cmd*/
	switch (state_cmd)
	{
		case READ_COMP:
		{
			if(is_a_valid_complex_name(tokens_array[1]) == ERROR)
				return ERROR;
			if(is_a_valid_comma(tokens_array[2]) == ERROR)
				return ERROR;
			if(is_a_valid_num(tokens_array[3]) == ERROR)
				return ERROR;
			if(is_a_valid_comma(tokens_array[4]) == ERROR)
				return ERROR;
			if(is_a_valid_num(tokens_array[5]) == ERROR)
				return ERROR;
			if(is_a_null(tokens_array[6]) == ERROR)
				return ERROR;
				
			return SUCCESS;
		}
		case PRINT_COMP:
		case ABS_COMP:
		{
			if(is_a_valid_complex_name(tokens_array[1]) == ERROR)
				return ERROR;
			if(is_a_null(tokens_array[2]) == ERROR)
				return ERROR;
			return SUCCESS;
		}
		case ADD_COMP:
		case SUB_COMP:
		case MULT_COMP_COMP:
		{
			if(is_a_valid_complex_name(tokens_array[1]) == ERROR)
				return ERROR;
			if(is_a_valid_comma(tokens_array[2]) == ERROR)
				return ERROR;
			if(is_a_valid_complex_name(tokens_array[3]) == ERROR)
				return ERROR;
			if(is_a_null(tokens_array[4]) == ERROR)
				return ERROR;
			return SUCCESS;
		}
		case MULT_COMP_REAL:
		case MULT_COMP_IMG:
		{
			if(is_a_valid_complex_name(tokens_array[1]) == ERROR)
				return ERROR;
			if(is_a_valid_comma(tokens_array[2]) == ERROR)
				return ERROR;
			if(is_a_valid_num(tokens_array[3]) == ERROR)
				return ERROR;
			if(is_a_null(tokens_array[4]) == ERROR)
				return ERROR;
			return SUCCESS;
		}
		case STOP:
		{
			if(is_a_null(tokens_array[1]) == ERROR)
				return ERROR;
			return SUCCESS;
		}
		case UNDEFINED_CMD:
		{
			printf("Undefined command name.\n");
			return ERROR;
		}
		default:
			printf("Unknown error occurred\n");
			return ERROR;
	}
}

int is_a_valid_complex_name(char *str)
{
	if(str == NULL)
		{
			printf("Complex number name is missing.\n");
			return ERROR;
		}
	if(strlen(str) > 1 || str[0] < 'A' || str[0] > 'F')
		{
			printf("Undefined complex variable.\n");
			return ERROR;
		}
	return SUCCESS;
}

int is_a_valid_comma(char *str)
{
	if(str == NULL)
		{
			printf("Comma is missing.\n");
			return ERROR;
		}
	if(strlen(str) > 1 || str[0] != ',')
		{
			printf("Comma is needed.\n");
			return ERROR;
		}
	return SUCCESS;
}

int is_a_valid_num(char *str)
{
	char *p;
	if(str == NULL)
		{
			printf("Number is missing.\n");
			return ERROR;
		}
	strtod(str, &p);
	if(*p != '\0')
		{
			printf("Invalid parameter - not a number.\n");
			return ERROR;
		}
	return SUCCESS;
}

int is_a_null(char *str)
{
	if(str != NULL)
		{
			printf("Extraneous text after end of command.\n");
			return ERROR;
		}
	return SUCCESS;
}