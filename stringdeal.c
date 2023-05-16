#include "complex.h"

char *read_line_and_add_spaces(char *str, int actual_size)
{
	int curr = 0;
	char *tempP;/*help to free str allocation if realloc failed*/
	while((str[curr] = getchar()) != EOF && str[curr] != '\n')
	{
		/*performing re-allocation if the user type chars more than the given space*/
		/*if str[curr] == ',' we need to ensure that we have free space ahead to separate it*/
		if(curr >= actual_size || str[curr] == ',')
		{
			tempP = str;
			/*ENLARGE_SIZE changes the size of actual_size*/
			str = (char *)realloc(str, ENLARGE_SIZE(actual_size)*sizeof(char));
			if(str == NULL)
				{
					free(tempP);
					printf("ERROR: allocation failed, no free space found.\n");
					exit(EXIT_FAILURE);
				}

			if(str[curr] == ',')
			{
				/*separate commas by space*/
				str[curr] = ' ';
				str[++curr] = ',';
				str[++curr] = ' ';
			}
		}
		curr++;
	}


	if(str[curr] == EOF)
	{
		printf("ERROR: exit from the program allowed by stop() function only!\n");
		exit(EXIT_FAILURE);
	}

	str[curr] = '\0';
	return str;
}

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

void stop(int *stop_flag)
{
	*stop_flag = 1;
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
	if(str == NULL ||  strlen(str) > 1 || str[0] != ',')
		{
			printf("Comma is missing.\n");
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
	if(strcmp(str, "\0") == 0 || str == NULL)
		{
			printf("Too many characters for this operator.\n");
			return ERROR;
		}
	return SUCCESS;
}

complex get_curr_comp(char c, complex comp_arr[])
{
	switch(c)
	{
		complex default_comp = {0, 0};
		case 'A':
			return comp_arr[0];
		case 'B':
			return comp_arr[1];
		case 'C':
			return comp_arr[2];
		case 'D':
			return comp_arr[3];
		case 'E':
			return comp_arr[4];
		case 'F':
			return comp_arr[5];
		default:
			return default_comp;
	}
}