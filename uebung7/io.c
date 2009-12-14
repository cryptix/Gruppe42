#include "matrix.h"

#define BUFSIZE 64

int getNextParam(char*); /* Nächste Zeichenkette aus dem Eingabepuffer auslesen */
int setOrder(matrix*); /* Rang der Matrix festlegen */
int setValues(matrix*); /* Werte der Matrix festlegen */
int setBValues(matrix*); /* Werte des Vektors b festlegen */

int getopt(matrix *mat) { /* Eingegebene Option auslesen */
	char opt;

	opt = getchar() - '0'; /* ASCII-Umwandlung */

	if (opt == EOF) return EOF;

	if (opt < 1 || opt > QUIT) return UNKWN; /* Unbekannte Option */

	switch(opt) { /* Eingegebene Option erwartet Parameter */
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

	while ((param[0] = getchar()) == ' ' || param[0] == '\t' || param[0] == '\n'); /* Bis zum ersten Zeichen gehen */
	i = 1;

	while ((param[i] = getchar()) != ' ' && param[i] != '\t' && param[i] != '\n') { /* Zeichenkette bis zum nächsten Whitespace auslesen */
		i++;
		if(i >= BUFSIZE) return 0; /* Fehler: Buffer übeschritten */
	}
	param[i] = '\0';

	return 1;
}

int setOrder(matrix *mat) {
	char param[BUFSIZE + 1];
	int order;

	if (!getNextParam(param)) return 0; /* Parameter auslesen */

	if ((order = atol(param)) < 1) return 0;

	freeMat(mat);
	mat = allocMat(order, order); /* Neue Matrix mit eingegebenen Rang erstellen */

	return 1;
}

int setValues(matrix *mat) {
	int i;
	char param[BUFSIZE + 1];
	double value;

	for (i = 0; i < (int)(mat->row * mat->col); i++) {
		if (!getNextParam(param)) return 0; /* Für jeden der n^2 Werte einen Parameter einlesen */

		value = atof(param);

		mat->wert[i] = value;
	}

	return 1;
}

int setBValues(matrix *mat) {
	int i;
	char param[BUFSIZE + 1];
	double value;

	for (i = 0; i < (int)(mat->col); i++) {
		if (!getNextParam(param)) return 0; /* Für jeden der n Werte einen Parameter einlesen */

		value = atof(param);

		mat->vec[i] = value;
	}

	return 1;
}
