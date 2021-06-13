#include <iostream>
#include <stdio.h>
using namespace std;

struct nodo{
    int nro;
    struct nodo *sgte; //El apuntador
};
typedef nodo *ptrPila;

void push( ptrPila &p, int valor ){
     ptrPila aux;
     aux = new(struct nodo);  //Apuntamos al nuevo nodo creado
     aux->nro = valor;
     aux->sgte = p ;
     p = aux ;
}

int pop( ptrPila &p ){
     int num;
     ptrPila aux;

     aux = p ;
     num = aux->nro;   // asignamos el primer vamor de la pila

     p = aux->sgte ;
     delete(aux);

     return num;
}
/*                     Muestra elementos de la pila
------------------------------------------------------------------------*/
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
/*								El int main
**********************************************************************************************************************************/
int main(){
	ptrPila p = NULL;  // creando pila
    int x;
	int dato,dat,des;
	int exit;
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
    cout<<"\nPila vacia!"<<endl;
    printf("\n");
	 }
    //Termina de mostrar
     do{
    	printf("\n�Desea desapilar?\n");
    	printf("0 para continuar\n");
    	printf("1 desapilar\n--> ");
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
            	}
		 	}
	   }while(des != 0);
	  printf("\n\nVolver a apilar?\n");
	  printf("1 Volver a apilar\n");
	  printf("0 para salir del programa\n");
	  cin>>exit;
	 }while(exit != 0);
	cout<<"\n-----Bye-----\n";
}
