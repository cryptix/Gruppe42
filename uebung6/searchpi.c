#include "pi.h"

int searchpi(char *num) {
	int i, ret=-1, numLen = strlen(num);

	for(i=0;i < piLen; i++) {
		if(strncmp(pi+i,num, numLen) == 0) ret = i;
	}

	return ret;
}
