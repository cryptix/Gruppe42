#include<stdio.h>
#define GRENZE 20
int main(){
	long int a,b,c,d,e,f,A,B,C,D,E,F,G,H,I,J;
	int do_break = 0;
	a=b=c=d=e=0;
	a=5;

	while(a<GRENZE){
		if(do_break>0) break;
		b=0;
		while(b<GRENZE){
			if(do_break>0) break;
			c=0;
			while(c<GRENZE){
				if(do_break>0) break;
				d=0;
				while(d<GRENZE){
					if(do_break>0) break;
					e=0;
					while(e<GRENZE){
						if(e != d && d != 0){
						printf("a: %d, b: %d, c: %d, d: %d, e: %d;\n",a,b,c,d,e);
							A = a*(b+c)/d-e;
							B = a*(b+c/d)-e;
							C = a*(b+c/d-e);
							D = a*b+(c/d-e);
							E = a*b+c/(d-e);
							F = a*b+c/d-e;
							G = (a*b+c)/d-e;
							H = (a*b+v)/(d-e);
							I = (a*(b+c))/d-e;
							J = (a*(b+c))/(d-e);

							if(A!=B && A!=C && A!=D && A!=E && A!=F //&& A!=G 
							&& B!=C && B!=D && B!=E && B!=F// && B!=G
							&& C!=D && C!=E && C!=F //&& C!=G
							&& D!=E && D!=F// && D!= G
							&& E!=F){// && E!=G
							/*&& F!=G)*/ 
								do_break=1;
								break;
							} 
						}
						e++;
					}
					d++;
				}
				c++;
			}
			b++;
		}
		a++;
	}

							
							

	printf("A: %d\n",A);
	printf("B: %d\n",B);
	printf("C: %d\n",C);
	printf("D: %d\n",D);
	printf("E: %d\n",E);
	printf("F: %d\n",F);
	printf("G: %d\n",G);
	printf("H: %d\n",H);
	printf("B: %d\n",B);
	printf("C: %d\n",C);
	printf("D: %d\n",D);
	printf("E: %d\n",E);
	printf("F: %d\n",F);
	printf("B: %d\n",B);
	printf("C: %d\n",C);
	printf("D: %d\n",D);
	printf("E: %d\n",E);
	printf("F: %d\n",F);
	return(0);
}

