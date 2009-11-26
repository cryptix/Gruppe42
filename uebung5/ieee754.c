/* ieee754.c
 * Prozedurale Programmierung, Übungsblatt 5 - Aufgabe 1 
 *
 * Gruppe 42:
 * - Henry Bubert   
 * - Jannik Theiß
 * - Jan Winkelmann
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define B 127

#define EXPLEN 8
#define MANLEN 23


/* Typdeklaration
 * 3 Member vom Typ Char. Mehr braucht man fue 0 und 1 nicht.
 *
 * Mit typedef struct kann man statt 'struct name'
 * im weitern Code einfach 'name' schreiben.
 */
typedef struct {
	char sig;			/* Vorzeichen bit */
	char exp[EXPLEN+1];	/* Exponent */
	char man[MANLEN+1];	/* Mantisse */
} ieee754;

/* Funktions deklaration */
float ieee2dec(ieee754 *num);
void  dec2ieee(float in, ieee754 *out);
void  printieee(ieee754 *num);

int main(int argc, char *argv[]) {
	ieee754 *con;
	float in = -54.0625, con2;
	
	if(argc < 2) {
		fprintf(stderr, "usage: %s <float>\nusing default %f\n\n", argv[0], in);
	} else {
		in = strtof(argv[1], NULL);
		if(in == 0) {
			fprintf(stderr, "Error: Conversion failed. See man 2 strtof for the proper way to input numbers.\n");
			return -1;
		}
	}

	if( (con = (ieee754 *) malloc(sizeof(ieee754))) == NULL) {
		fprintf(stderr, "Error: Couldn't allocate memory on heap\n");
		return -2;
	}

	dec2ieee(in, con);
	printieee(con);
	
	con2 = ieee2dec(con);
	printf("%f\n", con2);

	return 0;
} /* main */

/* Wandelt eine Variable in ieee754 bit Darstellung
 * in float um, und gibt diese zurück
 */
float ieee2dec(ieee754 *in) {
	short int i, e, E;
	float out, mant;
	
	for (E=0,i=EXPLEN-1; i >= 0; i--)
		E += ((in->exp[i] == '1') ? 1 : 0) * 1<<(EXPLEN-1 - i);
	e = E-B;
	
	for (mant = 1, i = 0; i < MANLEN; i++)
		mant += ((in->man[i] == '1') ? 1 : 0) * 1.0/(2<<(i));
	
	/* out = s * m * 2^e */
	out = ((in->sig == '1') ? -1 : 1) * mant * (2<<(e-1));

	return out;
} /* ieee2dec */

/* Wandelt eine Variable von Float
 * in ieee754 bit darstellung um
 */
void dec2ieee(float  in, ieee754 *out) {
	short int i, e, set;
	float mant, exp, tmp;

	/* Vorzeichen Bit */
	out->sig = (in < 0) ? '1' : '0';
	in *= (in < 0) ? -1 : 1;	

	/* Exponenten Berechnung */
	if(in > 1 || in < -1)
		for(i=0, exp=1; in > exp*2; i++, exp*=2);
	else
		for(i=0, exp=1; in < exp; i--, exp/=2);


	/* Exponenten Bits */
	e = i + B;
	for(i=EXPLEN-1; i >= 0; i--, e /= 2)
		out->exp[i] = (e%2 == 0) ? '0' : '1';
	
	out->exp[EXPLEN+1] = '\0';

	/* Mantisse */
	mant = in/exp;

	/* implizit 1 */
	mant -= 1;

	/* Mantissen Bits */
	for(i=0; i <= MANLEN; i++) {

		tmp = 1.0/(2<<(i));
		set = ( mant > tmp)  ? 1 : 0;

		out->man[i] = (set==1) ? '1' : '0';

		mant -= tmp * set;
	}
	out->man[MANLEN] = '\0';

	return;
} /* dec2ieee */

/* Nimmt ein ieee754 und stellt es dar
 */
void printieee(ieee754 *in) {
	
	printf("\t| sign | exponent | mantisse\n");
	printf("\t|  %c   | %s | %s\n",in->sig, in->exp, in->man);
	printf("\n\n");

	return;
} /* printieee */
