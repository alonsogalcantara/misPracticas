#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main(){
	string linea;
       int opc;
       bool repite = true;
       do{
          cout<<"\nIngrese un valor entero\n--> ";
          getline(cin, linea);
          if(Validar_num(linea)){
             repite = false;
          } else {
             cout<<linea<<"\nNo ha ingresado un entero. Intente nuevamente" << endl;
          }
       } while (repite);
       opc = atoi(linea.c_str());
       cout << "El numero ingresado fue: "<<opc<<endl;
       return 0;
	
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
