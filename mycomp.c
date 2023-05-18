#include "complex.h"
#include "parse_and_valid.h"

#define COMP_ARR_SIZE 6
#define CMD_ARR_SIZE 9
#define FIRST_SIZE 15
#define ENLARGE_SIZE(X) (X+=10)
#define TOKENS_ARRAY_SIZE 7



char *read_line_and_add_spaces(char *str, int actual_size);
complex get_curr_comp(char c, complex comp_arr[]);


int main()
{
	/*Declaration and initialization*/
	complex A = {0,0}, B = {0,0}, C = {0,0}, D = {0,0}, E = {0,0}, F = {0,0};
	complex complex_arr[COMP_ARR_SIZE];

	int stop_flag = 0;
	char *cmd_array[CMD_ARR_SIZE] =  {
			"read_comp",
			"print_comp",
			"add_comp",
			"sub_comp",
			"mult_comp_real",
			"mult_comp_img",
			"mult_comp_comp",
			"abs_comp",
			"stop",
		};
	int state_cmd;

	complex_arr[0] = A;
	complex_arr[1] = B;
	complex_arr[2] = C;
	complex_arr[3] = D;
	complex_arr[4] = E;
	complex_arr[5] = F;
	

	printf("This program deals actions with complex numbers. There are 6 complex numbers, A-F and 9 actions:\n");
	printf("1) read_comp NAME, REAL1, REAL2.\n");
	printf("2) print_comp NAME.\n");
	printf("3) add_comp NAME1, NAME2.\n");
	printf("4) sub_comp NAME1, NAME2.\n");
	printf("5) mult_comp_real NAME, REAL.\n");
	printf("6) mult_comp_img NAME1, IMG.\n");
	printf("7) mult_comp_comp NAME1, NAME2.\n");
	printf("8) abs_comp NAME.\n");
	printf("9) stop.\n");

	while (!stop_flag)
	{
		char *line_input;
		char *tokens_array[TOKENS_ARRAY_SIZE] = {NULL};
		int i;
		int valid_line;
		complex curr_comp1, curr_comp2;
		char *endptr;

		printf("\nPlease type your action:\n");
		/*read_line reads and store the input inside line_input if func succeed*/
		line_input = (char *)malloc(FIRST_SIZE*sizeof(char));
		if (line_input == NULL) 
		{
			printf("Error: memory allocation failed.\n");
			exit(EXIT_FAILURE);
		}
		line_input = read_line_and_add_spaces(line_input, FIRST_SIZE);
		printf("The line as read from input is: %s\n", line_input);

		/*split the line into tokens and store them in tokens array*/
		split_input(line_input, tokens_array, TOKENS_ARRAY_SIZE);

		/*Finding the command. The tokens_array[0] is the command*/
		for(i = 0; i < CMD_ARR_SIZE; i++)
			if(strcmp(tokens_array[0], cmd_array[i]) == 0)
				break;
			state_cmd = i;

		/*checking the pattern of the rest of the string according to command was choose.*/
		valid_line = check_pattern(state_cmd, tokens_array);

		if(valid_line == SUCCESS)
		{
			switch (state_cmd)
			{
				case READ_COMP:
				{
					complex *compP;
					switch(*tokens_array[1])
					{
						case 'A':
							compP = &complex_arr[0];
							break;
						case 'B':
							compP = &complex_arr[1];
							break;
						case 'C':
							compP = &complex_arr[2];
							break;
						case 'D':
							compP = &complex_arr[3];
							break;
						case 'E':
							compP = &complex_arr[4];
							break;
						case 'F':
							compP = &complex_arr[5];
							break;
					}
					read_comp(compP, strtod(tokens_array[3], &endptr), strtod(tokens_array[5], &endptr));
					break;
				}
				case PRINT_COMP:
				{
					curr_comp1 = get_curr_comp(*tokens_array[1], complex_arr);
					print_comp(curr_comp1);
					break;
				}
				case ADD_COMP:
				{
					curr_comp1 = get_curr_comp(*tokens_array[1], complex_arr);
					curr_comp2 = get_curr_comp(*tokens_array[3], complex_arr);
					add_comp(curr_comp1, curr_comp2);
					break;
				}
				case SUB_COMP:
				{
					curr_comp1 = get_curr_comp(*tokens_array[1], complex_arr);
					curr_comp2 = get_curr_comp(*tokens_array[3], complex_arr);
					sub_comp(curr_comp1, curr_comp2);
					break;
				}
				case MULT_COMP_REAL:
				{
					curr_comp1 = get_curr_comp(*tokens_array[1], complex_arr);
					mult_comp_real(curr_comp1, strtod(tokens_array[3], &endptr));
					break;
				}
				case MULT_COMP_IMG:
				{
					curr_comp1 = get_curr_comp(*tokens_array[1], complex_arr);
					mult_comp_img(curr_comp1, strtod(tokens_array[3], &endptr));
					break;
				}
				case MULT_COMP_COMP:
				{
					curr_comp1 = get_curr_comp(*tokens_array[1], complex_arr);
					curr_comp2 = get_curr_comp(*tokens_array[3], complex_arr);
					mult_comp_comp(curr_comp1, curr_comp2);
					break;
				}
				case ABS_COMP:
				{
					curr_comp1 = get_curr_comp(*tokens_array[1], complex_arr);
					abs_comp(curr_comp1);
					break;
				}
				case STOP:
				{
					stop(&stop_flag);
					break;
				}
			}
		}

		free(line_input);
	}
	return 0;
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
