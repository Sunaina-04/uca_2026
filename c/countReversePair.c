#include <stdio.h>
#include <stdlib.h>

int pair(int nums[], int start, int mid, int end) {
	
	int count = 0;
	int j = mid + 1;

	// count valid reverse pairs in left half
	for (int i = start; i <= mid; i++) {
		while (j <= end && nums[i] > 2 * nums[j]){
			j++;
		}
		count += j - (mid + 1);
	}

	int helper_arr[end - start +1];
	int helper_index = 0;
	int left_index = start;
	int right_index = mid + 1;

	while( left_index <= mid && right_index <= end) {
		if (nums[left_index] <= nums[right_index]) {
			helper_arr[helper_index] = nums[left_index++];
		}else{
			helper_arr[helper_index] = nums[right_index++];
		}
		helper_index++;
	}

	while(left_index <= mid) {
		helper_arr[helper_index++] = nums[left_index++];
	}

	while(right_index <= end) {
		helper_arr[helper_index++] = nums[right_index++];
	}

	// copy all elements back into og array 
	helper_index = 0;
	for (int i = start; i <= end; i++) {
		nums[i] = helper_arr[helper_index++];
	}
	return count;
}

int reversePair(int nums[], int start, int end) {
	// base case
	if (start >= end) {
		return 0;
	}

	int mid = start + (end - start) / 2;
	int count = 0;

	// counting left half
	count += reversePair(nums, start, mid);
	// counting right half
	count += reversePair(nums, mid+1, end);
	// checking pair in left sorted array to right sorted array 
	count += pair(nums, start, mid, end);

	return count;	
}

int main (){

	int size;
	printf("Enter size of array: ");
	scanf("%d", &size);

	int nums[size];
	for (int i = 0 ; i < size; i++) {
		scanf("%d", &nums[i]);
	}

	int pairs = (size > 0) ? reversePair(nums, 0, size-1) : 0;
	printf("%d \n", pairs);

	return 0;
}
