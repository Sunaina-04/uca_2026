#include <stdio.h>

int findFour(int arr[], int size) {
	int result = 0;

	for (int bit = 0; bit < 32; bit++) {
		int bit_sum = 0;
		for (int i = 0; i < size; i++) {
			// check if the given bit is set
			if (arr[i] & (1 << bit)) {
				bit_sum++;
		
			}
		if (bit_sum % 3 != 0 ) {
			result |= (1 << bit);
			}
		}
	}
	return result;
}

int main() {

	int size;

	printf("Enter array size");
	scanf("%d",&size);

	int arr[size];
	printf("Enter array elements:");

	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}

	printf("Element occuring 4x times is: %d", findFour(arr, size));
	return 0;
}
