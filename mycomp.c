#include "complex.h"




int main()
{
	/*Declaration and initialization*/
	complex A = {0,0}, B = {0,0}, C = {0,0}, D = {0,0}, E = {0,0}, F = {0,0};
	/*struct {
		char name;
		complex comp;
	}  complexes[6] =  {
			{'A', A},
			{'B', B},
			{'C', C},
			{'D', D},
			{'E', E},
			{'F', F},
			{'#', NULL}
		};*/
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
			"not_valid"
		};
	int state_cmd;/*between 0-9*/
	

	printf("This program deals actions with complex numbers. There are 6 complex numbers, A-F and 6 actions:\n");
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
		char *tokens_array[TOKENS_ARRAY_SIZE];
		int i;
		int valid_line;

		printf("\nPlease type your action:\n");
		/*read_line reads and store the input inside line_input if func succeed*/
		line_input = (char *)malloc(FIRST_SIZE*sizeof(char));
		line_input = read_line_and_add_spaces(line_input, FIRST_SIZE);

		/*split the line into tokens and store them in tokens array*/
		split_input(line_input, tokens_array, TOKENS_ARRAY_SIZE);

		/*The tokens_array[0] is the command*/
		for(i = 0; i < CMD_ARR_SIZE; i++)
			if(strcmp(tokens_array[0], cmd_array[i]) == 0)
			{
				state_cmd = i;
				printf("on strcmp %d %s",i, cmd_array[i]);
				break;
			}

		/*checking the pattern of the rest of the string according to command was choose.*/
		valid_line = check_pattern(state_cmd, tokens_array);

		if(valid_line == SUCCESS){
			/*active the functions*/
			printf("SUCCESS!!");
		}

		free(line_input);
	}
	return 0;
}
