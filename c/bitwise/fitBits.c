#include <stdio.h>


int fitsBits(int num1, int num2){
	int shift = 32 + (~num2 + 1);
	return !(((num1 << shift) >> shift) ^ num1); 
}
int main(){
	int num1, num2;
	
	printf("Enter 2 numbers: ");
	scanf("%d %d", &num1, &num2);

	printf("%d \n", fitsBits(num1, num2));
	return 0;
}
