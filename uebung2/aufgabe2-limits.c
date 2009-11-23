/* aufgabe2-limits.c
 * Prozedurale Programmierung, Übungsblatt 2 - Aufgabe 2 
 *
 * Gruppe 42:
 * - Henry Bubert	   
 * - Jannik Theiß	 
 * - Jan Winkelmann
 */
#include <stdio.h>
#include <limits.h>

int main(void) {

	/* Auslesen der definieretn Grenzen aus limits.h */
    printf("\nshort int (%d bytes)\n\tmin:%d\n\tmax:%d\n",sizeof(short int), SHRT_MIN, SHRT_MAX);
    printf("\nlong int (%d bytes)\n\tmin:%ld\n\tmax:%ld\n",sizeof(long int), LONG_MIN, LONG_MAX);
    printf("\nunsigned short int (%d bytes)\n\tmin:%d\n\tmax:%u\n",sizeof(unsigned short int), 0, USHRT_MAX);
    printf("\nunsigned long int (%d bytes)\n\tmin:%d\n\tmax:%lu\n",sizeof(unsigned long int), 0, ULONG_MAX);

    return 0;
}
