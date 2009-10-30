/* Rechnet den Rest von Eingabe A und B ohne Modulo Operator
 *
 * Gruppe 42:
 * - Henry Bubert	   
 * - Jannik Thei�	 
 * - Jan Winkelmann
 */
#include <stdio.h>
#include <stdlib.h>

int modulo(int a, int b);

int main(int argc, char *argv[]) {
	int a, b;
	
	if(argc < 3) {
		fprintf(stderr, "Usage: %s <a> <b>\n", argv[0]);
		return -1;
	}
	
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	
	if (a == 0 || b == 0) {
		fprintf(stderr, "Bitte Werte ungleich 0 eingeben.\n");
		return -2;
	}
	
	printf("Eingabe:\t%d %d\n",a, b);
	printf("modulo():\t%d\n", modulo(a,b));
	printf("debug:\t\t%d\n",a%b);
	
	return 0;
}

int modulo(int a, int b) {
	int m;
	
	m = a - (a/b)*b;
	
	return m < 0 ? -1 * m : m;
}