/* zweierkomplement.c
 * Prozedurale Programmierung, Übungsblatt 3 - Aufgabe 4
 *
 * Gruppe 42:
 * - Henry Bubert	   
 * - Jannik Theiß	 
 * - Jan Winkelmann
 *
*/
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	short int i, j; /* Schleifenvariablen */
	short int a = 42; /* Input Dec-Numer */
	short int c = 0; /* Output Bin-Number als Dec */
	unsigned short int bitMask; /* Bitmaske zum Umwandeln von Dec nach Bin */
	unsigned short int b[16] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, bIn[16] = {0}; /* Input Bin-Number */
	
	/* Input-Handling */
	if (argc < 3) {
		fprintf(stderr, "Usage: %s <Dec-Number> <Bin-Number>\nUsing Default Dec-Number = 42 and Bin-Number = 1\n", argv[0]);
	} else {
		/* Input Dec-Number */
		a = atoi(argv[1]);
		
		/* Input Bin-Number */
		for (i = 0; argv[2][i] != 0; i++) {
			bIn[i] = (argv[2][i] == 48) ? 0 : 1;
		}
		/* Bits sortieren */
		for (j = 0; j < i; j++) {
			b[j] = bIn[i - j - 1];
		}
	}
	
	/* Prüfen ob die einzelnen Bits des Integers gesetzt sind */
	for (bitMask = 0x8000; bitMask > 0; bitMask >>= 1) {
		printf("%d", (a & bitMask) != 0);
	}
	
	printf("\n");
	
	/* Angefangen bei dem höchstwertigen Bit die Bits der Bin-Number einzeln dem Output-Integer hinzufügen
	 und die Bits daraufhin jeweils um eine Stelle verschieben, bis alle an der richtigen Stelle sind */
	for (i = 15; i >= 0; i--) {
		c <<= 1;
		c |= b[i];
	}
	
	printf("%d\n", c);
	
	return 0;
}