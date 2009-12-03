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

int main(void) {
	int mopt; /* menu option */
	char *pi, *in;
	
	if((pi = (char *) malloc(sizeof(char) * NMAX)) == NULL) {
		fprintf(stderr, "Error: Couldn't allocate memory for π.\n");
		exit(-1);
	}
	if((in = (char *) malloc(sizeof(char) * INMAX)) == NULL) {
		fprintf(stderr, "Error: Couldn't allocate memory for user input.\n");
		exit(-2);
	}
	
	while(mopt = getopt(in)) {
		switch(mopt) {
			case DIGCNT:
				/* check in first */
				printf("digcnt: %s\n",in);
				break;
			case CALC:
				printf("calculating new pi\n");
				break;
			case PRINT:
				printf("printing pi\n");
				break;
			case SEARCH:
				/* check in first */
			 	printf("search digits: %s\n", in);
				break;
			case DIST:
				printf("calc distribution\n");
				break;
			case AVG:
				printf("calc average\n");
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