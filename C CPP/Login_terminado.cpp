#include <string>
#include <stdio.h>
#include <stdlib.h>

//Usuarios :v
#define ALONSO "Alonso"
#define PASSA "123"

using namespace std;
void login ();
void menuLogin();
void menugeneral();
//Main
int main(){
	login();
}

//Menu principal
int menu(){
	printf("\t\t\t**********Menu principal**********\n");
	printf("\t\t\t1.- Arreglos\n");
	printf("\t\t\t2.- Pilas\n");
	printf("\t\t\t3.- Colas\n");
	printf("\t\t\t0 para salir\n");
	printf("\t\t\t**********************************\n");
}
//Menu de arreglos
int menu_arreglo(){
	printf("\n\t\t\t**********Menu Arreglos**********\n");
	printf("\t\t\t1.- Unidimencional\n");
	printf("\t\t\t2.- Bidimencional\n");
	printf("\t\t\t0 para retoceder\n");
	printf("\t\t\t**********************************\n");
}
//Menu de tipos de arreglos
int menu_tipo(){
	system("color 0B");
	printf("\n\t\t\t**********Menu de tipo**********\n");
	printf("\t\t\t1.- Numeros\n");
	printf("\t\t\t2.- Letras\n");
	printf("\t\t\t0 para retroceder\n");
	printf("\t\t\t**********************************\n");
}
//Menu colas
int menu_cola(){
	system("CLS");
	system("color 0B");
    printf("\t\t\t ---Menu colas---\n");
    printf("\n\t\t\t 1.- Meter cola");
    printf("\n\t\t\t 2.- Mostrar cola");
    printf("\n\t\t\t 0 para regresar al menu principal");
}

//Salida
int exit(){
	return 0;
}

//Iniciar sesion
void login (){
	string user, password;
	bool ingresar=false;
	int sigma = 0;
	char punto;
	do{
		system("cls");
		system("color 0B");
		if(sigma==1)cout<<"Queda dos intentos\n\n";
		else if(sigma==2)cout<<"Queda un intento\n\n";

		cout<<"Usuario: "; cin>>user;
		cout<<"Contrase�a: ";
		//Para hacer el punto
		punto = getch();
	    while(punto != 13){
		password.push_back(punto);
		cout<<"*";
		punto = getch();
	}//Fin :v
		if((user == ALONSO && password == PASSA)){
			ingresar = true;
		}else{
			system("cls");
			system("color 0C");
			cout<<"\nUsuario o contrase�a incorrecta vuelve a intentar\n";
			ingresar = false;
			sigma++;
			password ="";
			system("pause");
		}
	}while(ingresar == false && sigma < 3);
		if(ingresar == false){
			system("cls");
			system("color 0E");
			cout<<"Limite de intentos revasado\n";
			exit();
		}else{
			system("cls");
			system("color 0A");
			cout<<"\nBienvenido "<<user<<"\n\n";
			system("pause");
			menuLogin();
		}
}

//Menu
void menuLogin(){
	int opc;
	int a,b,c;
	do{
		system("cls");
		system("color 06");
		cout<<"\n0.- Para salir\n";
		cout<<"1.- Cambiar de usuario\n";
		cout<<"2.- Menu principal\n";
		cin>>opc;
		if(opc == 0)exit();
		switch(opc){
			case 0:
				cout<<"Saliendo...";
				break;
			case 1:
				login();
				break;

			case 2:
				menugeneral();
				break;

			default:
				cout<<"Opcion no valida\n";
				system("pause");
				break;
			}
	}while(opc != 0);
}
//Only structs
struct nodo{
    int nro;
    struct nodo *sgte; //El apuntador
}; typedef nodo *ptrPila;
	//De la cola
	typedef struct nodoc{
  	int dato_colas;//donde se guarda el telefono
  	int dura_colas;//donde se guarda el tiempo
  	struct nodoc *sgte;//puntero siguiente
 	}nodoc;
 	long int fono;
	int tiempo;
	nodoc *act_1,*fin,*inicio_1=NULL;
