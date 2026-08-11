#include <stdio.h>


int getByte(int num, int shift){
	// F = 1111 so FF = 1111 1111 --> 8 bytes 
	return ((num >> (shift << 3)) & 0xFF);
}
int main(){
	int num, shift;
	
	printf("Enter 2 numbers to get byte: ");
	scanf("%x %d", &num, &shift);

	printf("Extracted byte of 0x%x for %d byte is: 0x%x \n", num, shift, getByte(num, shift));
	return 0;
}
