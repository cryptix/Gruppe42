#include "pi.h"

/* calc pi to n decimal points */
int calcpi(void) {
	int i, j;
	int *piRow; /* Reihenglieder */
	int rowLen, almostRowLen; /* Anzahl Reihenglieder */
	int a;
	
	/* Arraylängen festlegen */
	free(pi);
	if( (pi = (char *) malloc(sizeof(char) * (piLen + 1))) == NULL) {
		return -1;
	}

	rowLen = 10 * piLen / 3 + 1;
	if( (piRow = (int *) malloc(sizeof(int) * rowLen)) == NULL) {
		return -1;
	}

	/* Alle Reihenglieder mit 2 initialisieren */
	for (i = 0; i < rowLen; i++) {
		piRow[i] = 2;
	}

	/* Berechnung der Dezimalstellen von pi */
	almostRowLen = rowLen - 1;
	for (i = 0; i < piLen; i++) {

		j = almostRowLen;
		piRow[j] *= 10;
		for (; j > 0; j--) {
			piRow[j-1] *= 10; /* Jedes Reihenglied mit neuer Basis 10 multiplizieren */
			a = 2 * j + 1;
			piRow[j-1] += j * (piRow[j] / a); /* Normaliesierung der Reihenglieder */
			piRow[j] %= a;
		}

		pi[i] = piRow[0] / 10 + '0'; /* Dezimalstelle aus höchstwertigstem Reihenglied berechnen (und Umformung in ASCII-Wert) */
		piRow[0] %= 10; /* Berechnete Dezimalstelle von der Reihe subtrahieren */

		j = i; /* Mögliche unaufgelöste Überträge auflösen */
		while (pi[j] == '9' + 1) {
			pi[j] = '0';
			pi[j-1] += 1;
			j--;
		}
	}

	pi[piLen] = '\0';

	free(piRow);

	return 0;
}

