#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 10000

//Querry: how is everyone keeping array dynamic 
int maxHeap[MAX_SIZE];
int maxHeapSize = 0;

int minHeap[MAX_SIZE];
int minHeapSize = 0;

void swap(int *temp1, int *temp2) {
	int temp = *temp1;
	*temp1 = *temp2;
	*temp2 = temp;
}

void pushMaxHeap(int val) {
	// add num at last 
	maxHeap[maxHeapSize] = val;
	// increase curr pointer 
	int curr = maxHeapSize++;
	//swim
	while (curr > 0){
		int parent = (curr -1) / 2;
		if (maxHeap[parent] < maxHeap[curr]) {
			swap(&maxHeap[parent], &maxHeap[curr]);
			curr = parent; 
		}else {
			break;
		}
	}
}


int popMaxHeap() {
	int top = maxHeap[0];
	maxHeap[0] = maxHeap[--maxHeapSize];

	int curr = 0;
	// sink 
	// while (curr * 2 + 1 < maxHeapSize) --> check if current node has atleast one left child 
	while (curr * 2 + 1 < maxHeapSize) {
		int left = curr * 2 + 1;
		int right = curr * 2 + 2;
		int largest_index = curr;

		if (left < maxHeapSize && maxHeap[left] > maxHeap[largest_index]) {
			largest_index = left;
		}
		if (right < maxHeapSize && maxHeap[right] > maxHeap[largest_index]) {
			largest_index = right;
		}

		if (largest_index == curr) {
			break;
		}
		swap(&maxHeap[curr], &maxHeap[largest_index]);
		curr = largest_index;
	}
	return top;
}

void pushMinHeap(int val) {
	minHeap[minHeapSize] = val;
	int curr = minHeapSize++;
	while (curr > 0) {
		int parent = (curr -1) / 2;
		if (minHeap[parent] > minHeap[curr]) {
			swap(&minHeap[parent], &minHeap[curr]);
			curr = parent;
		}else {
			break;
		}
	}
}

int popMinHeap() {
	int top = minHeap[0];
	minHeap[0] = minHeap[--minHeapSize];
	int curr = 0;

	while(curr * 2 + 1 < minHeapSize) {
		int left = curr * 2 + 1;
		int right = curr * 2 + 2;
		int smallest_index = curr;

		if (left < minHeapSize && minHeap[left] < minHeap[smallest_index]) {
			smallest_index = left; 
		} 
		if (right < minHeapSize && minHeap[right] < minHeap[smallest_index]) {
			smallest_index = right;
		}

		if (smallest_index == curr) {
			break;
		}
		swap(&minHeap[curr], &minHeap[smallest_index]);
		curr = smallest_index;
	}
	return top;
}
//O(log n)
void addNum(int num) {
	// min heap and maxHeap
	if(maxHeapSize == 0 || num <= maxHeap[0]) {
		pushMaxHeap(num);	
	} else {
		pushMinHeap(num);
	}
	
	// balance heap sizes
	if (maxHeapSize > minHeapSize + 1) {
		pushMinHeap(popMaxHeap());
	}else if (minHeapSize  > maxHeapSize) {
		pushMaxHeap(popMinHeap());
	}
} 

//O(1)
double findMedian() {
	if (maxHeapSize > minHeapSize) {
		// balanaced
		return (double)maxHeap[0];
	}
       // else unbalanced 
       return (maxHeap[0] + minHeap[0]) / 2.0;	
	
}

int main() {
	while (true) {
		printf("Enter your choice to insert number, get median or exit (i/g/e): ");
		char choice;

		scanf("%c", &choice);

		switch (choice) {
			case 'i' :
				int num;
				printf("Enter choice of number: ");
				scanf("%d",&num);
				addNum(num);
				break;
			case 'g' :
				printf("Median is : %.2f \n", findMedian());
				break;
			case 'e' :
				goto exit_loops;
			default :
				printf("Invalid command");
				break; // or return -1??
		}
	}

	exit_loops:
		printf("Bye!\n");
	return 0;
}
