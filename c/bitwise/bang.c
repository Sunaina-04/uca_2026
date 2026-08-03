#include <stdio.h>


int sign(int num1, int num2){
	return ~(~num1|~num2);
}
int main(){
	int num1, num2;
	
	printf("Enter 2 numbers to AND: ");
	scanf("%d %d", &num1, &num2);

	printf("AND of %d and %d is: %d \n", num1, num2, sign(num1, num2));
	return 0;
}
