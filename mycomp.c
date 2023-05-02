#include "complex.h"
#define SIZE_COMMAND 20

int main()
{
	/*Declaration and initialization*/
	complex A = {0,0}, B = {0,0}, C = {0,0}, D = {0,0}, E = {0,0}, F = {0,0};
	char command[SIZE_COMMAND];


	printf("This program deals actions with complex numbers. There are 6 complex numbers, A-F and 6 actions:\n");
	printf("read_comp NAME, REAL1, REAL2.\n");
	printf("print_comp NAME.\n");
	printf("add_comp NAME1, NAME2.\n");
	printf("sub_comp NAME1, NAME2.\n");
	printf("mult_comp_real NAME, REAL.\n");
	printf("mult_comp_img NAME1, IMG.\n");
	printf("mult_comp_comp NAME1, NAME2.\n");
	printf("abs_comp NAME.\n");
	printf("Please enter your action:\n");

	scanf("%s", command);

	return 0;
}
