#include<stdio.h>
#include<iostream>

struct Nodo{
	int dato,opc;
	Nodo *sig;
};

void agregar (Nodo *&frente,Nodo *&fin, int n);
bool cola_vacia(Nodo*);
void eliminar (Nodo *&frente,Nodo *&fin, int n);
//void muestra_cola(Nodo*&frente,Nodo *&fin, int n);

int main() {
	Nodo *frente=NULL;
	Nodo *fin=NULL;
	int num,can;
	std::cout<<"Cuantos deseas meter?";
	std::cin>>can;
	for(int i=1; i<=can;i++){
	printf("Ingresa el valor\n--> ");
	scanf("%d",& num);
	agregar(frente,fin,num);
	}
	muestra_cola(frente,fin,num);
	return 0;
}

void agregar (Nodo *&frente,Nodo *&fin, int n){
	Nodo *nuevo_nodo=new Nodo();
	nuevo_nodo -> dato = n;
	nuevo_nodo -> sig = NULL;
        if( cola_vacia(frente) ){
			frente=nuevo_nodo;
		}
		else{ fin -> sig=nuevo_nodo;}
		fin=nuevo_nodo;
	printf("EL DATO SE AGREGO A LA COLA \n");
		}

bool cola_vacia(Nodo*frente){
	if (frente=NULL){
		return true;
	}
	else { return false;
	}
}
void eliminar (Nodo *&frente,Nodo *&fin, int n){
		Nodo *aux;
		while( *&frente!= NULL){
			aux = *&frente;
			*&frente = aux->sig;
			delete(aux);
		}
		*&frente = NULL;
		*&fin = NULL;

	       }
void muestra_cola(Nodo*&frente,Nodo *&fin, int n){
		 Nodo *aux;
		aux=frente;
		while( aux != NULL ){
			printf("TU NUMERO ES: \n",aux->dato);
			aux = aux->sig;
		}
}
