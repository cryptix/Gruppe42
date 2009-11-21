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
	double pi = 0, piPre;
	int i = 0;
	
	do {
		piPre = pi; /* Vorherigen Wert für die Abbruchsbedingung speichern */
		pi += ((i%2 == 0) ? 1 : -1) * (pow(2, -2*i-1)+pow(3, -2*i-1)) / (2*i+1); /* Zusammengafesster Summand der Summenformel wird jeweils addiert */
		
		i++;
	} while (piPre != pi); /* Wenn sich der Wert nicht mehr ändert, ist die bestmögliche Präzision erreicht */
	
	printf("Algorithmus1:\ni:\t%d\npi:\t%.50f\n\n", i, 4*pi); /* Da der Algorihmus anders in der Aufgabenstellung beschrieben nur pi/4 annähert wird der Wert mal 4 genommen */
	
	i = 0;
	pi = 0;
	/* Analoges Verfahren für den zweiten Algorithmus */
	do {
		piPre = pi;
		pi += (1 << (2*i)) * fac(i)*fac(i) / fac(2*i+1)*(5*pow(1/7.0, 2*i+1)/pow(50/49.0, i+1) + 2*pow(3/79.0, 2*i+1)/pow(6250/6241.0, i+1));
		
		i++;
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

