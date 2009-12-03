#include "pi.h"


int getopt(char *s) {
	int i, c, next;
	int opt;

	
	while((s[0] = c = getch()) == ' ' || c == '\t'); /* skip whitespaces */
	s[1]='\0'; /* just in case */
	
	/* no menu point */
	opt = atoi(s);
	if(opt < 1 || opt > 8)
		return UNKWN;


	while((c = getch()) == ' ' || c == '\t'); /* skip whitespaces */
	ungetch(c); /* push back last char which isnt space or tab */
	
	if(opt == 1 || opt == 4) {
		i = 0;
		
		if(isdigit(c)) /* collect integer input */
			while(isdigit(s[i++] = c = getch()));

		s[i] = '\0';
		
		return opt;
	} else
		return opt; /* all other options dont have input */
	
	return UNKWN;
}