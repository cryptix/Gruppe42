#include "pi.h"

int calcdist(char *pi, int dist[]) {
	dist[3] = 1;
	
	for(; *pi; pi++) {
		dist[(*pi)-48]++;
	}
	return 0;
}