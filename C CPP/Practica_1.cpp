#include <iostream>

int main(){
	char Arreglomensaje[8];
    char ArregloInver[8];
    char ArregloParynon[8];
    char ArregloNumerado[8];
    int c,i=1;

    //Guarda las letras por cada enter
    for(int i=1; i<=8;i++){
    	printf("Ingresa el codigo[%d]: ",i);
    	scanf("%c",&Arreglomensaje[i]);
		scanf("%c",&Arreglomensaje[i]);

    	ArregloInver[i]=Arreglomensaje[i];
 		ArregloParynon[i]=Arreglomensaje[i];
	 	ArregloNumerado[i]=Arreglomensaje[i];
	 }

 	//Mostrara el mensaje
 	printf("\n");
 	printf("El codigo es este:\n");
 	for(i=1; i<=8;i++){
 		printf("%c ",Arreglomensaje[i]);
 	}

 	//Arreglo invertido
 	printf("\n");
 	printf("\n");
 	printf("En orden invertido:\n");
 	for(i=8; i>=1; i--){
	 	 int po=ArregloInver[i];
		 printf("%c ",ArregloInver[i]);
	 }

	//Arreglo de pares
	printf("\n");
	printf("Los pares son:\n");
	c=0;
	for(i=1;i<=8;i++){
	 if((c+1)%2==0){
		printf("%c ",ArregloParynon[i]);
		i=i+1;
		}
	}


	//Parte de los impares
	printf("Los impares son:\n");
	c=0;
	for(i=1;i<=8;i++){
	 if((c+1)%2!=0){
		printf("%c ",ArregloParynon[i]);
		i=i+1;
		}
	}

	//Mensaje ord
	printf("\n\nOrden de extremos:\n");
	c=0;
	for(i=1;i<=4;i++){
		printf("%d ",ArregloNumerado[7-i]);
		printf("%d ",ArregloNumerado[i]);
		i=i+1;
	}

    return 0;
}
