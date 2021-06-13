#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

string uni, des, cen, mil;

int unidades(int a){
	if(a == 0)uni = "";
	if(a == 1)uni = "I";
	if(a == 2)uni = "II";
	if(a == 3)uni = "III";
	if(a == 4)uni = "IV";
	if(a == 5)uni = "V";
	if(a == 6)uni = "VI";
	if(a == 7)uni = "VII";
	if(a == 8)uni = "VIII";
	if(a == 9)uni = "IX";
	return a;
}

int descenas(int a){
	if(a == 0)des = "";
	if(a == 1)des = "X";
	if(a == 2)des = "XX";
	if(a == 3)des = "XXX";
	if(a == 4)des = "XL";
	if(a == 5)des = "L";
	if(a == 6)des = "LX";
	if(a == 7)des = "LXX";
	if(a == 8)des = "LXXX";
	if(a == 9)des = "XC";
	return a;
}

int miles(int a){
	if(a == 0)mil = "";
	if(a == 1)mil = "M";
	if(a == 2)mil = "MM";
	if(a == 3)mil = "MMM";
	return a;
}

int main(){
	//Numeros
	int a;
	//Auxiliares
	char auxa[1];
	int aux=0,cont;
	char opc[1],auxc[1];
	//Divisiones a la de ley
	int unid,desc,cent,mile;
	//system("cls");
	//system("color 0A");
	//Mensaje de bienvenida
	cout<<"\t\t\t\tConvertidor de numero arabes a romanos\n";
	cout<<"Hola!";
	cout<<"\nEste programa solo convierte numeros arabigos (Los que siempre usamos) a numeros romanos.\nsolo acepta numeros enteros, mayores a cero y menores a 4000, introduciras letras cuando se te pida.\nPorfavor haz caso ^^\n";
	//system("pause");
	do{
		//system("cls");
		//system("color 0B");
		a = 0;
		cont = 0;
		do{
			cont++;
			//system("cls");
			if(cont > 1){//Cada que se introdusca un numero grande, mandara mensaje de error
				system("color 74");
				cout<<"--> "<<auxa<<" <--"<<" \nNo es un numero/letra valido, prueba intentando de nuevo\n";
				//system("pause");
				//system("cls");
				//system("color 0B");
			}
			cout<<"Introduce un numero \n--> ";
			cin>>auxa;
			a = atoi(auxa);
		}while(a > 3999 || a <= 0);
		//Se sacan las unidades, centenas, descenas y unidades de millar
		mile = a / 1000 % 10;
		miles(mile);
		//cent = a / 100 % 10;
		//centenas(cent);
		desc = a / 10 % 10;
		descenas(desc);
		unid = a / 1 % 10;
		unidades(unid);
		cout<<"El numero en romano es: "<<mil<<cen<<des<<uni<<"\n\n";
		//system("pause");
		//system("cls");
		//Pregunta si se desea repetir
		do{
			aux = 0;
			cout<<"Repetir? Y/N\n--> ";
			cin>>opc;
			//Copia solola primera letra para que sea valido
			strncpy(auxc,opc,1);
			mile=0; cent=0; desc=0; unid=0;
			if((auxc[1] == 'y') || (auxc[1] == 'Y')){
				aux = 1;
			}else if((auxc[1] == 'n') || (auxc[1] == 'N')){
				aux = 2;
			}else{
				//system("cls");
				aux=3;
				cout<<"--> "<<opc<<" <--"<<" \nno es valido, prueba intentando de nuevo\n";
				//system("pause");
				//system("cls");
			}
		}while(aux == 3);
	}while(aux != 2);
	return 0;
}
