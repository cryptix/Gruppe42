#include "matrix.h"

int solve(matrix* mat){
	unsigned int i,j;
	double det = getDet(mat);
	if(mat->row!=mat->col) return -1;
	for(i=0; i < mat->col; i++){
		matrix *a_k;
		a_k = allocMat(mat->row, mat->col);
		

			
		for(j=0;j<(mat->row*mat->col);j++)
			a_k->wert[j] = mat->wert[j];
		
		for(j=0;j<mat->row;j++)
			a_k->wert[j*(mat->row) + i] = mat->vec[j];
		
		mat->slv_x[i] = (getDet(a_k) / det);
		free(a_k);
	}
	return 0;
}

int printVector(matrix *matr){
	unsigned i;
	printf("Bei A*x=b:\nx=");
	for(i=0;i<matr->row;i++)
		printf("\t%f\n",matr->slv_x[i]);
	
	return 0;
}
