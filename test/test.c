#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void split_input(char *str, char *str_array[], int size);
char *read_line_and_add_spaces(char *str, int actual_size);


int main()
{
    int i;
    char *line_input;
    char *tokens_array[7];

    printf("\nPlease type your action:\n");
    /*read_line reads and store the input inside line_input if func succeed*/
    line_input = (char *)malloc(10*sizeof(char));
    if (line_input == NULL) 
    {
        printf("Error: memory allocation failed.\n");
    }
    line_input = read_line_and_add_spaces(line_input, 10);

    split_input(line_input, tokens_array, 7);
	printf("The splitted input is:\n");
	for(i = 0; i < 7; i++)
		printf("%d: %s\n", i, tokens_array[i]);

    return 0;
}

void split_input(char *str, char *str_array[], int size)
{
	int i = 0;
	str_array[i] = strtok(str, " \t");
	for(i = 1; i < size; i++)
		str_array[i] = strtok(NULL, " \t");
}

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
			str = (char *)realloc(str, (actual_size+=10)*sizeof(char));
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
	}

	str[curr] = '\0';
	return str;
}