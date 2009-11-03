/*
 * Gewusst Wo.
 */

#include <stdio.h>
#include <limits.h>

int main(void) {

    printf("\nshort int\n\tmin:%d\n\tmax:%d\n", SHRT_MIN, SHRT_MAX);
    printf("\nlong int\n\tmin:%ld\n\tmax:%ld\n", LONG_MIN, LONG_MAX);

    printf("\nunsigned short int\n\tmin:%u\n\tmax:%u\n", 0, USHRT_MAX);
    printf("\nunsigned long int\n\tmin:%lu\n\tmax:%lu\n", 0, ULONG_MAX);

    return 0;
}
