#include<stdio.h>
#include<stdlib.h>

struct Matrix{
	int ordnung, **wert;
};
typedef struct Matrix matrix;

int determ(matrix *matr); /* matrix.c */
int defordnung(matrix *matr, int ordnung); /* matrix.c */
int invert(matrix *matr, matrix *inv); /* matrix.c */
int solve(matrix *matr); /* lgs.c */
int wertegeben(matrix *matr); /* io.c */



