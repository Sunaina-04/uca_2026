#include <stdio.h>


int logicalShift(int num, int shift){
	// in c >> performs arithmetic shift (preserves sign bit), we want logical shift, ie. shift should be covered by 0
	int mask = ~(((1 << 31) >> shift) << 1);
	return ((num >> shift) & mask);
}
int main(){
	int num, shift;
	
	printf("Enter number and shift: ");
	scanf("%x %d", &num, &shift);

	printf("Logical shift of 0x%x by %d is: 0x%x \n", num, shift, logicalShift(num, shift));
	return 0;
}
