#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX  100000
#define INMAX 10000

enum { DIGCNT=1, CALC, PRINT, SEARCH, DIST, AVG, HELP, QUIT, UNKWN};

/* working functions */
int calcpi(char *pi, int n);
int searchpi(char *pi, char *num);
float calcavg(char *pi);
int calcdist(char *pi, int dist[]);


/* menu handling */
int getopt(char *);
int getch(void);
void ungetch(int);


