/* aufgabe1.c
 * Prozedurale Programmierung, Übungsblatt 2 - Aufgabe 1 
 *
 * Gruppe 42:
 * - Henry Bubert	   
 * - Jannik Theiß	 
 * - Jan Winkelmann
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    long int x=0;        /* Der aktuelle Wert X_k */
    long int k=0;        /* Der aktuelle Index von X_k */

	/* Optionales Argument für X_0 */
    if(argc < 2) {
        fprintf(stderr, "Usage: %s <Startindex>\nUsing Default X_0 = 27\n", argv[0]);
        x = 10;
    } else {
        x = atol(argv[1]);
        if(x == 0) {
            fprintf(stderr, "Couldn't parse input or input is zero\n");
            return -1;
        }
    }

	/* Folge konvergiert gegen 1 */
    while(x > 1) {
		/* Fallunterscheidung und Berechnung von X_k+1 */
		x = x%2 == 1 ? 
				3 * x + 1:
				x / 2;

        /* Ausgabe und Inkrementierung von k und x */
        printf("k:%ld\tx:%ld\n",k++, x);
    }


    return 0;
}
