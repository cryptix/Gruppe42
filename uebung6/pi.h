#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX  100000
#define INMAX 10000

enum { DIGCNT=1, CALC, PRINT, SEARCH, DIST, AVG, HELP, QUIT, UNKWN};

extern char *pi;
extern int piLen;

/* working functions */
int calcpi(void);
int searchpi(char *num);
float calcavg(void);
int* calcdist(void);


/* menu handling */
int getopt(char *);
int getch(void);
void ungetch(int);


