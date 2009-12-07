#include "pi.h"

int strCmp(char* str1, char* str2, int* status);

int searchpi(char *num) {
	int status, i, foo;
	for(i=0;status==1;i++)
		strCmp(pi,num,&status);
	return i;
}

int strCmp(char* str1, char* str2, int* status){
	char* varstr1;
	int i;
	for(varstr1=str1;strlen(varstr1) >0; varstr1 ++)
		if(strcmp(varstr1,str2) ==0){
			*status=0;
			return ( ( (int) str1) - ( (int) varstr1) );
		}
	*status = 1;
	return -1;
}

