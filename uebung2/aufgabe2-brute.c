#include <stdio.h>

#define SIZE 3

enum { MAX, CUR, MIN };

int main(int argc, char *argv[]) {
    short int sInt[SIZE];
    long  int lInt[SIZE];
    unsigned short int usInt[SIZE];
    unsigned long  int ulInt[SIZE];

    /* Solange hoch zaehlen bis die Graenze erreicht wird und wir im Negativen sind */
    for(sInt[CUR] = 0; sInt[CUR] >= 0; sInt[CUR]++);
    sInt[MIN] = sInt[CUR];

    /* Das ganze nur umgekehrt */
    for(sInt[CUR] = 0; sInt[CUR] <= 0; sInt[CUR]--);
    sInt[MAX] = sInt[CUR];

    printf("short int\n\n min:%d\tmax:%d\n", sInt[MIN], sInt[MAX]);

    /* Analog dazu mit long int */
    for(lInt[CUR] = 0; lInt[CUR] >= 0; lInt[CUR]++);
    lInt[MIN] = lInt[CUR];
    for(lInt[CUR] = 0; lInt[CUR] <= 0; lInt[CUR]--);
    lInt[MAX] = lInt[CUR];
    printf("long int\n\n min:%ld\tmax:%ld\n", lInt[MIN], lInt[MAX]);
           
    /* unsigned ints bewegen sich von 0 bis MAX
     * daher ist die grenze bei 0 - 1
     */
    usInt[MIN] = 0;
    usInt[MAX] = usInt[MIN]-1;
    printf("unsigned short int\n\n min:%u\tmax:%u\n", usInt[MIN], usInt[MAX]);

    /* Analog dazu mit unsigned long int */
    ulInt[MIN] = 0;
    ulInt[MAX] = ulInt[MIN]-1;
    printf("unsigned long int\n\n min:%lu\tmax:%lu\n", ulInt[MIN], ulInt[MAX]);
 
    return 0;
}
