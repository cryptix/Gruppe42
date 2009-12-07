#include "pi.h"

unsigned int* calcdist(void) {
	unsigned int *dist;
	char *ptr = pi; /* changing pi, means changing pi in the global context */
	
	if((dist = (unsigned int *) malloc(sizeof(unsigned int) * 10)) == NULL) {
		fprintf(stderr, "Error: Couldn't allocate memory for π.\n");
		return NULL;
	}
	bzero(dist, sizeof(unsigned int)*10);
	
	for(; *ptr; ptr++) dist[(*ptr)-'0']++;
	
	return dist;
}
