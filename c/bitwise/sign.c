#include <stdio.h>


int sign(int num){
	return ((num >> 31) | (!!num));
}
int main(){
	int num;
	
	printf("Enter number to get sign: ");
	scanf("%d", &num);

	printf("sign of %d is :%d \n", num, sign(num));
	return 0;
}
