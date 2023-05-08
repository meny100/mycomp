#include "complex.h"

int read_line_and_add_spaces(char *str)
{
	int curr = 0;
	char *tempP;/*help to free str allocation if realloc failed*/
	int actual_size = FIRST_SIZE;

	while((str[curr] = getchar()) != '\n' && str[curr] != EOF)
	{
		/*performing re-allocation if the user want to input more element than the given array space*/
		/*ensuring that there is FREE_SPACES free spaces*/
		if(curr + FREE_SPACES >= actual_size)
		{
			tempP = str;
			/*ENLARGE_SIZE changes the size of actual_size*/
			str = (char *)realloc(str, ENLARGE_SIZE(actual_size));
			if(str == NULL)
				{
					free(tempP);
					return ERROR_ALLOCATION;
				}
		}
		if(str[curr] == ',')
		{
			/*separate commas by space*/
			str[curr] = ' ';
			str[++curr] = ',';
			str[++curr] = ' ';
		}
		curr++;
	}
	if(str[curr] == EOF)
		return ERROR_EOF;

	str[curr] = '\0';
	return SUCCESS;
}

void split_input(char *str, char *str_array[], int size)
{
	int i = 0;
	str_array[i] = strtok(str, " ");
	for(i = 1; i < size && str_array[i] != NULL; i++)
	{
		str_array[i] = strtok(NULL, " ");
	}
}

/* TODO
void analyze_input(*parseRes)
{
        int error; // 0 is valid, 1 arg1 missing, 2 command not valid. instead this attribute you can creat method to analyze the parse result.
		char command[SIZE_TOK];
		char arg1[SIZE_TOK];
		char arg2[SIZE_TOK];
		char arg3[SIZE_TOK];
}*/

void stop(int *stop_flag)
{
	*stop_flag = 1;
}