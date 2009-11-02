/* rest.c
 * Prozedurale Programmierung, Übungsblatt 1 - Aufgabe 3
 * 
 * Gruppe 42:
 * - Henry Bubert
 * - Jannik Theiß
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
	int a, b; /* Zwei Variablendeklarationen vom Typ int */
	
    /* Sicher stellen das a und b auch eingegeben wurden, Fehlermeldung und Abbruch wenn nicht */
	if(argc < 3) {
		fprintf(stderr, "Usage: %s <a> <b>\n", argv[0]);
		return -1;
	}
	
    /* atoi() übersetzt ASCII-Zeichenketten in Integer
     * argv[] ist das Array welches die Eingabe(n) von der Kommandozeile bereit hällt
     */
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	
    /* Überprüfen ob a oder b gleich Null sind, falls ja Fehlermeldung und Abbruch */
	if (a == 0 || b == 0) {
		fprintf(stderr, "Bitte Werte ungleich 0 eingeben.\n");
		return -2;
	}
	
	/* Ausgabe der Eingabe von a und b und des modulo() Funtkionsaufrufes */
	printf("modulo(%d,%d):\t%d\n", a, b, modulo(a,b));
	
	/* Ausgabe der Eingabe von a und b und der Mobuloberechnung mit Hilfe des %-Operators zur Kontrolle */
	printf("%d%%%d:\t\t%d\n", a, b, a%b);
	
	return 0;
} /* main */

/* Funktionsdefinition
 * Rechnet den Rest von a und b ohne Modulooperator
 * Gibt den Betrag des Restes zurück
 */
int modulo(int a, int b) {
	int m; /* Variablendeklaration vom Typ int */
	
    /* Restberechnung unter Ausnutzung von Integerteilung */
	m = a - (a/b)*b;
	
    /* Rückgabe von m mit Betrag. Wenn m < 0 gib m * -1 zurück, sonst m */
	return m < 0 ? -1 * m : m;
} /* modulo */
