/* hallo.c
 * Prozedurale Programmierung, Übungsblatt 1 - Aufgabe 1 
 *
 * Gruppe 42:
 * - Henry Bubert	   
 * - Jannik Theiß	 
 * - Jan Winkelmann
 */
#include <stdio.h>

int main() {
	int a, b; /* Deklariert 2 Variablen vom Typ int */
	
	/* Gibt 2 neue Zeilen, den String "Hallo TUHH!" und nochmal 2 neue Zeilen aus */
	printf("\n\nHallo TUHH!\n\n");
	
	a = 22; b = 20; /* Weist Variable a den Wert 22 und Variable b den Wert 20 zu */
	
	/* Gibt den String "Die Antwort ist: ", einen Tabulator, einen Platzhalter für ein Dezimal Wert und 2 neue Zeilen aus */
	printf("Die Antwort ist: \t %d \n\n", a+b);
	
	return 0; /* Gibt den Wert 0 zurück */
}
