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
	short int a = -5, c = 0;
	unsigned short int bitMask;
	unsigned int b[16] = {0,1,0,1,1,1,0,1,1,1,1,1,0,1,1,0};
	int i;
	
	for (bitMask = 0x8000; bitMask > 0; bitMask >>= 1) {
		printf("%d", (a & bitMask) != 0);
	}
	
	printf("\n");
	
	for (i = 0; i < 16; i++) {
		c <<= 1;
		c |= b[i];
	}
	
	printf("%d\n", c);
	
	return 0;
}