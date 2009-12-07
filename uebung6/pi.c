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
		fprintf(stderr, "Error: Couldn't allocate memory for Ï€.\n");
		exit(-1);
	}
	calcpi();	
	
	usage();
	
	while((mopt = getopt(in)) != EOF) {
		switch(mopt) {
			case DIGCNT:
				if((newPiLen = atoi(in)) != 0) {
					piLen = newPiLen;	
					printf("Neue Länge für PI: %d\n",piLen);
				} else {
					printf("'%s' ist keine Zahl\n", in);
				}	
				break;
			case CALC:
				if(calcpi() == 0) {
					printf("calculated pi to the %dth decimal point\n", piLen);
				} else {
					printf("some thing went worng (?)\n");
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

