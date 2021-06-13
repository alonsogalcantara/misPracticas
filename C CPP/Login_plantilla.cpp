#include <iostream>
#include <string>
#include <stdio.h>
//#include <conio.h>
using namespace std;
void login ();
#define ALONSO "Alonso"
#define PASSA "1234"
//Salida
int exit(){
	return 0;
}
//Main
int main(){
	login();
	return 0;
}

//Menu
void menuLogin(){
	int opc;
	int a,suma,aux=0;
	do{
		system("cls");
		cout<<"\n0.- Para salir\n";
		cout<<"1.- Cambiar de usuario\n";
		cout<<"2.- Ir al menu principal\n";
		cin>>opc;
		//if(opc == 0)exit();
		switch(opc){
			case 0:
				cout<<"\nSaliendo...\n";
				break;
			case 1:
				login();
				break;

			case 2:
				aux = 0;
				cout<<"===Suma===\n\n";
				cout<<"Numeros a sumar: ";cin>>a;
				for(int i = 1;i <= a;i++){
					cout<<"["<<i<<"]"; cin>>suma;
					aux += suma;
				}
				cout<<"\n"<<aux<<"\n\n";
				system("pause");
				break;

			default:
				cout<<"Opcion no valida\n";
				system("pause");
				break;
			}
	}while(opc != 0);
}

//Iniciar sesion
void login (){
	string user, password;
	bool ingresar=false;
	int sigma = 0;
	char punto;
	do{
		system("cls");
		if(sigma==1)cout<<"Segundo intento\n";
		else if(sigma==2)cout<<"Tercer y ultimo intento intento\n";

		cout<<"Usuario:\t"; cin>>user;
		cout<<"Contrasenia:\t--> "; cin>>password;
		if((user == ALONSO && password == PASSA)){
			ingresar = true;
		}else{
			cout<<"\nUsuario o contrase�a incorrecta vuelve a intentar\n";
			ingresar = false;
			sigma++;
			password ="";
			system("pause");
		}
	}while(ingresar == false && sigma < 3);
		if(ingresar == false){
			cout<<"\nLimite de intentos revasado\n";
			exit();
		}else{
			system("color 10");
			system("cls");
			cout<<"\nBienvenido "<<user<<"\n\n";
			system("pause");
			system("color 01");
			menuLogin();
		}
}
