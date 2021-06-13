#include<stdio.h>

int main(){
	int i,j;
	int array[3][3]= {2,4,6,8,10,12,14,16,18};
	for(i=0; i<=2; i++){
		printf("\n");
		for(j=0; j<=2; j++){
		printf("%d \t",array[i][j]);
		}
	}
}
