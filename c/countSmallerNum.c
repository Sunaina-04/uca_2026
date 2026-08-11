#include <stdio.h>

typedef struct {
	int value;
	int index;
}Node;

void num_helper(Node arr[], int result[], int left, int mid, int right) {
	int size = right - left + 1;
	Node helper[size];

	int i = left, j = mid + 1, k = 0, count = 0;

	while (i <= mid && j <= right) {
		if (arr[j].value < arr[i].value) {
			helper[k] = arr[j++];
			count++;
		}
		else {
			result[arr[i].index] += count;
			helper[k] = arr[i++];

		}

		k++;
	}

	while(i <= mid) {
		result[arr[i].index] += count;
		helper[k++] = arr[i++];
	}
	
	while(j <= right) {
		helper[k++] = arr[j++];
	}

	for (int i = 0; i < size; i++) {
		arr[left + i ] = helper[i];
	}
}

void num_after_self(Node arr[], int result[], int left, int right) {
	if (left >= right){
		return;
	}

	int mid = left + (right - left) / 2;

	num_after_self(arr, result, left, mid);
	num_after_self(arr, result, mid+1, right);
	num_helper(arr, result, left, mid, right);
}

int main (){
	int size;
	scanf("%d", &size);

	Node arr[size];
	int result[size];

	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i].value);
		arr[i].index = i;
		result[i] = 0;
	}
      
	num_after_self(arr, result, 0, size - 1);

	for(int i = 0; i < size; i++) {
		printf("%d", result[i]);
	} 

      	return 0;
}
