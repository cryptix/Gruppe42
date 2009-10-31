/* Rechnet den Rest von Eingabe a und b ohne Modulo Operator
 *
 * Gruppe 42:
 * - Henry Bubert
 * - Jannik Thei§
 * - Jan Winkelmann
 */
#include <stdio.h>
#include <stdlib.h>

/* Deklaration der Funktion modulo()
 * Parameter a und b vom Typ int
 * Rueckgabe Typ: int
 */
int modulo(int a, int b); 

int main(int argc, char *argv[]) {
	int a, b;
	
    /* Sicher stellen das a und b auch eingegeben wurden, Fehlermeldung und Abbruch wenn nicht */
	if(argc < 3) {
		fprintf(stderr, "Usage: %s <a> <b>\n", argv[0]);
		return -1;
	}
	
    /* atoi() uebersetzt ASCII-Zeichenketten in Integer
     * argv[] ist das Array welches die Eingabe(n) von der Kommandozeile bereit stellt
     */
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	
    /* Ueberpruefen ob a oder b gleich Null sind, falls ja Fehlermeldung und Abbruch */
	if (a == 0 || b == 0) {
		fprintf(stderr, "Bitte Werte ungleich 0 eingeben.\n");
		return -2;
	}
	
	printf("Eingabe:\t%d %d\n",a, b);
	printf("modulo(a,b):\t%d\n", modulo(a,b));
	printf("a%%b:\t\t%d\n",a%b);
	
	return 0;
} /* main */

/* Funktionsdefinition */
int modulo(int a, int b) {
	int m; /* Variablen deklaration vom typ int */
	
    /* Rest berechnung unter Ausnutzung von Integerteilung */
	m = a - (a/b)*b;
	
    /* Rueckgabe Wert mit Betrag. Wenn m < 0 gib m * -1 aus, sonst m */
	return m < 0 ? -1 * m : m;
} /* modulo */
