/* aufgabe2a.c
 * Prozedurale Programmierung, Übungsblatt 4 - Aufgabe 2a
 *
 * Gruppe 42:
 * - Henry Bubert	   
 * - Jannik Theiß	 
 * - Jan Winkelmann
 *
*/
#include <stdio.h>
#include <math.h>

double fac(unsigned int i); /* Berechnet i! */

int main() {
	double pi = 0, piPre, dA, dB, dC, dD;
	int i = 0, iA;
	
	dA = 1.0 / 2;
	dB = 1.0 / 3;
	dC = 1;
	do {
		piPre = pi; /* Vorherigen Wert für die Abbruchsbedingung speichern */
		pi += (i%2 ? -1 : 1) * (dA+dB) / dC; /* Zusammengafesster Summand der Summenformel wird jeweils addiert */

		dA /= 4;
		dB /= 9;
		dC += 2;
		
		i++;
	} while (piPre != pi); /* Wenn sich der Wert nicht mehr ändert, ist die bestmögliche Präzision erreicht */
	
	printf("Algorithmus1:\ni:\t%d\npi:\t%.50f\n\n", i, 4*pi); /* Da der Algorihmus anders in der Aufgabenstellung beschrieben nur pi/4 annähert wird der Wert mal 4 genommen */
	
	i = 0;
	pi = 0;
	dA = 1;
	dB = 1;
	dC = 7 / 10.0;
	dD = 237 / 3125.0;
	iA = 1;
	/* Analoges Verfahren für den zweiten Algorithmus */
	do {
		piPre = pi;
		pi += iA * dA / dB * (dC + dD);
		
		i++;

		iA <<= 2; /* = 2^(2*i)*/
		dA *= i; /* dA/dB = (i!)^2/(2*i+1)!) */
		dB *= 4*i + 2;
		dC /= 50; /* = 5 * (1/7)^(2*i+1) / (1 + (1/7)^2)^(i+1) */
		dD *= 9 / 6250.0; /* = 2 * (3/79)^(2*i+1) / (1 + (3/79)^2)^(i+1) */
	} while (piPre != pi);

	printf("Algorithmus2:\ni:\t%d\npi:\t%.50f\n\n", i, 4*pi);
	
	return 0;
}

double fac(unsigned int i) {
	double o = 1;

    while(i > 1)
        o *= i--;

	return o;
}

