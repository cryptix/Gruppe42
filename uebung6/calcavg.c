#include "pi.h"

float calcavg(void) {
	float sum = 3; /* we dont store 3. in pi */
	int i;
	
	for(i = 0; pi[i]; i++) sum += pi[i]-'0';

	sum /= i;
	
	return sum;
}
