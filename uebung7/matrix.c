#include "matrix.h"

typedef struct{
	int koeff;
	matrix matr;
} subDet;

int getSubDet(matrix *matr, int reihe, int spalte, subDet* ret);

int determ(matrix *matr){
	matrix* foo = allocMat(3,3);
	//foo->werte={1,2,3,4,5,6,7,8,10};
	matrix* subdet = allocMat(2,2);
}

int getSubDet(matrix *matr, int reihe, int spalte, subDet* ret){
	int i,I,j,J;

	if(matr->col != matr->row) return -1;
	if(ret->matr.col != ret->matr.row) return -2;
	if(matr->col != ret->matr.row) return -3;

	for(i=I=1; i<=matr->row; i++){
		if(i==reihe) continue; 
		for(j=J=1; j<=matr->col;j++){
			if(j==spalte) continue;
			ret->matr.wert[I*ret->matr.col + J] = matr->wert[i*matr->col + j];
		}
	}

	return 0;
}

/* Einheitsmatrix erstellen */
matrix *identMat(unsigned int order) {
	unsigned int i;
	matrix *ptr;

	ptr=allocMat(order, order);
	if(ptr == NULL) return NULL;

	for(i = 0; i < order; i++)
		ptr->wert[order * i + i] = 1.0;

	return ptr;
}

