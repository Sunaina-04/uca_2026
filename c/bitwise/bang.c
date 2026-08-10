#include <stdio.h>


int bang(int num){
	// ~num +1 --> 2's complement | num 
	// (num | 2's complement) >> 31 --> checks the sign of number, for both -ve and +ve but zero it is zero in both case, so if either +ve or -ve of number = to 1 at msb ==> it is not a 0, if it is we add 1 ==> o/p 
	return ((num | (~num +1) ) >> 31) +1;
}
int main(){
	int num;
	
	printf("Enter number: ");
	scanf("%d", &num);

	printf("Bang of  %d is: %d \n", num, bang (num));
	return 0;
}
