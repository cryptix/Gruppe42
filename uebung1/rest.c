/* Rechnet den Rest von Eingabe A und B ohne Modulo Operator
 *
 * Gruppe 42:
 * - Henry Bubert	   
 * - Jannik Theiß	 
 * - Jan Winkelmann
 */
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	int a, b;
	
	if(argc < 3) {
		fprintf(stderr, "Usage: %s <a> <b>\n", argv[0]);
		return -1;
	}
	
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	
	if (a <= 0 || b <= 0) {
		fprintf(stderr, "Bitte Werte ungleich 0 eingeben.\n");
		return -2;
	}
	
	
	printf("Toll: %d %d\n",a, b);
	
	
	return 0;
}