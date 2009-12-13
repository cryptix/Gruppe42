#include "matrix.h"

void printMat(matrix *mat) {
	unsigned int i, j;
	
	printf("Matrix: %d x %d\n", mat->row, mat->col);

	for(i=0; i < mat->col; i++) {
		for(j=0; j < mat->row; j++) {
			printf("  %3.2f  ", mat->wert[mat->row * i + j]);
		}
		printf("\n");
	}
}

matrix *allocMat(unsigned int row, unsigned int col) {
	matrix *mat;

	mat = (matrix *) malloc(sizeof(matrix));
	if(mat == NULL) {
		fprintf(stderr, "Error 1: Couldn't allocate memory for matrix.\n");
		return NULL;
	}

	mat->wert = (double *) malloc(sizeof(double) * row * col);
	if(mat->wert == NULL) {
		free(mat); /* free struct space */
		fprintf(stderr, "Error 2: Couldn't allocate memory for values.\n");
		return NULL;
	}

	mat->row = row;
	mat->col = col;

	return mat;
}

void freeMat(matrix *ptr) {
	free(ptr->wert);
	ptr->wert = NULL;
	free(ptr);
	ptr = NULL;
}
