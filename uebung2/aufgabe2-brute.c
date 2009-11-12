/* aufgabe2-brute.c
 * Prozedurale Programmierung, Übungsblatt 2 - Aufgabe 2 
 *
 * Gruppe 42:
 * - Henry Bubert	   
 * - Jannik Theiß	 
 * - Jan Winkelmann
 */
#include <stdio.h>

#define SIZE 3

enum { MAX=0, CUR, MIN };

int main(void) {
    short int sInt[SIZE];
    long  int lInt[SIZE];
    unsigned short int usInt[SIZE];
    unsigned long  int ulInt[SIZE];
	
	/* Da die kleinste Zahl eines signed int immer -1 mal eine Potenz von 2 ist,
	 wird bei der Multiplikation mit 2 vor dem Wrap-around der kleinste Wert erreicht */
	for (sInt[CUR] = -2; sInt[CUR] < 0; sInt[CUR] *= 2) {
		sInt[MIN] = sInt[CUR];
	}
	/* Nach dem Wrap-around folgt der größte Wert */
	sInt[MAX] = sInt[MIN] - 1;
    printf("\nshort int\n\tmin:%d\n\tmax:%d\n", sInt[MIN], sInt[MAX]);
 
    /* Analog dazu mit long int */
	for (lInt[CUR] = -2; lInt[CUR] < 0; lInt[CUR] *= 2) {
		lInt[MIN] = lInt[CUR];
	}
    lInt[MAX] = lInt[MIN] - 1;
    printf("\nlong int\n\tmin:%ld\n\tmax:%ld\n", lInt[MIN], lInt[MAX]);
              
    /* unsigned ints bewegen sich von 0 bis MAX
     * daher ist die grenze bei 0 - 1
     */
    usInt[MIN] = 0;
    usInt[MAX] = usInt[MIN]-1;
    printf("\nunsigned short int\n\tmin:%u\n\tmax:%u\n", usInt[MIN], usInt[MAX]);
    
    /* Analog dazu mit unsigned long int */
    ulInt[MIN] = 0;
    ulInt[MAX] = ulInt[MIN]-1;
    printf("\nunsigned long int\n\tmin:%lu\n\tmax:%lu\n", ulInt[MIN], ulInt[MAX]);
	
    return 0;
}
