#include "pi.h"

/* calc pi to n decimal points */
int calcpi(void) {
	long int i, j;
	long int *pirow;

	if( (pi = (char *) malloc(sizeof(char) * piLen)) == NULL) {
		return -1;
	}

	if( (pirow = (long int *) malloc(sizeof(long int) * (10 * piLen / 3 + 1))) == NULL) {
		return -1;
	}

	for (i = 0; i < (10 * piLen / 3 + 1); i++) {
		pirow[i] = 2;
	}

	for (i = 0; i < piLen; i++) {

		j = 10 * piLen / 3;
		pirow[j] *= 10;
		for (; j > 0; j--) {
			pirow[j-1] *= 10;
			pirow[j-1] += j * (pirow[j] / (2 * j + 1));
			pirow[j] %= 2 * j + 1;
		}

		pi[i] = pirow[0] / 10 + 48;
		pirow[0] %= 10;

		j = i;
		while (pi[j] == 58) {
			pi[j] = 48;
			pi[j-1] += 1;
			j--;
		}
	}

	return 0;
}

