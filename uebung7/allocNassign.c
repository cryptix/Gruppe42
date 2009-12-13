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
 * allozieren, und mit [mat.row * curRow + curCol] drauf zugreifen
 */

int main(void) {
	matrix *mat;
	int i, j;

	mat = allocMat(10,25);
	if(mat == NULL) return -1;

	for(i=0; i < mat->row; i++) {
		for(j=0; j < mat->col; j++) {
			mat->wert[mat->row * j + i] = i*j+j;
		}
	}

	printMat(mat);

	freeMat(mat);

	return 0;
}
