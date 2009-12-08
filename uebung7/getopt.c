#include "pi.h"

#define BUFSIZE 100
static char buf[BUFSIZE];	/* buffer for ungetch */
static int bufp = 0;		/* next free position in buf */

static int getch(void);
static void ungetch(int);

int getopt(char *s) {
	int i, c, opt;
	
	while((s[0] = c = getch()) == ' ' || c == '\t'); /* skip whitespaces */
	s[1]='\0'; /* just in case */

	if(c == EOF) return EOF;

	opt = s[0] - '0';

	/* no menu point */
	if(opt < 1 || opt > 8) return UNKWN;
	
	switch(opt) {
		case 1:
		case 4:
			while((c = getch()) == ' ' || c == '\t'); /* skip whitespaces */
			ungetch(c); /* last c was no whitespace, give it back */

			i=0;
			if(isdigit(c))
				while(isdigit(s[i++] = getch()) && i < INMAX);
			s[(i!=0) ? i-1 : 0] = '\0'; /* replace newline */
		default:
			return opt;
			break;
	}
}

/* get a (possibly pushed-back) character */
static int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
static void ungetch(int c) {
	if(bufp >= BUFSIZE)
		fprintf(stderr, "ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
