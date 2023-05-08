#include "complex.h"

char *read_line_and_add_spaces(char *str, int actual_size)
{
	int curr = 0;
	char *tempP;/*help to free str allocation if realloc failed*/
	while((str[curr] = getchar()) != '\n' && str[curr] != EOF)
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
	str_array[i] = strtok(str, " \t");
	
	for(i = 1; i < size; i++)
		str_array[i] = strtok(NULL, " \t");
}

int check_pattern(int state_cmd, char *tokens_array[])
{
	/*to each command there is a special valid pattern, we deciding this by state_cmd*/
	switch (state_cmd)
	{
		case 0:
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
		case 1:
		case 7:
		{
			return SUCCESS;
		}
		case 2:
		case 3:
		case 6:
		{
			return SUCCESS;
		}
		case 4:
		case 5:
		{
			return SUCCESS;
		}
		case 8:
		{
			return SUCCESS;
		}
		case 9:
		{
			printf("Undefined command name.\n");
			return ERROR;
		}
		default:
			printf("Unknown error was occurred\n");
			return ERROR;
	}
}

void stop(int *stop_flag)
{
	*stop_flag = 1;
}

int is_a_valid_complex_name(char *str)
{
	if(strlen(str) > 1)
		{
			printf("Undefined complex variable1.\n");
			return ERROR;
		}
	if(str[0] < 'A' || str[0] > 'F')
		{
			printf("Undefined complex variable2.\n");
			return ERROR;
		}
	return SUCCESS;
}

int is_a_valid_comma(char *str)
{
	if(strlen(str) > 1 || str[0] != ',')
		{
			printf("Comma is missing.\n");
			return ERROR;
		}
	return SUCCESS;
}

int is_a_valid_num(char *str)
{
	char *p;
	strtod(str, &p);
	if(p != NULL)
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
			printf("Too many operands.\n");
			return ERROR;
		}
	return SUCCESS;
}
