#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char *argv[]) {
	char pa [] = {"susto"};
	char pb [] = {"rino"};
	char let[1];
	char opc;
	int cont;
	do{
		cout<<"Elige una opcion a responder\n";
		if(cont == 1)cout<<"A.- Se puso muy palido le dieron un...<<";
		if(cont >= 2)cout<<"\nB.- La segunda parte de 'ceronte', la primera es...\n--> ";
		cin>>opc;
		if(opc == 'a' || opc == 'A')
		{
			do
			{
				cout<<"A.- Se puso muy palido le dieron un...\nQ para salir\n--> ";
				cin>>let[1];
				if(let[1] == pa[1] || let[1] == pa[2] || let[1] == pa[3] || let[1] == pa[4] || let[1] == pa[5])
				{
					cout<<"La letra es correcta.";
					if(let[1] == pa[5])
					{
						cont++;
					}

				}else{
					cout<<"La letra es incorrecta";
				}
			}while(let[1] != 'Q' || let[1] != 'q');
		} else if(opc == 'b' || opc == 'B'){
			do{
				cout<<"\nB.- La segunda parte de 'ceronte', la primera es...\nQ para salir\n-->";
				cin>>let[1];
				if(let[1] == pa[1] || let[1] == pa[2] || let[1] == pa[3] || let[1] == pa[4] || let[1] == pa[5])
				{
					cout<<"La letra es correcta.";
					if(let[1] == pa[5])
					{
						cont++;
					}

				}else{
					cout<<"La letra es incorrecta";
				}
			}while(let[1] != 'Q' || let[1] != 'q');
		}//Cierra el if
		}while((opc == 'a' || opc == 'A'));
	return 0;
}
