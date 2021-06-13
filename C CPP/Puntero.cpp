# include <iostream>

int main(){
	int num=20;
	int y = 10;
	int x[10]{2,4,6,8,10,12,14,16,18,20};
	int *ip;
	int *ip2;
	int *ip3;

	ip = &num;
	ip2 = &y;
	ip3 = &x[10];

	printf("[%d] %d",num,*ip);
	printf("\n");
	printf("[%d] %d",y,*ip2);
	printf("\n");
	printf("[%d] %d",x[10],*ip3);
	printf("\n");


	return 0;
}
