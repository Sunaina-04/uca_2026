#include <stdio.h>


int conditional(int num1, int num2, int num3){
	// conditional(x,y,z)
	// if x = non-zero --> return y, if x = zero --> return z;
	
	// 1. Convert num1 to boolean: 1 if num1 is non-zero, 0 if num1 is zero
	int is_nonzero = !!num1;
	
	// 2. Create a 32-bit mask using two's complement (-is_nonzero):
   	//    If true  (1) -> mask is ALL 1s (0xFFFFFFFF)
    	//    If false (0) -> mask is ALL 0s (0x00000000)
	int mask = ~is_nonzero + 1;

	// 3. Use mask to pick num2 (if true) or num3 (if false)
	return  (( mask & num2) | ((~mask & num3)));
}
int main(){
	int num1, num2, num3;
	
	printf("Enter 3 numbers to check conditon: ");
	scanf("%d %d %d", &num1, &num2, &num3);

	printf("conditional of %d, %d and %d is: %d \n", num1, num2, num3, conditional(num1, num2, num3));
	return 0;
}
