#include <stdio.h>
#include <stdlib.h>

#define NMAX  100000
#define INMAX 10000

enum { DIGCNT=1, CALC, PRINT, SEARCH, DIST, AVG, HELP, QUIT, UNKWN};

/* working functions */
int calcpi(char *pi, int n);
int searchpi(char *pi, int num);
int calcavg(char *pi);
int calcdist(char *pi);

/* menu handling */
int getopt(char *);
int getch(void);
void ungetch(int);


