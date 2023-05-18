mycomp: mycomp.c complex.c parse_and_valid.c
	gcc -ansi -pedantic -Wall mycomp.c complex.c parse_and_valid.c -lm -o mycomp
