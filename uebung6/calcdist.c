#include "pi.h"

int* calcdist(void) {
	int *dist;
	char *ptr = pi;
	
	
	if((dist = (int *) malloc(sizeof(int) * 10)) == NULL) {
		fprintf(stderr, "Error: Couldn't allocate memory for π.\n");
		return NULL;
	}
	memset(dist, 0, 10);
	
	dist[3] = 1; /* we dont store 3. in pi */	
	for(; *ptr; ptr++) dist[(*ptr)-'0']++;
	
	return dist;
}