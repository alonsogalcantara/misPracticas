#include <iostream>

int main(){
char *Cadena = new char[80];
    printf("\n Ingresa un Numero: ");
    scanf("%d",&Cadena);

    int suma = 0;
    printf("\n Los numero separados Son:\n");
    for(int i = 0 ; i < (Cadena) - 1; i++) {
        int Num = Cadena[i] - '0';
        printf("\n %d",Num);
        suma += Num;
    }
    printf("\n\nLa Suma de Dichos Numeros es: %d", suma);
    delete[] Cadena;
    return 0;
}
