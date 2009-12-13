#include "matrix.h"

void usage(void){
	printf("(1) <n> Ordnung n festlegen\n");
	printf("(2) <a 1,1> <a 1,2> .. <a n,n> Matrix A eingeben\n");
	printf("(3) det(A) berechnen\n");
	printf("(4) A invertieren\n");
	printf("(5) Ein LGS Ax=b lösen\n");
	printf("(6) Gibt diese Hilfe aus.\n");
	printf("(7) Programm beenden\n");
}

int main(void) {
	int mopt; /* menu option */
	matrix *mat;

	mat = allocMat(2, 2);

	printf("\n");
	usage();
	
	while((mopt = getopt(mat)) != EOF) {
		switch(mopt) {
			case ORDER:
				printf("Order of Matrix: %d\n", mat->row);
				break;
			case INA:
				printf("Input Matrix:\n");
				printMat(mat);
				break;
			case DETA:
				printf("det(A):\n");
				break;
			case INVA:
				printf("A inverted:\n");	
				break;
			case SOLVE:
				printf("for Ax=b, x=%s\n", "");
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

