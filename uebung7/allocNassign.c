#include "matrix.h"
/*
 * anstatt
 * [][][]
 * [][][]
 * [][][]
 * zu allozieren, was mat.row + 1 malloc() calls braucht.
 *
 * koennen wir auch
 * [][][][][][][][][]
 * allozieren, unt mit [mat.row * curRow + curCol] drauf zugreifen
 */

int main(void) {
	matrix mat;
	int i, j;

	mat.row=3;
	mat.col=3;
	mat.wert = (double *) malloc(sizeof(double) * mat.row * mat.col);
	if(mat.wert == NULL) {
		fprintf(stderr, "Couldnt Alloc\n");
		return -1;
	}

	for(i=0; i < mat.col; i++) {
		for(j=0; j < mat.row; j++) {
			mat.wert[mat.row * i + j] = 1.25;
		}
	}


	for(i=0; i < mat.col; i++) {
		for(j=0; j < mat.row; j++) {
			printf("  %3.2f  ",mat.wert[mat.row * i + j]);
		}
		printf("\n");
	}

	return 0;
}
