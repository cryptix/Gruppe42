#include "matrix.h"

double getSubDet(double*, int);

double getDet(matrix *mat) {
	return getSubDet(mat->wert, mat->col);
}

double getSubDet(double *vals, int order) {
	int subOrder = order - 1;
	double *subVals;
	double subDet = 0;
	int i, j, off;

	if (order == 1) return *vals;

	if ((subVals = (double *) malloc(sizeof(double) * subOrder * subOrder)) == NULL) {
		fprintf(stderr, "Couldn't allocate memory.\n");
	}

	for (i = 0; i < order; i++) {
		off = 0;
		for (j = 0; j < order * subOrder; j++) {
			if ((j - i) % order != 0) {
				subVals[j - off] = vals[order + j];
			} else {
				off++;
			}
		}
		subDet += ((i % 2 == 0) ? 1 : -1) * vals[i] * getSubDet(subVals, subOrder);
	}

	return subDet;
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

