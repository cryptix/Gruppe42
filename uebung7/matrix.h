#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int ordnung
	int **wert;
} matrix;

enum { ORDER=1, INA, DETA, INVA, SOLVE, HELP, QUIT, UNKWN};

int determ(matrix *matr); /* matrix.c */
int defordnung(matrix *matr, int ordnung); /* matrix.c */
int invert(matrix *matr, matrix *inv); /* matrix.c */
int solve(matrix *matr); /* lgs.c */
int wertegeben(matrix *matr); /* io.c */

int getopt(char *); /* getopt.c */

