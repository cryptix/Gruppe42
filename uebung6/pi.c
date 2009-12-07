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
unsigned long piLen = PILENDEF; 

int main(void) {
	int mopt; /* menu option */
	unsigned short i;
	unsigned int *dist;
	unsigned long newPiLen, found=0;
	char *in;
	time_t delta;
	
	if((in = (char *) malloc(sizeof(char) * INMAX)) == NULL) {
		fprintf(stderr, "Fehler während Speicherallozierung.\n");
		exit(-1);
	}
	calcpi();	
	
	usage();
	
	while((mopt = getopt(in)) != EOF) {
		switch(mopt) {
			case DIGCNT:
				errno = 0;
				newPiLen = strtoul(in, NULL, 10);
				if( (errno == ERANGE && newPiLen == ULONG_MAX) || (errno != 0 && newPiLen == 0) ) {
					perror("strtoul");
					piLen = PILENDEF;
					printf("Input ist keine Zahl. Benutze %lu\n", piLen);
				} else {
					piLen = newPiLen;
					printf("Neue Laenge fuer PI: %lu\n", piLen);
				}	
				break;
			case CALC:
				delta = time(NULL);
				switch(calcpi()) {
					case 0:
						delta = time(NULL)-delta;
						printf("Pi auf %lu Stellen zu bestimmen hat %lu Sekunden gedauert.\n", piLen, (unsigned long) delta);
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
					printf("Konnte '%s' in den ersten %lu Stellen von PI nicht finden\n", in, piLen);
				} else {
					printf("Konnte '%s' an der  %luen Stelle finden\n", in, found);
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
				printf("Durchschnitt der ersten %lu Stellen: %f\n", piLen, calcavg());
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

