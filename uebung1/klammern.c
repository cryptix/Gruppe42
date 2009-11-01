/* klammern.c
 * Prozedurale Programmierung, Übungsblatt 1 - Aufgabe 2
 *
 * Findet heraus, bei welchen a,b,c,d,e die Terme 'perms[]' unterschiedlich sind.
 *
 * von Gruppe 42:
 *   Jannik Theiß
 *   Henry Bubert
 *   Jan Winkelmann
 *
 */

#include <time.h> 	/* fuer notRandom() */
#include <stdio.h>

#define GRENZE 3   /* Grenze als Konstante/Makro definieren */
#define PERMCNT 6  /* Anzahl der Klammerkombinationen definieren */

/* Funktions Deklarationen */
short int notRandom(int max);  
int noEquals(short int arr[]); 
void printPretty(int a,int b,int c,int d,int e, short int perms[]); 

int main(void){
	/* Deklariert a, b, c, d und e vom Typ short int,
	 * werden fuer die Klammerkombinationen deklarieren 
	 */
	short int a,b,c,d,e;

	/* Deklaration des short int Arrays 'perms', mit PERMCNT Elementen,
	 * wird fuer die Ergebnisse der Terme verwendet.
	 */
	short int perms[PERMCNT];
	
	/* Deklariert und Definiert 'treffer' vom Typ short int,
	 * wird fuer die Anzahl der unterschiedlichen Termwerte verwendet.
	 * Am Anfang noch nie, also 0
	 */
	short int treffer = 0;
	
	/* Deklariert und Definiert 'rand' vom Typ short int,
	 * wird verwendet um unterschiedliche Belegung 
	 * fuer die Variablen a bis f zu liefern.
	 */
	short int rand = notRandom(500);

	/* Die Hauptschleife wird mit a,b,c,d und e = -GRENZE initialisiert,
	 * laeuft solange a kleiner ist als die Grenze,
	 * und in jedem Durchgang wird e inkrementiert.
	 * Wenn e die Grenze erreicht, wird d inkrementiert.
	 * Wenn d die Grenze erreicht, wird c inkrementiert. usw.
	 */
	for(a=b=c=d=e=-GRENZE; a<GRENZE; e++) {
		if(e==GRENZE){ e=-GRENZE; d++; }	   
		if(c==GRENZE){ c=-GRENZE; b++; }	   
		if(d==GRENZE){ d=-GRENZE; c++; }      
		if(b==GRENZE){ b=-GRENZE; a++; }      

		/* Um zu verhindern, dass durch 0 geteilt wird */
		if(d==e || d ==0){e++; continue;} 

		/* a bis e sind zugewiesen,
		 * jetzt wird in jedem durchgang der Wert der Terme ausgerechnet 
		 * und im Array gespeichert
		 */
		perms[0] = a*b+c/d-e;
		perms[1] = (a*b+c)/d-e;
		perms[2] = (a*b+c)/(d-e);
		perms[3] = (a*(b+c))/(d-e);
		perms[4] = a*(b+c)/d-e;
        perms[5] = a*(b+c/d)-e;

		/* Dieser Block ueberprueft ob die ergebnisse sich unterscheiden
		 * und gibt eine mehr oder weniger zufaellige Kombination der Variablen aus
		 */
		if(noEquals(perms)==0 && rand == treffer++) {
			/* Saubere Ausgabe der Permutationen und der Ergebnisse */
			printPretty(a,b,c,d,e,perms); 

			/* Das Programm nach der ersten Ausgabe beenden */
			return 0;
		}
	}

	return 0;
} /* main */

/* eine mehr oder weniger zufaellige Zahl ausgeben */
short int notRandom(int max){
	int ret = (int) time(NULL)%4223;            

	while( (ret %= max) > max ); /* solange ret groesser ist als gewollt,  */
	
	return (short int) ret; /* und dann zurueckgeben */
} /* notRandom */

/* Untersucht ein Array auf gleiche Inhalte.
 * Wenn zwei gleich sind gib 1 zureuck, sonst 0.
 */
int noEquals(short int arr[]){
	int i,j;

	/* Um festzustellen ob arr[] zwei gleiche Werte enthaehllt,
	 * benutzen wir 2 verschachtelte for-Schleifen
	 * und suchen nach gleichen Werten mit unterschiedlichen Indizes.
	 */
	for(i=0; i<PERMCNT; i++){        
		for(j=0; j<PERMCNT; j++){
			/* Damit wir nicht ein Element mit sich selbst vergleichen */
			if(i==j) continue;

			/* Falls zwei gleich sind... */
			if(arr[i] == arr[j]) return 1;
		}
	}

	return 0; /* keine gleichen gefunden */
} /* noEquals */

/* gibt a, b, c, d, e und die Terme huebsch aus. */
void printPretty(int a, int b, int c, int d, int e, short int perms[]){
	/* a bis e mit ihren Werten ausgegeben */
	printf("a=%d, b=%d, c=%d, d=%d, e=%d\n\n", a, b, c, d, e); 

	/* Termpermutationen mit ihren Werten ausgeben */
	printf("a*b+c/d-e\t= %d\n",       perms[0]);      
	printf("(a*b+c)/d-e\t= %d\n",     perms[1]);
	printf("(a*b+c)/(d-e)\t= %d\n",   perms[2]);
	printf("(a*(b+c))/(d-e)\t= %d\n", perms[3]);
	printf("a*(b+c)/d-e\t= %d\n",     perms[4]);
    printf("a*(b+c/d)-e\t= %d\n",     perms[5]);
} /* printPretty */
