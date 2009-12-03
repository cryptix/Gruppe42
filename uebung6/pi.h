#include <stdio.h>
#include <stdlib.h>

#define NMAX  100000
#define INMAX 10000

enum { DIGCNT=1, CALC, PRINT, SEARCH, DIST, AVG, HELP, QUIT, UNKWN};

int getopt(char *);
int getch(void);
void ungetch(int);


