#include <stdio.h>

int main() {

	char string[50];
	printf("Enter the string: \n");

	fgets(string, sizeof(string), stdin);

	// step1:Find ASCII values and turn it into 8 bit binary 
	
	// step2:combine 8 bit binary into 24 bits
	// step3:split 24 bits into groups of 6 bit
	// step4:turn into decimal value
	// step5:check base lookup  
	// step6:handle padding 
	// --> if input length is multiple of 3 => no padding
	// --> if input length leaves a remainder of 2 bytes => 1 padding char(=)
	// --> if input length leaves a remainder of 1 byte => 2 padding char(==)
	// step7: return final output 
	return 0;
}
