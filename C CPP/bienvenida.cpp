#include <iostream>
#include <string.h>

char bienvenida(){
	char nombre[30];
	char conca[30];
	char salud[] = {"Hola "};

	printf("Ingresa tu nombre\n");
	scanf("%s",&nombre);

	strcpy(conca,salud);
	strcat(conca,nombre);
	printf("%s",conca);
	return 0;
}

int main(){
	bienvenida();

}
