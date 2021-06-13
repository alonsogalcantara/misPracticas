#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	float suma,noap,prom,porcen;
	int i,nin;
	
	for(i=0;i<=3;i++){
		printf("Ingresa la calificacion[%d]:",i+1);
		scanf("%d",&nin);
		suma=i*suma;
		prom=suma/20;
		noap=(i<=5.9);
		porcen=(noap*10)/20;
	}
	printf("La suma es: %.1f",suma);
	printf("\n");
	printf("El promedio es: %.1f",prom);
	printf("\n");
	printf("%.1f son los que no pasaron",noap);
	printf("\n");
	printf("El procentaje es de %.1f de reprobados",porcen);
	/*int opc,mm,celsi;
	float cm=0,mts=0,inch=0, pies=0,faren=0;

	do{
		printf("---Menu---");
		printf("\n");
		printf("1- Convertidor");
		printf("\n");
		printf("2.- Temperatura");
		printf("\n");
		printf(" 0 para salir");
		scanf("%d",&opc);
		switch(opc){
	case 1:
		printf("Inserte el valo en milimetros: ");
		scanf("%d",&mm);
		cm=0.10*mm;
		mts=0.100*cm;
		inch=cm*2.54;
		pies=cm*30.78;
		printf("\n");
		printf("El valor en metros es: %.1f",mts);
		printf("\n");
		printf("El valor en pulgadas es: %.1f",inch);
		printf("\n");
		printf("El valor en pies es: %.1f",pies);
		printf("\n");
		break;
	case 2:
		printf("Inserte el valo en celsius");
		scanf("%d",&celsi);
		faren=(celsi*9/5)+32;
		printf("\n");
		printf("El valor en farenheit es: %.1f",faren);
		printf("\n");
		break;
		}
		printf("\n");
	}
	while(opc!=0);*/
}
