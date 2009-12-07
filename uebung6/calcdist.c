#include "pi.h"

int* calcdist(void) {
	int *dist;
	char *ptr = pi; /* changing pi, means changing pi in the global context */
	
	if((dist = (int *) malloc(sizeof(int) * 10)) == NULL) {
		fprintf(stderr, "Error: Couldn't allocate memory for π.\n");
		return NULL;
	}
	bzero(dist, sizeof(int)*10);
	
	for(; *ptr; ptr++) dist[(*ptr)-'0']++;
	
	return dist;
}
