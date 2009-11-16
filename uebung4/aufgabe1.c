/* zweierkomplement.c
 * Prozedurale Programmierung, Übungsblatt 3 - Aufgabe 4
 *
 * Gruppe 42:
 * - Henry Bubert	   
 * - Jannik Theiß	 
 * - Jan Winkelmann
 *
*/
#include <stdio.h>

int main() {
	volatile float f1 = 1, f2;
	volatile double d1 = 1, d2;
	int i = 0;
	
	do {
		i--; /* Zählvariable für die Schleifendurchgänge. f1 entspricht immer 2^i
			(pro Schleifendurchgang wird f1 mit 2^-1 multipliziert) */
		f1 /= 2; /* Angefangen von 2^-1 werden immer kleinere Potenzen von 2 getestet */
		f2 = 1 + f1; /* Sobald dieser Wert 1 ist, ist der größte Wert für f1 gefunden */
	} while (f2 != 1);
	
	printf("float:\t2^%d = %.50e\n", i, f1);
	
	/* Analog dazu für double */
	i = 0;
	do {
		i--;
		d1 /= 2;
		d2 = 1 + d1;
	} while (d2 != 1);
	
	printf("double:\t2^%d = %.50e\n", i, d1);

	
	return 0;
}
