#include "matrix.h"

#define BUFSIZE 64

int getNextParam(char*);
int setOrder(matrix*);
int setValues(matrix*);
int setBValues(matrix*);

int getopt(matrix *mat) {
	char opt;

	opt = getchar() - '0';

	if (opt == EOF) return EOF;

	if (opt < 1 || opt > QUIT) return UNKWN;

	switch(opt) {
		case 1:
			if (!setOrder(mat)) return UNKWN;
			break;
		case 2:
			if (!setValues(mat)) return UNKWN;
			break;
		case 5:
			if (!setBValues(mat)) return UNKWN;
			break;
	}

	return opt;
}

int getNextParam(char *param) {
	int i = 0;

	while ((param[0] = getchar()) == ' ' || param[0] == '\t' || param[0] == '\n');
	i = 1;

	while ((param[i] = getchar()) != ' ' && param[i] != '\t' && param[i] != '\n') {
		i++;
		if(i >= BUFSIZE) return 0;
	}
	param[i] = '\0';

	return 1;
}

int setOrder(matrix *mat) {
	char param[BUFSIZE + 1];
	int order;

	if (!getNextParam(param)) return 0;

	if ((order = atol(param)) < 1) return 0;

	freeMat(mat);
	mat = allocMat(order, order);

	return 1;
}

int setValues(matrix *mat) {
	int i;
	char param[BUFSIZE + 1];
	double value;

	for (i = 0; i < (int)(mat->row * mat->col); i++) {
		if (!getNextParam(param)) return 0;

		if ((value = atof(param)) < 1) return 0;

		mat->wert[i] = value;
	}

	return 1;
}

int setBValues(matrix *mat) {
	int i;
	char param[BUFSIZE + 1];
	double value;

	for (i = 0; i < (int)(mat->col); i++) {
		if (!getNextParam(param)) return 0;

		if ((value = atof(param)) < 1) return 0;

		mat->vec[i] = value;
	}

	return 1;
}
