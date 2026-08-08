#include <stdio.h>
#include <stdlib.h> // for malloc(), srand() and rand()
#include <time.h> // for time()
#include <stdbool.h> // for bool data
		     //
void randomArray(int* arr, int n){
	// to set the number truly random we set a seed in srand. seed is a starting number. 
	// time is always changing so we set the seed as time so that we get starting from a random number each time.
	// srand is used to SET the number generation. its return type is null
	// rand is then used to fetch the number. 
	srand(time(NULL));
	for (int i = 0 ; i < n ; i++){
		arr[i] = rand();
	}
}

void ascendingArray (int* arr, int n){
	for (int i = 0 ; i < n ; i++){
		arr[i] = i;
	}
}

void descendingArray (int* arr, int n){
	for (int i = n ; i >0 ; i--){
		arr[i] = i;
	}
}

void swap (int heap[], int pos1, int pos2) {
	int temp = heap[pos1];
	heap[pos1] = heap[pos2];
	heap[pos2] = temp;
}

void sink(int heap[], int size, int current) {
	int root = current;
	int left = 2 * current + 1;
	int right = 2 * current + 2;

	if (left < size && heap[left] > heap[root]) {
		root = left;
	}

	if (right < size && heap[right] > heap[root]) {
		root = right;
	}

	if (root != current) {
		swap (heap, current, root);
		sink(heap, size, root);
	}
}

void printArray(int heap[], int size) {
	for (int i = 0; i < size; i++) {
		printf("[ %d, ", heap[i]);
	}
	printf("] \n");
}

void heapSort(int heap[], int size){

	// parent = n / 2 -1 for 0 based index 
	// child1 = n * 2 + 1
	// child2 = n * 2 + 2
	for (int i = size / 2 - 1; i >= 0 ; i--) {
		sink(heap, size, i);
	}
	
	// delmax
	for (int i = size - 1; i > 0; i--) {
		swap(heap, 0, i);

		sink(heap, i, 0);
	}
	// print final array 	
	//printArray(heap, size);
}

double countTime(int* arr, int size){
	// give the time for run 
	clock_t t;
        t = clock();
        heapSort(arr, size);
        t = clock()-t;
        double time_taken = ((double)t)*1000 / CLOCKS_PER_SEC;

	return time_taken;
}
int main(){

	int sizeArray[9] = {0,8000,12000,16000,20000,24000,28000,32000,36000};
	int sizeArrayLength = sizeof(sizeArray)/sizeof(sizeArray[0]);
	for (int i =0 ;i<sizeArrayLength ; i++){
		int size = sizeArray[i];
		int* arr = malloc (size *sizeof(int));
		randomArray(arr, size);
		double time_taken = countTime(arr,size);
		printf("random array - heap sort -ms : %f \n",time_taken);
		ascendingArray(arr,size);
        	time_taken = countTime(arr,size);
       	 	printf("ascending array - heap sort -ms : %f \n",time_taken);
		descendingArray(arr,size);
        	time_taken = countTime(arr,size);
        	printf("descending array - heap sort -ms : %f \n",time_taken);
	}
	return 0;
}
