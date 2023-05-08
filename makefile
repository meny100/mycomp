mycomp: mycomp.c complex.c stringdeal.c
	gcc -ansi -pedantic -Wall mycomp.c complex.c stringdeal.c -lm -o mycomp
