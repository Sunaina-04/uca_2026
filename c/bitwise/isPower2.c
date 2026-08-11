#include <stdio.h>


int isPower2(int num1) {
	return (num1 > 0) && !(num1 & (num1-1));
}
int main() {
	int num1, num2;
	
	printf("Enter number to check power: ");
	scanf("%d", &num1);

	printf("%d \n",isPower2(num1));
	return 0;
}
