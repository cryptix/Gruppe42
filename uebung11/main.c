#include <stdlib.h>

void allocMat(char **A, int n);
void freeMat(char **A, int n);

int main() {
	int n = 10;
	char **A;

	allocMat(A, n);

	completeGrahp(A, n);

	freeMat(A);

	return 0;
}

void completeGraph(char **A, int n) {
	char anyNew;
	char *new;
	int i, j, k;

	new = malloc(sizeof(char) * n);

	for (i = 0; i < n; i++) { /* alle spalten durchgehen */
		for (j = 0; j < n; j++) new[j] = A[i][j]; /* spalte in new kopieren */

		anyNew = 1;

		while (anyNew) {
			anyNew = 0;

			for (j = 0; j < n; j++) { /* new durchgehen */
				if (new[j] == 1) {
					new[j] = 0;

					for (k = 0; k < n; k++) { /* neue kanten kopieren */
						if ((A[i][k] == 0) && (A[j][k] == 1)) {
							A[i][k] = 1;
							new[k] = 1;
							anyNew = 1;
						}
					}
				}
			}
		}
	}

	free(new);
}

void allocMat(char **A, int n) {
	int i;

	A = malloc(sizeof(char *) * n);
	
	for (i = 0; i < n; i++) {
		A[i] = malloc(sizeof(char) * n);
	}
}

void freeMat(char **A, int n) {
	int i;

	for (i = 0; i < n; i++) {
		free(A[i]);
	}

	free[A];
}
