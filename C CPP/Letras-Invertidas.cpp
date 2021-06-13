#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>

char letra[8],aux;
int i;

int main()
{
	printf("Introduce las letras:\n");
	i=0;
	do{
		scanf("%c",&letra[i]);
		i=i+1;
	}while(i<8);
	printf("\nLetras introducidas:\n");
	i=0;
	do{
		printf("%c  ",letra[i]);
		i=i+1;
	}while(i<8);
	printf("\n\nOrden invertido:\n");
	i=0;
	do{
		aux=letra[i];
		letra[i]=letra[7-i];
		letra[7-i]=aux;
		i=i+1;
	}while(i<4);
	i=0;
	do{
		printf("%c  ",letra[i]);
		i=i+1;
	}while(i<8);

	//Invertir de nuevo
	i=0;
	do{
		aux=letra[i];
		letra[i]=letra[7-i];
		letra[7-i]=aux;
		i=i+1;
	}while(i<4);
	printf("\n\nLetras en pocision par:\n");
	i=0;
	do{
		if((i+1)%2==0)
			printf("%c  ",letra[i]);
		i=i+1;
	}while(i<8);
	printf("\n\nLetras en posicion impar:\n");
	i=0;
	do{
		if((i+1)%2!=0)
			printf("%c  ",letra[i]);
		i=i+1;
	}while(i<8);
	printf("\n\nOrden de extremos:\n");
	i=0;
	do{
		printf("%c  ",letra[7-i]);
		printf("%c  ",letra[i]);
		i=i+1;
	}while(i<4);
	system("pause");
}
