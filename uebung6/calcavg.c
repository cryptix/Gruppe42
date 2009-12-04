#include "pi.h"

float calcavg(char *pi) {
	float sum;
	int i;
	
	sum += 3;
	for(i = 0; pi[i]; sum += pi[i++]-48);
		
	sum /= i;
	
	return sum;
}