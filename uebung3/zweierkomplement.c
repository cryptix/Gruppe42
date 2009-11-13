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
	short int i, j, a = 42, c = 0;
	unsigned short int bitMask, b[16] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, bIn[16] = {0};
	
	if (argc < 3) {
		fprintf(stderr, "Usage: %s <Dec-Number> <Bin-Number>\nUsing Default Dec-Number = 42 and Bin-Number = 1\n", argv[0]);
	} else {
		a = atoi(argv[1]);
		
		for (i = 0; argv[2][i] != 0; i++) {
			bIn[i] = (argv[2][i] == 48) ? 0 : 1;
		}
		
		for (j = 0; j < i; j++) {
			b[j] = bIn[i - j - 1];
		}
	}
	
	for (bitMask = 0x8000; bitMask > 0; bitMask >>= 1) {
		printf("%d", (a & bitMask) != 0);
	}
	
	printf("\n");
	
	for (i = 15; i >= 0; i--) {
		c <<= 1;
		c |= b[i];
	}
	
	printf("%d\n", c);
	
	return 0;
}