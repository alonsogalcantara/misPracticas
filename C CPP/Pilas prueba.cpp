//*********************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main (){
	Pila *tas;
	char *nom;
	if ((tas = (Pila *) malloc (sizeof (Pila))) == NULL)
	return -1;
	if ((nom = (char *) malloc (50 * sizeof (char))) == NULL)
	return -1;
	inicializacion (tas);
	printf ("Ingrese una palabra: ");
	scanf ("%s", nom);
	apilar (tas, nom);
	printf ("La pila (%de elementos): \n",tas->tamano);
	printf("\n********** Cabeza de la PILA **********\n");
	muestra(tas); printf("__________ Bajo de la PILA __________\n\n");
	printf ("Ingrese una palabra: ");
	scanf ("%s", nom); apilar (tas, nom);
	printf ("La pila (%de elementos): \n",tas->tamano);
	printf("\n********** Cabeza de la PILA **********\n"); muestra(tas);
	printf("__________ Bajo de la PILA __________\n\n"); printf ("Ingrese una palabra: ");
	scanf ("%s", nom); apilar (tas, nom);
	printf ("La pila (%de elementos): \n",tas->tamano);
	printf("\n********** Cabeza de la PILA **********\n");
	muestra(tas); printf("__________ Bajo de la PILA __________\n\n");
	printf ("\nLa ultima entrada (LastInFirstOut) [ %s ] sera eliminada", pile_dato(tas));
	printf ("\nLa ultima entrada es eliminada\n"); desapilar (tas);

	/* eliminaci�n del ultimo elemento ingresado */
	printf ("La pila (%de elementos): \n",tas->tamano);
	printf("\n********** Cabeza de la PILA **********\n");
	muestra(tas);
	printf("__________ Bajo de la PILA __________\n\n");
	return 0;}
