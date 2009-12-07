#include<stdio.h>
#include<stdlib.h>

struct Matrix{
	int ordnung, **wert;
};
typedef struct Matrix matrix;

int determ(matrix *matr);
int solve(matrix *matr);
int defordnung(matrix *matr, int ordnung);
int wertegeben(matrix *matr);