//Para meter weas
void push( ptrPila &p, int valor ){
     ptrPila aux;
     aux = new(struct nodo);  //Apuntamos al nuevo nodo creado
     aux->nro = valor;
     aux->sgte = p ;
     p = aux ;
}
//Sacar weas
int pop( ptrPila &p ){
     int num;
     ptrPila aux;
     aux = p ;
     num = aux->nro;   // asignamos el primer vamor de la pila
     p = aux->sgte ;
     delete(aux);
     return num;
}
//Muestra elementos de la pila
void mostrar_pila( ptrPila p ){
     ptrPila aux;
     aux = p;     // apunta al inicio de la lista
	 printf("\t|------Cima------|");
     printf("\n");
     while( aux != NULL ){//Se repite hasta que apunte a NULL
            printf("\t|	 %d	 |\n",aux->nro);
			aux = aux->sgte;
     }
	 printf("\t|----------------|");
}
//Insertar cola
void insertar_colas(){
	system("color 0B");
  printf("\n\n Ingrese numero: ");
  scanf("%d",&fono);
  act_1=(nodoc*)malloc(sizeof(nodoc));
  act_1->dato_colas=fono;
  act_1->dura_colas=tiempo;
  act_1->sgte=NULL;
  if(fin==NULL)
    fin=inicio_1=act_1;
  else{
    fin->sgte=act_1;
    fin=act_1;
  }
}
//Imptimir cola
void imprimir_colas(){
  act_1=inicio_1;
  system("color 0B");
  printf("La cola es: \n");
  while(act_1!=NULL){
    printf("%d\n",act_1->dato_colas);
    act_1=act_1->sgte;
  }
  system("pause");
}

