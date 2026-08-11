#include <stdio.h>

void swap (int heap[], int current,  int parent) {
	heap[parent] = temp;
}
void heapify(int heap[], int current) {
	// parent = i / 2;
	// child1 = i * 2;
	// child2 = i * 2 + 1;
	
      // recursively creating max heap for ascending order 	
	// if i is at root 
	if (current == 0){
		return; 
	}
	int parent = current/2;
	if (heap[parent] > heap[current]) {
		swap(heap, parent, current);
		heapify(heap, parent);	
	}
	/*
	int temp, i;

	i = size;
	temp = A[n]
	if ()*/
}

void insert(int heap[], int key) {
	// WHAT AND WHERE IS SIZE COMING FROM, SHOULDNT IT BE 'i'
	heap[size] = key;
	heapify(heap, size);
	size++;
}


/*void swim(int size, int test_array[size]) {
	int last_index_ele, i ,j;

}*/

void printArray(int size, int test_array[size]) {
	for (int i = 0 ; i < size; i++) {
		printf("[%d, ]",test_array[i]);
	}
}
int main() {
	int test_array[6] = {5,9,4,2,8,0};
	int size = sizeof(test_array) / sizeof(test_array[0]);

	int heap [size];
	// creating max-heap aka heapify 
	for (int i = 0; i < size; i++) {
		insert(heap, test_array[i]);
	}

	//2. delmax
	//3. printArray 
	printArray(size, test_array);
	return 0;
}
