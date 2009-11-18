/* aufgabe2b.c
 * Prozedurale Programmierung, Übungsblatt 4 - Aufgabe 2b
 *
 * Gruppe 42:
 * - Henry Bubert	   
 * - Jannik Theiß	 
 * - Jan Winkelmann
 *
*/
#include <stdlib.h>
#include <stdio.h>

double frac1(int depth);
double frac2(int depth);
double frac1r(int depth, double a, double b);
double frac2r(int depth, double a);

int main(int argc, char *argv[]) {
	int depth = 42;
	
	/* Input-Handling */
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <depth>\nUsing Default Depth = 42\n", argv[0]);
	} else {
		depth = atol(argv[1]);
		if(depth < 1) {
			fprintf(stderr, "Couldn't parse input or input is < 1\n");
			return -1;
		}
	}

	printf("%.50f\n", 4/frac1r(depth, 1, 1));
	printf("%.50f\n", frac1(depth));/* Pi ersten Funktion und ausgeben */

	printf("%.50f\n", frac2r(depth, 1) - 3);
	printf("%.50f\n", frac2(depth));/* Pi aus der zweiten Funktion und ausgeben */
			
	return 0;
}

double frac1(int depth) {
	int i;
	double a = 1;

	for (i = depth; i > 0; i--) {
		a = 1 + 2 * (i-1) + (i * i) / a;/* Zuerst letztes Element des Kettenbruches ausrechnen und dann das jeweils übergeordnete */
	}

	return 4 / a;/* Pi aus dem angenäherten Wert errechnen */
}

double frac2(int depth) {
	int i;
	double a = 1;

	for (i = depth; i > 0; i--) {
		a = 6 + (2 * i - 1) * (2 * i - 1) / a;/* Zuerst letztes Element des Kettenbruches ausrechnen und dann das jeweils übergeordnete */
	}
	return a - 3;/* Pi aus dem angenäherten Wert errechnen */
}

double frac1r(int depth, double a, double b) {
	if (depth > 0) {/* Abbruch, wenn die maximale Rekusrionstiefe erreicht wird */
		return a + b * b / frac1r(depth - 1, a + 2, b + 1);/* Berechnung des Kettenbruchs mit rekursivem Aufruf der Funktion für jeweis den Nenner */
	} else {
		return 1;
	}
}

double frac2r(int depth, double a) {
	if (depth > 0) {/* Abbruch, wenn die maximale Rekusrionstiefe erreicht wird */
		return 6 + a * a / frac2r(depth - 1, a + 2);/* Berechnung des Kettenbruchs mit rekursivem Aufruf der Funktion für jeweis den Nenner */
	} else {
		return 1;
	}
	return depth;
}

