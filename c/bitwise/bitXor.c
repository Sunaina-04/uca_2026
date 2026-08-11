#include <stdio.h>


int bitXor(int num1, int num2){
	return !(num1 & !(num1 & num2)) & !(num2 & !(num1 & num2));
}

int main(){
	int num1, num2;
	
	printf("Enter 2 numbers to XOR: ");
	scanf("%d %d", &num1, &num2);

	printf("XOR of %d and %d is: %d \n", num1, num2, bitXor(num1, num2));
	return 0;
}
