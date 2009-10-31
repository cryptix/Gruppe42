/* Findet heraus, bei welchen a,b,c,d,e die Terme 'perms[]' unterschiedlich sind.
*
* von Gruppe 42:
*   Jannik Theiß
*   Henry Bubert
*   Jan Winkelmann
*
*/

#include<time.h> 	/*	Die normale time() ist immer geSegFaulted */
#include<stdio.h>	/*	fuer printf. irgendwie logisch.						*/

#define GRENZE 3								// Grenze als Konstante/Makro definieren
#define ANZAHL_PERMUTATIONEN 5  // Anzahl der Klammerkombinationen definieren

/*gibt perms, a, b, c, d und e huebsch aus. */
void huebschAusgeben(int a,int b,int c,int d,int e); 
	
int main(); /* Um dem Compiler von vornherein zu sagen, welche Funktionen es gibt. 
						In diesem Fall sind das nicht so viele...*/

/* Gibt eine mehr oder weniger zufaellige Zahl zurueck */
long int notRandom(int max);  

char sindAlleAnders(); /*	Funktion, die auf der Basis von a,b,c,d,e und 
													perms herausfindet, ob alle Perms unterschiedlich 
													sind.*/

/*	Array der Permutationen global, weil andere Funktionen 
		die auch noch brauchen. Ich weiss, haesslich. */
short int perms[ANZAHL_PERMUTATIONEN]; 

int main(){
	short int treffer;		// Die Iteratoren fuer die Ueberpruefungsschleife definieren.
	short int a,b,c,d,e;	// Die fuer die Klammerkombis gebrauchten Variablen definieren
	long int rand = notRandom(500);
	treffer=0;			// Zaehlt, wie oft alle Ergebnisse unterschiedlich waren. Am Anfang noch nie, also 0

		
	/*	Die Mainloop laeuft, solange a kleiner ist als die Grenze. In jedem Durchgang wird e 
			inkrementiert. wenn e die Grenze erreicht. wird d inkrementiert, wenn d die Grenze 
			erreicht, wird c inkrementiert, usw.	*/
	for( a=b=c=d=e=-GRENZE; a<GRENZE; e++){		/*	a,b,c,d und e werden mit -GRENZE initialisiert,
																								die Schleife wird weitergefuehrt, solange a<0 ist,
																								und am ende der Schleife wird e inkrementiert.	*/
		if(e==GRENZE){e=-GRENZE;d++;}	/* Wenn e die Grenze erreicht hat, d erhoehen und e reseten */
		if(c==GRENZE){c=-GRENZE;b++;}	/* s.o. */
		if(d==GRENZE){d=-GRENZE;c++;} /* s.o. */
		if(b==GRENZE){b=-GRENZE;a++;} /* s.o. */
		if(d==e || d ==0){e++; continue;} /* Um zu verhindern, dass durch 0 geteilt wird */

		/* a bis e sind zugewiesen, jetzt wird in jedem durchgang der Wert der Terme ausgerechnet 
		und im Array gespeichert */
		perms[0] = a*b+c/d-e;
		perms[1] = (a*b+c)/d-e;
		perms[2] = (a*b+c)/(d-e);
		perms[3] = (a*(b+c))/(d-e);
		perms[4] = a*(b+c)/d-e;
		
		if(sindAlleAnders()>0){ // Falls sindAlleAnders() > 0 ist
			if(rand == treffer){ //falls die Treffernummer "ausgelost" wurde
				huebschAusgeben(a,b,c,d,e); /*Saubere Ausgabe der Permutationen und der Ergebnisse*/
				return 0; //Das Programm nach der ersten Ausgabe beenden
			}
			treffer++; //Die Treffernummer inkrementieren. Muss ja jeder eine eigene haben.
		}
	}
	return 0;
}

long int notRandom(int max){
	int ret = (int) time(NULL)%4223; //eine mehr oder weniger zufaellige Zahl erstellen
	while(ret > max){ //solange diese groesser ist als gewollt
		//ret = ret/(max/8); //kleiner machen
		ret = ret%(max);
	}
	return ret; //und dann zurueckgeben
}

char sindAlleAnders(){
	int i,j;
	char alleAnders=1; /* Wir gehen davon aus, dass bei allen Termen etwas anderes herauskommt */
	for(i=0;i<ANZAHL_PERMUTATIONEN;i++){   // Zum Vergleichen gehen wir in zwei
		for(j=0;j<ANZAHL_PERMUTATIONEN;j++){ // for-Schleifen, da wir zwei Werte vergleichen muessen.
				if(i==j) continue;	// Damit wir nicht einen Term mit sich selbst vergleichen
				if(perms[i] == perms[j]) {	//Falls dann doch mal einer gleich ist...
					alleAnders=0; // Wird zuerst alleAnders auf 0 gesetzt.

				}
		}
	}
	return alleAnders;
}
void huebschAusgeben(int a,int b,int c,int d,int e){
	//printf("Die moeglichen, mathematisch verschiedenen Kombinationen sind:\n\n");
	printf("a=%d, b=%d, c=%d, d=%d, e=%d\n\n" ,a,b,c,d,e); //a-e werden mit ihren Werten ausgegeben
	printf("a*b+c/d-e\t= %d\n", perms[0]);  //Alle Permutationen mit ihren Werten ausgeben
	printf("(a*b+c)/d-e\t= %d\n", perms[1]);
	printf("(a*b+c)/(d-e)\t= %d\n", perms[2]);
	printf("(a*(b+c))/(d-e)\t= %d\n",perms[3]);
	printf("a*(b+c)/d-e\t= %d\n",perms[4]);
	//printf("Diese sind unterschiedlich, wenn a,b,c,d und e z.B. so gewaehlt werden:\n");

	//printf("Sie sorgen naemlich fuer die oben angezeigten Ergebnisse\n");
}
