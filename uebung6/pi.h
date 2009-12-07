#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <errno.h>

#define NMAX  100000
#define INMAX 100000
#define PILENDEF 42

enum { DIGCNT=1, CALC, PRINT, SEARCH, DIST, AVG, HELP, QUIT, UNKWN};

extern char *pi;
extern unsigned long piLen;

/* working functions */
int calcpi(void);
unsigned long searchpi(char *num);
float calcavg(void);
unsigned int* calcdist(void);


/* menu handling */
int getopt(char *);



