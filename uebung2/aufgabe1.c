#include <stdio.h>

int main(int argc, char *argv[]) {
    long int x=0;        /* Der aktuelle Wert X_k */
    long int k=0;        /* Der aktuelle Index von X_k */

    if(argc < 2) {
        fprintf(stderr, "Usage: %s <Startindex>\nUsing Default X_0 = 27\n", argv[0]);
        x = 10;
    } else {
        x = atol(argv[1]);
        if(x == 0) {
            fprintf(stderr, "Couldn't parse input or input is zero\n");
            return -1;
        }
    }

    while(x > 1) {
        if(x%2 == 0)
            x = x / 2;
        else 
            x = 3 * x + 1;

        printf("k:%d\tx:%d\n",k, x);
        k++;
    }


    return 0;
}
