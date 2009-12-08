#include <stdio.h>
#include <stdlib.h>

typedef struct{
	unsigned int row;	/* zeilen */
	unsigned int col;	/* spalten */
	double det;	/* detrminante */
	double *wert; /* daten */
} matrix;

enum { ORDER=1, INA, DETA, INVA, SOLVE, HELP, QUIT, UNKWN};

int determ(matrix *matr); /* matrix.c - jan */
int defordnung(matrix *matr, int ordnung); /* matrix.c - jannik */
int invert(matrix *matr, matrix *inv); /* matrix.c - henry */
int solve(matrix *matr); /* lgs.c - jan */
int wertegeben(matrix *matr); /* io.c - jannik*/

int getopt(matrix *); /* getopt.c - henry */

/* tools.c */
void printfMat(matrix *matr);
