#include "matrix.h"

static double  getSubDet(double*, int);
static matrix* getSubMat(matrix*, unsigned int, unsigned int);

double getDet(matrix *mat) {
	double foo = getSubDet(mat->wert, mat->col);
	mat->det = foo;
	return foo;
}

static double getSubDet(double *vals, int order) {
	int subOrder = order - 1;
	double *subVals;
	double subDet = 0;
	int i, j, off;

	if (order == 1) return *vals;

	if ((subVals = (double *) malloc(sizeof(double) * subOrder * subOrder)) == NULL) {
		fprintf(stderr, "Couldn't allocate memory.\n");
		return 0;
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
		subDet += ((i % 2 == 0) ? 1 : -1) * ((vals[i] == 0) ? 0 : vals[i] * getSubDet(subVals, subOrder));
	}

	free(subVals);

	return subDet;
}

/* Invertiert mat 'in place' */
int invert(matrix *mat) {
	unsigned int i, j;
	float detA = 0;
	matrix *tmp;
	double *inv;

	/* if matrix is invertible */
	if(mat->row != mat->col) return -1;
	if((detA = getDet(mat)) == 0) return -1;

	/* allocate space for inverted matrix */
	inv = (double *) malloc(sizeof(double) * mat->col * mat->col);
	if(inv == NULL) return -1;

	for(i=0; i < mat->row; i++) {
		for(j=0; j < mat->col; j++) {
			tmp = getSubMat(mat, j, i); /* strike i-col and j-row */
			inv[mat->row * j + i] = ((i+j)%2 == 0 ? 1 : -1) * getDet(tmp)/detA;
			freeMat(tmp);
		}
	}

	free(mat->wert);
	mat->wert=inv;

	return 0;
}

/* Streicht Spalte col und Zeile row
 * Gibt die resultierende Matrix zurueck
 */
static matrix *getSubMat(matrix *mat, unsigned int col, unsigned int row) {
	unsigned int i, I, j, J; /* counters */
    unsigned int order = mat->row - 1; /* mat is square */
	matrix *tmp;

	if (order == 0) return mat;

	tmp = allocMat(order, order);
	if(tmp == NULL) return NULL;


	for(i=I=0; i < mat->row; i++) {
		if(i == row) continue;
		for(j=J=0; j < mat->col; j++) {
			if(j != col) {
				tmp->wert[tmp->row * I + J] = mat->wert[mat->row * i + j];
				J++;
			}
		}
		I++;
	}

	return tmp;
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

