#include "pi.h"

/* calc pi to n decimal points */
int calcpi(void) {
	long int i, j;
	long int *piRow;
	long int rowLen;
	
	free(pi);
	if( (pi = (char *) malloc(sizeof(char) * piLen)) == NULL) {
		return -1;
	}

	rowLen = 10 * pilen / 3 +1; 
	if( (piRow = (long int *) malloc(sizeof(long int) * rowLen)) == NULL) {
		return -1;
	}

	for (i = 0; i < rowLen; i++) {
		piRow[i] = 2;
	}

	for (i = 0; i < piLen; i++) {

		j = rowLen - 1;
		piRow[j] *= 10;
		for (; j > 0; j--) {
			piRow[j-1] *= 10;
			piRow[j-1] += j * (piRow[j] / (2 * j + 1));
			piRow[j] %= 2 * j + 1;
		}

		pi[i] = piRow[0] / 10 + 48;
		piRow[0] %= 10;

		j = i;
		while (pi[j] == 58) {
			pi[j] = 48;
			pi[j-1] += 1;
			j--;
		}
	}

	free(piRow);

	return 0;
}

