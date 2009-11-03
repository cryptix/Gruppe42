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
    printf("\nshort int\n\tmin:%d\n\tmax:%d\n", SHRT_MIN, SHRT_MAX);
    printf("\nlong int\n\tmin:%ld\n\tmax:%ld\n", LONG_MIN, LONG_MAX);
    printf("\nunsigned short int\n\tmin:%d\n\tmax:%u\n", 0, USHRT_MAX);
    printf("\nunsigned long int\n\tmin:%d\n\tmax:%lu\n", 0, ULONG_MAX);

    return 0;
}
