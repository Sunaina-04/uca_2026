#include <stdio.h>
#include <stdlib.h>

int inversionHelper(int arr[], int left, int mid ,int right) {
	int helper_arr[right - left + 1];

	int k = 0;
	int i = left;
	int j = mid + 1;
	int count = 0;

	while ( i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			helper_arr[k] = arr[i++];
		}else{
			helper_arr[k] = arr[j++];
			count += mid - i + 1;
		}
		k++;
	}

	while (i <= mid) {
		helper_arr[k++] = arr[i++];
	}

	while (j <= right) {
		helper_arr[k++] = arr[j++];
	}

	k = 0;
	for (int i = left; i <= right; i++) {
		arr[i] = helper_arr[k++];
	}

	return count;
}

int countInversion(int arr[], int left, int right) {
	if (left >= right) {
		return 0;
	}

	int mid = left + (right - left) / 2;
	int count = 0;

	count += countInversion(arr, left, mid);
	count += countInversion(arr, mid+1, right);
	count += inversionHelper(arr, left, mid, right);

	return count;
}

int main (){
	int size;
	printf("Enter size of array:");
	scanf("%d", &size);

	int arr[size];
	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}

	int inversion = countInversion(arr, 0, size-1);
	printf("%d\n", inversion);
        return 0;
}
