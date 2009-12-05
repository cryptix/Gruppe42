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
	int found = 0;
	int i;
	int dist[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	char *in;
	
	/* wird noch dynamisch */
	if((pi = (char *) malloc(sizeof(char) * NMAX)) == NULL) {
		fprintf(stderr, "Error: Couldn't allocate memory for π.\n");
		exit(-1);
	}
	if((in = (char *) malloc(sizeof(char) * INMAX)) == NULL) {
		fprintf(stderr, "Error: Couldn't allocate memory for π.\n");
		exit(-1);
	}
	strcpy(pi,"14159265");	
	piLen = strlen(pi);
	
	
	usage();
	
	while(mopt = getopt(in)) {
		switch(mopt) {
			case DIGCNT:
				if(piLen = atoi(in)) {
					printf("digcnt: %d\n",piLen);
				} else {
					printf("invalid input\n");
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
				printf("π ≈ 3.%s\n", pi);
				break;
			case SEARCH:
				if((found = searchpi(in)) == -1) {
					printf("Konnte '%s' in den ersten %d Stellen von PI nicht finden\n", in, piLen);
				} else {
					printf("Konnte '%s' an der  %den Stelle finden\n", in, found);
				}	
				break;
			case DIST:
				calcdist(dist);
				printf("Ziffernverteilung:\n");
				for(i = 0; i < 10; ++i) printf("%d\t%d\n", i, dist[i]);
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