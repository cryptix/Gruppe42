#include <stdio.h>
#include <stdlib.h>

typedef struct{
	unsigned int row;	/* zeilen */
	unsigned int col;	/* spalten */
	double det;	/* determinante */
	double *wert; /* daten */
	double *vec; /* lösungsvektor */
} matrix;

enum { ORDER=1, INA, DETA, INVA, SOLVE, HELP, QUIT, UNKWN};

int determ(matrix *matr); /* matrix.c - jan */
double getDet(matrix*); /* matrix.c */
int invert(matrix *matr, matrix *inv); /* matrix.c - henry */
int solve(matrix *matr); /* lgs.c - jan */

matrix *identMat(unsigned int order);

int getopt(matrix *); /* io.c - jannik */

/* tools.c */
matrix *allocMat(unsigned int row, unsigned int col);
void freeMat(matrix *matr);
void printMat(matrix *matr);
