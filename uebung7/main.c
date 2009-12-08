#include "matrix.h"

void usage(void){
	printf("(1) Ordnung n festlegen\n");
	printf("(2) Matrix A eingeben\n");
	printf("(3) det(A) berechnen\n");
	printf("(4) A invertieren\n");
	printf("(5) Ein LGS Ax=b lösen\n");
	printf("(6) Gibt diese Hilfe aus.\n");
	printf("(7) Programm beenden\n");
}

int main(void) {
	int mopt; /* menu option */
	
	usage();
	
	while((mopt = getopt(in)) != EOF) {
		switch(mopt) {
			case ORDER:
				printf("Order of Matrix: %lu\n", 42);
				break;
			case INA:
				printf("Input Matrix:\n");
				break;
			case DETA:
				printf("det(A):\n");
				break;
			case INVA:
				printf("A inverted:\n");	
				break;
			case SOLVE:
				printf("for Ax=b, x=%s");
				break;
			case HELP:
				usage();
				break;
			case QUIT:
				exit(0);
				break;
		}
	}
	
	return 0;
}

