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
	int i = 0;
	int stop_flag = 0;
	int read_status;
	char *line_input;
	char *tokens_array[TOKENS_ARRAY_SIZE] = {'\0'};

	printf("This program deals actions with complex numbers. There are 6 complex numbers, A-F and 6 actions:\n");
	printf("1) read_comp NAME, REAL1, REAL2.\n");
	printf("2) print_comp NAME.\n");
	printf("3) add_comp NAME1, NAME2.\n");
	printf("4) sub_comp NAME1, NAME2.\n");
	printf("5) mult_comp_real NAME, REAL.\n");
	printf("6) mult_comp_img NAME1, IMG.\n");
	printf("7) mult_comp_comp NAME1, NAME2.\n");
	printf("8) abs_comp NAME.\n");
	printf("9) stop.\n\n");

	while (!stop_flag)
	{
		printf("Please type your action:\n");
		/*read_line reads and store the input inside line_input if func succeed*/
		line_input = (char *)malloc(FIRST_SIZE);
		read_status = read_line_and_add_spaces(line_input);
		if(read_status == ERROR_EOF)
		{
			printf("ERROR: exit from the program allowed only by stop() function!\n");
			return ERROR;
		}
		if(read_status == ERROR_ALLOCATION)
		{
			printf("ERROR: allocation failed, no free space found.\n");
			return ERROR;
		}
		printf("The line after func: %s\n", line_input);

		split_input(line_input, tokens_array, TOKENS_ARRAY_SIZE);
		printf("The tokens_array after split:\n");
		for(; i < TOKENS_ARRAY_SIZE; i++)
			printf("%d) %s\n", i+1, tokens_array[i]);
		/*scan into line_input;
		struct of parser(line_input); // hard part
		analyzeParserResult();
		check the analyze --> error or execute.



		if(fgets("%s", line_input))
		{
			strtok(line_input, " ,");
			for(i = 0; i < 4; i++)
				strtok(NULL, " ,"); 
			for(i = 0; cmd[i].func != NULL; i++)
				if(strcmp(command, cmd[i].name)==0)
					break;

			if(cmd[i].func == NULL)
				printf("Command does not exist: %s", command);
			else
				(*(cmd[i].func))();
		}*/
	}
	return 0;
}
