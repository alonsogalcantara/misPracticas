#include <iostream>
#include <ctype.h>
#include <stdlib.h>

int main(){
int opc;
float cel,fah,kel;

	do{
	printf("1.- Celsius \n");
	printf("2.- Fahrenheit \n");
	printf("3.- Kelvin \n");
	printf("Ingresa la opcion:");
	printf("---> ");
	scanf("%d",&opc);
	fflush(stdin);
	if(opc!=1 && opc!=2 && opc!=3){
		printf("Ingresaste mal, vuelve a intentarlo\n");
		system("cls");
	}
}while(opc!=1 && opc!=2 && opc!=3);

if(opc == 1){
	printf("Ingresa el valor en celius: \n");
	scanf("%f",&cel);
	if(isalnum(cel));
	kel = cel+273.15;
	fah = 1.8*(kel-273.15)+32;
	printf("\n%.2f en grados Fahrenheit",fah);
	printf("\n%.2f en grados Kelvin",kel);
} else if (opc == 2){
	printf("Ingresa el valor en Fahrenheit: \n");
	scanf("%f",&fah);
	cel = (5*(fah-32))/9;
	kel = cel+273.15;
	printf("\n%.2f en grados Celsius",cel);
	printf("\n%.2f en grados Kelvin",kel);
} else if(opc == 3){
	printf("Ingresa el valor en Kelvin: \n");
	scanf("%f",&kel);
	fah = 1.8*(kel-273.15)+32;
	cel = (5*(fah-32))/9;
	printf("\n%.2f en grados Celsius",cel);
	printf("\n%.2f en grados Kelvin",fah);
}//Fin del else 3

printf("\nHasta luego");
return 0;
}//Fin del int main
