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

int main(void) {
	int mopt; /* menu option */
	int picnt = 42; /* number of digits do calculate */
	int found = 0;
	int i;
	float avg = 0;
	int dist[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	char *pi, *in;
	
	/* wird noch dynamisch */
	if((pi = (char *) malloc(sizeof(char) * NMAX)) == NULL) {
		fprintf(stderr, "Error: Couldn't allocate memory for π.\n");
		exit(-1);
	}
	if((in = (char *) malloc(sizeof(char) * INMAX)) == NULL) {
		fprintf(stderr, "Error: Couldn't allocate memory for user input.\n");
		exit(-2);
	}
	
	strcpy(pi,"14159265");	
	
	usage();
	
	while(mopt = getopt(in)) {
		switch(mopt) {
			case DIGCNT:
				if(picnt = atoi(in)) {
					printf("digcnt: %d\n",picnt);
				} else {
					printf("invalid input\n");
				}
				break;
			case CALC:
				if(calcpi(pi, picnt) == 0) {
					printf("calculated pi to the %dth decimal point\n", picnt);
				} else {
					printf("something went worng (?)\n");
				}
				break;
			case PRINT:
				printf("printing pi: 3.%s\n", pi);
				break;
			case SEARCH:
				/* check in first */
			 	printf("search digits: %s\n", in);
				if((found = searchpi(pi, in)) == -1) {
					printf("couldnt find pi in the first %d digits\n", picnt);
				} else {
					printf("found pi at %d\n", found);
				}
				break;
			case DIST:
				printf("Ziffernverteilung:\n");
				
				calcdist(pi, dist);
				
				for(i = 0; i < 10; ++i)
					printf("%d:%d\n", i, dist[i]);
					
				break;
			case AVG:
				avg = calcavg(pi);
				printf("avg of pi: %f\n", avg);
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