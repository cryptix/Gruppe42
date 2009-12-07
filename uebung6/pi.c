/* gcc *.c -o pi && ./pi */
#include "pi.h"


void usage(void){
	printf("(1) Anzahl der Stellen eingeben\n");
	printf("(2) PI-Stellen (neu) erzeugen\n");
	printf("(3) PI-Stellen ausgeben\n");
	printf("(4) In PI eine Zahl (<10^6) suchen\n");
	printf("(5) Ziffernverteilung in PI bestimmen\n");
	printf("(6) Mittelwert von PI-Stellen berechnen\n");
	printf("(7) Gibt diese Hilfe aus.\n");
	printf("(8) Programm beenden\n");
}

char *pi;
int piLen = 42; 

int main(void) {
	int mopt; /* menu option */
	int newPiLen, i, found = 0;
	int *dist;
	char *in;
	
	if((in = (char *) malloc(sizeof(char) * INMAX)) == NULL) {
		fprintf(stderr, "Fehler während Speicherallozierung.\n");
		exit(-1);
	}
	calcpi();	
	
	usage();
	
	while((mopt = getopt(in)) != EOF) {
		switch(mopt) {
			case DIGCNT:
				if((newPiLen = atoi(in)) != 0) {
					piLen = newPiLen;	
					printf("Neue Laenge fuer PI: %d\n",piLen);
				} else {
					printf("Input ist keine Zahl\n");
				}	
				break;
			case CALC:
				switch(calcpi()) {
					case 0:
						printf("Pi auf %d Stellen bestimmt\n", piLen);
						break;
					case -1:
						fprintf(stderr, "Fehler waehrend Speicherallozierung\n");
						break;
				}
				break;
			case PRINT:
				printf("pi = %c.%s\n", pi[0], &pi[1]);
				break;
			case SEARCH:
				if((found = searchpi(in)) == -1) {
					printf("Konnte '%s' in den ersten %d Stellen von PI nicht finden\n", in, piLen);
				} else {
					printf("Konnte '%s' an der  %den Stelle finden\n", in, found);
				}	
				break;
			case DIST:
				dist = calcdist();
				if(dist != NULL) {
					printf("Ziffernverteilung:\n");
					for(i = 0; i < 10; ++i) printf("%d\t%d\n", i, dist[i]);
					free(dist);
				} else {
					printf("something went wrong\n");
				}
				break;
			case AVG:
				printf("Durchschnitt der ersten %d Stellen: %f\n", piLen, calcavg());
				break;
			case HELP:
				usage();
				break;
			case QUIT:
				exit(0);
				break;
		}
	}
	
	free(pi);
	free(in);
	
	return 0;
}

