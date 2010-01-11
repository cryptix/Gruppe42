#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int strLenSum = 0;
	int i;
	char *concated;
	
	for(i=1; i<argc; i++)
		strLenSum += strlen(argv[i]);
	
	printf("strlen:%d\n",strLenSum);
	
	concated = (char *) malloc(strLenSum * sizeof(char));
	if(concated == NULL) {
		fprintf(stderr, "Error: Couldn't allocate memory\n");
		exit(1);
	}
	
	for(i=1; i< argc; i++)
		strcat(concated, argv[i]);
	
	printf("concated: %s\n", concated);
	
	free(concated);

	return 0;
}