/* aufgabe1.c
 * Prozedurale Programmierung, Übungsblatt 2 - Aufgabe 1 
 *
 * Gruppe 42:
 * - Henry Bubert	   
 * - Jannik Theiß	 
 * - Jan Winkelmann
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    long int x;		/* Der aktuelle Wert X_k */
    long int k=0;	/* Der aktuelle Index von X_k */

	/* Optionales Argument für X_0 */
    if(argc < 2) {
        fprintf(stderr, "Usage: %s <Startindex>\nUsing Default X_0 = 27\n", argv[0]);
        x = 27;
    } else {
        x = atol(argv[1]);
		/* X_0 = 0 ist kein möglicher Startwert,
		 da die Folge dann gegen 0 konvergiert! */
        if(x < 1) {
            fprintf(stderr, "Couldn't parse input or input is < 1\n");
            return -1;
        }
    }
	
	/* Startwert X_0 ausgeben */
	printf("k:%ld\tx:%ld\n", k++, x);
	
	/* Wenn die Folge den Wert 1 erreicht hat,
	 waren die vorherigen Werte 2 und 4 (außer der X_0 = 2),
	 da kein ganzzahliges, positives x mit 1 = 3x + 1 oder 2 = 3x + 1 existiert.
	 Somit wurden die periodischen Werte genau einmal durchlaufen. */
    while(x != 1) {
        /* Fallunterscheidung und Berechnung von X_k+1 */
        x = x%2 == 1 ? 3 * x + 1: x / 2;
		
		/* Ausgabe und Inkrementierung von k und x */
        printf("k:%ld\tx:%ld\n", k++, x);
    }

    return 0;
}
