#include "matrix.h"

void printMat(matrix *mat) {
	unsigned int i, j;
	
	for(i=0; i < mat->col; i++) {
		for(j=0; j < mat->row; j++) {
			printf("  %3.2f  ", mat->wert[mat->row * i + j]);
		}
		printf("\n");
	}

	return 0;
}
