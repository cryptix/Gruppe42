#include <stdio.h>
#include <stdlib.h>

typedef struct{
	unsigned int row;	/* zeilen */
	unsigned int col;	/* spalten */
	double det;	/* determinante */
	double *wert; /* daten */
	double *vec; /* lösungsvektor */
	double *slv_x; /* multiplikationsvektor : mat * slv_x = vec*/

} matrix;

enum { ORDER=1, INA, DETA, INVA, SOLVE, HELP, QUIT, UNKWN};

double getDet(matrix *matr); /* matrix.c - warum denn jetzt double? int war da, um den 
													Fehlercode zu returnen, die daten kommen doch ins struct!?! */
int invert(matrix *matr); /* matrix.c - henry */
int solve(matrix *matr); /* lgs.c - jan */
int printVector(matrix *matr); /*lgs.c - jan */

matrix *identMat(unsigned int order);

int getopt(matrix *); /* io.c - jannik */

/* tools.c */
matrix *allocMat(unsigned int row, unsigned int col);
void freeMat(matrix *matr);
void printMat(matrix *matr);
