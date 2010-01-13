#ifndef MISC_H
#define MISC_H

#include <stdlib.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265
#endif

#define defParamCount 3

enum unitType {utVOICE = 1, utOSC};
enum unitScope {usLOCAL = 1, usGLOBAL};
enum paramType {ptFREQ = 1, ptVOL, ptPARAM1};
enum paramOption {poVAL = 1, poMOD, poRANGE};
enum boolType {btACT = 1};
enum oscType {otSIN = 1, otTRI, otREC};

extern float **gParams;
extern int gParamCount;
extern char gBools[];
extern float defParams[];

extern unsigned int sampleRate;

typedef struct {
	float *val;
	float *mod;
	float *range;
} param;


/* --- Setup --- */

void setupParam(param *);


/* --- Computing --- */

float compParam(param*);


/* Stuff */

float getFreq(int);

#endif