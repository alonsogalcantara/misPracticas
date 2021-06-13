#include <iostream>
#include <string.h>
using namespace std;
int main(){
	int numero;
	int uni;
	cout<<"Teclee el numero";
	cin>>numero;
	uni = numero / 100 % 10;
	cout<<"En centenas es: "<<uni;
	uni = numero / 10 % 10;
	cout<<"En descenas es: "<<uni;
	uni = numero / 1 % 10;
	cout<<"En unidades es: "<<uni;
}
