#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int Validar_num (char Ingresa_el_valor_en_char[10]) {
   int a, cont = 0;
   char aux[1];
   strncpy(aux,Ingresa_el_valor_en_char,1);
   do{
		system("cls");
		if(cont > 0){//Cada que se introdusca un numero grande, mandara mensaje de error
			cout<<"\nIngresa un numero valido\n\n";
			system("pause");
			system("cls");
		}
		a = atoi(aux);
		cont++;
	}while(a > 9999 || a <= 0);
		cout<<"El numero introducido fue: "<<a;
}

int main(){
	char a[10];
	cout<<"Ingresa el numero\n--> ";
	cin>>a;
	Validar_num(a);
	return 0;
}
