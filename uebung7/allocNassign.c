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
	matrix *mat;
	int i, j;

	mat = allocMat(12,12);
	if(mat == NULL) {
		fprintf(stderr, "allocation failed\n");
		return -1;
	}

	for(i=0; i < mat->col; i++) {
		for(j=0; j < mat->row; j++) {
			mat->wert[mat->row * i + j] = i*j+j;
		}
	}

	printMat(mat);

	freeMat(mat);

	return 0;
}
