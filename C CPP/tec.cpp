#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main(int argc, char *argv[]) {
	//Respuestas
	char pa [] = {"susto"};//1
	char pb [] = {"rino"};//2
	char pc [] = {"sentimiento"};//3
	char pd [] = {"conde"};//4
	char pe [] = {"Interesadamente"};//5
	char pf [] = {"ubicuo"};//6
	char pg [] = {"fe"};//7
	//Guardadito
	char let[20];
	//Opciones
	int opc,opc2,opc3;
	int asqui;
	//Auxiliares
	char aux[1];
	char aux2[1];
	int auxc;
	system("color 1B");
	cout<<"\t\t\tInstrucciones\n";
	cout<<"Tendras que adivinar la palabra completa, no podras introducir letra por letra\nSolo inserta palabras no numeros";
	system("pause");
	system("cls");
	do{
		do{
			system("cls");
			cout<<"Elige una opcion a responder\n";
			cout<<"1.- Se puso muy palido le dieron un...";
			cout<<"\n2.- La segunda parte es 'ceronte', la primera es...";
			cout<<"\n3.- El amor no es un espejismo sino un...";
			cout<<"\n4.- Entre el masques y el bizconde";
			cout<<"\n5.- De manera intersada";
			cout<<"\n6.- Que esta en muchos lugares a la vez";
			cout<<"\n7.- Dicen que mueve monta�as";
			cout<<"\n0 para salir del programa";
			cout<<"\n--> ";
			cin>>aux2;
			opc = atoi(aux2);
			if(opc > 0 || opc < 8){//Cada que se introdusca un numero grande, mandara mensaje de error
				cout<<"--> "<<aux2<<" <--"<<" \nNo es un numero/letra valido, prueba intentando de nuevo\n";
				system("pause");
				system("cls");
			}
		}while(opc != 0 );
		do{
			opc3 = 0;
			switch(opc2){
			case 1:
				system("cls");
				cout<<"Se puso muy palido le dieron un...\nQ para intentar con otra\n--> ";
				cin>>let;
				if(let[1] == 'q' || let[1] == 'Q')opc3++;
				auxc = strcmp(let,pa);
				if(auxc == 0){
					cout<<"La palabra es correcta!\n "<<let;
					system("pause");
					opc3++;
				} else {
					cout<<"La palabra no es correcta...\n";
					system("pause");
				}
				break;
			case 2:
				system("cls");
				cout<<"La segunda parte es 'ceronte', la primera es...\nQ para intentar con otra\n--> ";
				cin>>let;
				if(let[1] == 'q' || let[1] == 'Q')opc3++;
				auxc = strcmp(let,pb);
				if(auxc == 0){
					cout<<"La palabra es correcta!\n "<<let<<"ceronte\n";
					system("pause");
					opc3++;
				} else {
					cout<<"La palabra no es correcta...\n";
					system("pause");
				}
				break;
			case 3:
				system("cls");
				cout<<"El amor no es un espejismo sino un...\nQ para intentatar con otra\n--> ";
				cin>>let;
				if(let[1] == 'q' || let[1] == 'Q')opc3++;
				auxc = strcmp(let,pc);
				if(auxc == 0){
					cout<<"La palabra es correcta!"<<let<<"\n";
					opc3++;
					system("pause");
				} else {
					cout<<"La palabra no es correcta...\n";
					system("pause");
				}
				break;
			case 4:
				system("cls");
				cout<<"Entre el masquez y el bizconde\nQ para intentatar con otra\n--> ";
				cin>>let;
				if(let[1] == 'q' || let[1] == 'Q')opc3++;
				auxc = strcmp(let,pd);
				if(auxc == 0){
					cout<<"La palabra es correcta!"<<let<<"\n";
					opc3++;
					system("pause");
				} else {
					cout<<"La palabra no es correcta...\n";
					system("pause");
				}
				break;

			case 5:
				system("cls");
				cout<<"De manera interezada\nQ para intentatar con otra\n--> ";
				cin>>let;
				if(let[1] == 'q' || let[1] == 'Q')opc3++;
				auxc = strcmp(let,pe);
				if(auxc == 0){
					cout<<"La palabra es correcta!"<<let<<"\n";
					opc3++;
					system("pause");
				} else {
					cout<<"La palabra no es correcta...\n";
					system("pause");
				}
				break;
			case 6:
				system("cls");
				cout<<"Que esta en muchos lugares a la vez\nQ para intentatar con otra\n--> ";
				cin>>let;
				if(let[1] == 'q' || let[1] == 'Q')opc3++;
				auxc = strcmp(let,pf);
				if(auxc == 0){
					cout<<"La palabra es correcta!"<<let<<"\n";
					opc3++;
					system("pause");
				} else {
					cout<<"La palabra no es correcta...\n";
					system("pause");
				}
				break;
			case 7:
				system("cls");
				cout<<"Dicen que mueve monta�as\nQ para intentatar con otra\n--> ";
				cin>>let;
				if(let[1] == 'q' || let[1] == 'Q')opc3++;
				auxc = strcmp(let,pg);
				if(auxc == 0){
					cout<<"La palabra es correcta!"<<let<<"\n";
					opc3++;
					system("pause");
				} else {
					cout<<"La palabra no es correcta...\n";
					system("pause");
				}
				break;
			}
			let[1] = ' ';
		}while(opc3 != 1);
	}while(opc != 0);
	return 0;
}
