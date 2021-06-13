#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int x=1,i;
	int res=1;
	for(i=1;i<=8;i=i++){
		x=x*i;
		printf("%d * %d = %d",i,res,x);
		printf("\n");
	}
	return 0;
}
