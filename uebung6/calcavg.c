#include "pi.h"

float calcavg(void) {
	float sum = 0;
	int i;
	
	for(i = 0; pi[i]; i++) sum += pi[i]-'0';

	sum /= i;
	
	return sum;
}
