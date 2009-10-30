/* 
 * hallo.c
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
	
	/* Weist Variable a den Wert 22 und Variable b den Wert 20 */
	a = 22; b = 20;
	
	/* Gibt den String "Die Antwort ist: ", ein Tabulator, ein Platzhalter für ein Dezimal Wert und 2 neue Zeilen */
	printf("Die Antwort ist: \t %d \n\n", a+b);
	
	/* Gibt den Wert 0 zurück */
	return 0;
}