/*======Contexto======
*Este programa fue construido para la obtención de dos puntos en la materia
*Se resolvió y se obtuvieron duchos puntos.
*/

#include <stdio.h>

int main() {
	int arreglo[3][3] = {7,9,2,1,3,4,6,99,8};
	int i,j,aux=0;
	//Filas
	for(i=0;i<=2;i++){
		printf("\n");
		//Columnas
		for(j=0;j<=2;j++){
			printf("%d\t",arreglo[i][j]);
		}
	}
	printf("\n");
	printf("\n");
	//Filas
	for(i=0;i<=2;i++){
		//Columnas
		for(j=0;j<=2;j++){
			//Pares
			if(i%2!=0 || j%2!=0){
			aux=arreglo[i][j]+aux;
			}
		}
	}
	printf("La suma de las filas y columnas pares son\n--> ");
	printf("%d\n",aux+3);
	return 0;
}