//Menu :v
void menugeneral(){
	int opcM;
	int opcA,tipo;
	int i,j,tamm;
	int opci;
	//Arreglos unidimencionales
	int numero[100];
	char letras[100];
	//Arreglos bidimencionales
	int numeroB[100][100];
	char letrasB[100][100];
	//Pilas
	ptrPila p = NULL;  // creando pila
    int x;
	int dato,dat,des;
	int exit;
	do{
		system("color 0B");
		system("cls");
		menu();
		scanf("%d",&opcM);
		switch(opcM){
			case 0:
				printf("\n\nBye, que vuevlas pronto ^^\n");
				break;
			case 1://Abre case del menu princiapl
					do{
						menu_arreglo();
						scanf("%d",&opcA);
						switch(opcA){
							case 1://Abre case 1
								do{//Abre menu tipo
									menu_tipo();
									scanf("%d",&tipo);
											switch(tipo){//Abre el tipo
												case 1://Abre case 1 de la cantidad
													printf("De cuanto quieres el arreglo");
													scanf("%d",&tamm);
													//Metiendo datos
													printf("Ingresa los numeros:\n");
													for(i = 1;i <= tamm;i++){
														printf("[%d]",i);
														scanf("%d",&numero[i]);
													}
													//Mostrando datos
													for(i = 1;i <= tamm;i++){
														printf("\t%d\n",numero[i]);
													}
												break;//Cierra case 1 de la cantidad
												case 2://Abre case 1 de la cantidad
													printf("De cuanto quieres el arreglo");
													scanf("%d",&tamm);
												//Metiendo datos
													printf("Ingresa los numeros:\n");
													for(i = 1;i <= tamm;i++){
														printf("[%d]",i);
														scanf("%c",&letras[i]);
													}
													//Mostrando datos
														for(i = 1;i <= tamm;i++){
														printf("\t%c\n",letras[i]);
													}
												break;//Cierra case 1 de la cantidad
											}//Cierra el switch del tipo
										}while(tipo != 0);//Cierra el menu del tipo
									break;//Cierra el case 1
									case 2://Abre el case 2
										do{//Abre menu tipo
										menu_tipo();
										scanf("%d",&tipo);
											switch(tipo){//Abre el tipo
												case 1://Abre case 1 de la cantidad
													printf("**Nota si metes el valor se ver� reflejado como un 3x3 o 4x4\nDependiendo del valor\nPorfavor haz caso ^^");
													printf("\nDe cuanto quieres el arreglo\n");
													scanf("%d",&tamm);
													//Metiendo datos
													printf("Ingresa los numeros:\n");
													for(i = 1;i <= tamm;i++){
														for(j = 1;j <= tamm;j++){
															printf("[%d][%d]",i,j);
															scanf("%d",&numeroB[i][j]);
														}
													}
													//Mostrando datos
													printf("La tabla se ve de esta manera");
													for(i = 1;i <= tamm;i++){
														printf("\n");
														for(j = 1;j<=tamm;j++){
															printf("\t%d",numeroB[i][j]);
														}
													}
												break;//Cierra case 1 de la cantidad
											case 2://Abre case 1 de la cantidad
													printf("**Nota si metes el valor se ver� reflejado como un 3x3 o 4x4\nDependiendo del valor\nPorfavor haz caso ^^");
													printf("\nDe cuanto quieres el arreglo\n");
													scanf("%d",&tamm);
													//Metiendo datos
													printf("Ingresa las letras:\n");
													for(i = 1;i <= tamm;i++){
														for(j = 1;j<=tamm;j++){
															printf("[%d][%d]",i,j);
															scanf("%s",&letrasB[i][j]);
														}
													}
													//Mostrando datos
													printf("La tabla se ve de esta manera");
													for(i = 1;i <= tamm;i++){
														printf("\n");
														for(j = 1;j<=tamm;j++){
															printf("\t%c",letrasB[i]);
													}
												}
										break;//Cierra case 1 de la cantidad
									}//Cierra el switch del tipo
								}while(tipo != 0);//Cierra el menu del tipo
								break;//Cierra el case 2
						}//Cierra el switch del arreglo
					}while(opcA != 0);//Cierra el do del arreglo
				break;//Cierra case 1
			default:
				printf("\nIngresa un numero valido\n");
			break;//Cierra el case 1
		//Case 2
			case 2:
				do{
     				system("cls");
       				do{
				        system("cls");
        				cout<<"Cuantos datos introduciras?\n ";
        				cin>>dat;
        				if(dat <= 0){
     	 					cout<<"\nPorfavor ingresa un numero mayor a 0\n";
     	 					system("pause");
	     					}
	    				}while(dat <= 0);
					//Todos los datos ingresados se guardaran en dat
					for(int i=0;i<=dat-1;i++){
					printf("[%d]: ",i+1);
						cin>> dato;
    					push( p, dato );
					}
    				//Mostrar
    				if(p!=NULL){
        				mostrar_pila( p );
    				}else{
    				cout<<"\n�Pila vacia!"<<endl;
    				printf("\n");
	 				}
    				//Termina de mostrar
     				do{
    					printf("�Desea desapilar?\n");
    					printf("0 para continuar\n");
    					printf("1 desapilar");
    					cin>>des;
    					if(des == 1){
    						system("cls");
    						x = pop( p );
    						cout<<"\tNumero "<< x <<" desapilado...\n\n";
							//Mostrar
    						if(p!=NULL){
                  				mostrar_pila( p );
                 				}else{
                   	 				cout<<"\nPila vacia..!"<<endl;
                   		 			cout<<"\n\n";
        	    				}//Cierra else
			 				}//Cierra el if
					   }while(des != 0);
	  				printf("\n\nVolver a apilar?\n");
	  				printf("1 Volver a apilar\n");
	  				printf("0 para salir al menu principal\n");
	  				cin>>exit;
	 				}while(exit != 0);
			break;//Cierra case 2
			//Inicia case 3
			case 3:
				do{
   menu_cola();
    printf("\n\n Ingrese una opcion: ");
    scanf("%d",&opci);
    printf("\n");
   //Inicia switch
    switch(opci){
    	case 0:
        printf("...");
        break;
        case 1:
        insertar_colas();
        break;
        case 2:
        imprimir_colas();
        break;
        default:
        	printf("Vuelve a intentarlo");
        	break;
    }//Finaliza switch
  }while(opci != 0);//Finaliza do
				break;//Cierra el case 3
	 	}//Cierra el switch del menu principal
	}while(opcM != 0);//Cierra el do del munu principal
}//Cierra el main
