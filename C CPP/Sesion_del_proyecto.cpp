//@Autor Garcia Alcantara Alonso
//@Autor Gutierrez Aguilar Andrea
//@Autor Gonzalez Amezcua Manuel
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
using namespace std;
//Weas para que no se pierdan
bool Validar_num(string numero_en_string);
void menus();
void choferLogin();
void admLogin();
void menuChofer();
void menuAdm();
//Camionero
#define ALONSO "Alonso"
#define PASSA "1234"
//Admin
#define DENIS "Denis"
#define PASSD "1234"
//Salida
int exit(){
	return 0;
}
//main
int main(){
	menus();
}
//Menu de inicio
void menus(){
	int opc;
	string linea;
	bool repite = true;
	system("cls");
	do{
		do{
			cout<<"====MENU====\n1.- Salir\n2.- Chofer\n3.- Admin\n--> ";
			getline(cin, linea);
			if(Validar_num(linea)){
				repite = false;
			} else {
				cout<<linea<<" no es valido, vuelve a intentar"<<endl;
				system("pause");
				system("cls");
			}
		}while(repite);
		opc = atoi(linea.c_str());
		linea = "";
		switch(opc){
		case 1:
			cout<<"Bye!...\n";
			break;
		case 2:
			choferLogin();
			break;
		case 3:
			admLogin();
			break;
		default:
			if(opc >= 4){
				cout<<"\nNumero grande\nintentalo otra vez";
			} else if(opc < 0){
				cout<<"\nNumero peque�o\nintentalo otra vez";
			}
			system("pause");
			system("cls");
			break;
		}
	}while(opc != 1);
}
//Menu de choferes
void menuChofer(){
	system("cls");
	int opcChofer;
	string linea = "";
	bool repite = true;
	do{
		do{
			cout<<"====MENU DE USUARIO====\n1.- Cambiar de user\n2.- Cambiar de perfil\n3.- Ver perfil\n4.- Ver rutas de hoy\n--> ";
			getline(cin, linea);
			if(Validar_num(linea)){
				repite = false;
			} else {
				cout<<linea<<" no es valido, vuelve a intentar"<<endl;
				system("pause");
				system("cls");
			}
		}while(repite);
		opcChofer = atoi(linea.c_str());
		switch(opcChofer){
		case 1://Cambiar de usuario
			cout<<"Cambiaras de perfil!\n";
			menus();
			system("pause");
			break;
		case 2://Cambiar de perfil
			cout<<"Cambiaras de usuario";
			choferLogin();
			system("pause");
			break;
		case 3://Ver perfil
			cout<<"\t\t<<Tu perfil es>>";
			cout<<"\n\nNombre\n\t--> ";
			cout<<"\n\nFecha de nacimiento\n\t--> ";
			cout<<"\n\nDireccion\n\t--> ";
			cout<<"\n\nCorreo electronico\n\t--> ";
			cout<<"\n";
			system("pause");
			system("cls");
			break;
		case 4:
			cout<<"\t\t<<Tus rutas son>>";
			cout<<"Se visualizan las rutas de hoy\n";
			cout<<"Hoy tendras 'x' ruta\n";
			system("pause");
			break;
		default:
			cout<<"Numero no valido";
			break;
		}
		system("cls");
	}while(opcChofer != 1);//Fin del ciclo general
}
//Menu de administradores
void menuAdm(){
	system("cls");
	int opcAdm;
	string linea = "";
	bool repite = true;
	do{
		do{
			cout<<"====MENU DE ADMINISTRADOR====\n1.- Cambiar de adm\n2.- Cambiar de perfil\n3.- Camiones\n4.- Choferes\n--> ";
			getline(cin, linea);
			if(Validar_num(linea)){
				repite = false;
			} else {
				cout<<linea<<" no es valido, vuelve a intentar"<<endl;
				system("pause");
				system("cls");
			}
		}while(repite);
		opcAdm = atoi(linea.c_str());
		switch(opcAdm){
		case 1://Cambiar de usuario
			cout<<"Cambiaras de perfil!\n";
			system("pause");
			admLogin();
			break;
		case 2://Cambiar de perfil
			cout<<"Cambiaras de usuario";
			system("pause");
			menus();
			break;
		case 3://Camiones
			cout<<"Ira a una de camiones\nDonde se pueda editar, agregar o eliminar";
			system("pause");
			break;
		case 4:
			cout<<"Ira a una de choferes\nDonde se pueda editar, agregar o eliminar";
			system("pause");
			break;
		default:
			cout<<"Numero no valido";
			system("pause");
			break;
		}
		system("cls");
	}while(opcAdm != 1);//Fin del ciclo general
}
//Iniciar sesion usuario
void choferLogin (){
	string user, password;
	bool ingresar=false;
	int sigma = 0;
	char punto;
	do{
		system("cls");
		cout<<"----Ususario----\n";
		if(sigma==1)cout<<"Segundo intento\n";
		else if(sigma==2)cout<<"Tercer y ultimo intento.\n";
		cout<<"Usuario: "; cin>>user;
		cout<<"Contrase�a: "; cin>>punto;
		/*punto = getch();
		while(punto != 13){
			password.push_back(punto);
			cout<<"*";
			punto = getch();
		}*/
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
		system("cls");
		cout<<"\nBienvenido "<<user<<"\n\n";
		system("pause");
		menuChofer();
	}
}
//Iniciar sesion adm
void admLogin (){
	string user, password;
	bool ingresar=false;
	int sigma = 0;
	char punto;
	do{
		system("cls");
		cout<<"----Administrador----\n";
		if(sigma==1)cout<<"Segundo intento\n";
		else if(sigma==2)cout<<"Tercer y ultimo intento intento\n";
		cout<<"Usuario: "; cin>>user;
		cout<<"Contrase�a: "; cin>>punto;
		if((user == DENIS && password == PASSD)){
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
		system("cls");
		cout<<"\nBienvenido "<<user<<"\n\n";
		system("pause");
		menuAdm();
	}
}

bool Validar_num(string numero_en_string){
	bool b = true;
	int longitud = numero_en_string.size();
	if (longitud == 0){ // Cuando el usuario pulsa ENTER
		b = false;
	} else if (longitud == 1 && !isdigit(numero_en_string[0])){
		b = false;
	} else {
		int i;
		if (numero_en_string[0] == '+' || numero_en_string[0] == '-'){
			i = 1;
		}else{
			i = 0;
		}while(i < longitud){
			if(!isdigit(numero_en_string[i])){
				b = false;
				break;
			}
			i++;
		}
	}
	return b;
}
