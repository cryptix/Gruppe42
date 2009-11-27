#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void bin2float(float* target, char bits[]);
void intTo32Bit(int* target, int number);
void float2bin(int* target, float number);
int main(int argc, char* argv[]){
	if(argc==3){
		int i;
		if(strcmp(argv[1],"f2b")==0) {
			int target[32];
			printf("als Float: %f\n",atof(argv[2]));
			float2bin(target, atof(argv[2]));
			printf("als Bin: ");
			for(i=0; i<32; printf("%d", target[i++]));
		}
		else if(strcmp(argv[1],"b2f")==0){
			float* target = malloc(4);
			bin2float(target, argv[2]);
			printf("%10.179f", *target);
			free(target);
		}
		printf("\n");
		return 0;
	}
	return 1;
}
void bin2float(float* target, char bits[]){
	unsigned int* retint = (unsigned int*) target;
	int i;
	*retint = 0;
	for(i=0;i<32;i++){
		if(bits[31-i] == "1"[0]){
			if(i==1){
				*retint+=1; 
				continue;
			}
			*retint += 2<<(i-1);
		}
	}
	printf("als Int: %d\n",*retint);
}

void float2bin(int* target, float number){
	int* intfoo = (int*) &number;
	printf("als Int: %d\n",*intfoo);
	intTo32Bit(target, *intfoo);
}
void intTo32Bit(int* target, int number){
	int i;
	for(i=0; i<32; i++) target[i] = (number & (2<<(30-i))) ?  1:0;
}
