#include <stdio.h>
#include <stdlib.h> // for malloc(), srand() and rand()
#include <time.h> // for time()
#include <stdbool.h> // for bool data
		     //
void randomArray(int* arr, int n){
	// to set the number truly randome we set a seed in srand. seed is a starting number. 
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
		arr[i] = n-i;
	}
}
void swap (int* num1, int* num2){
	int temp = *num1;
	*num1 = *num2 ;
	* num2 = temp;
}
void bubbleSort(int* arr, int n ){
	bool swapped;
	for ( int i = 0 ; i < n ; i++){
		swapped = false;
		// optimized j < n-i-1 because the last numbers are already at the correct position we are only covering till the last unsorted number ie n-i-1 
		for (int j = 0 ; j < n-i-1 ; j++){
			if (arr[j] > arr[j+1]){
				swap(&arr[j], &arr[j+1]);
				swapped = true;
			}
		}
		// optimized
		// if there hasn't been any recent swap then the array is sorted. break the loop early 
		if (!swapped){
			break;
		}
	}
}
double countTime(int* arr, int size){
	// give the time for run 
        clock_t t;
        t = clock();
        bubbleSort(arr, size);
        t = clock()-t;
        double time_taken = ((double)t)*1000 / CLOCKS_PER_SEC;

	return time_taken;
}
int main(){
	// set the size
	int size = 0;
	
	// initialize the array 
	int *arr = malloc (size *sizeof(int));
	
	// fill with random numbers
	randomArray(arr , size);

	// give the time for run 
	double time_taken = countTime(arr,size);
	printf("random array - bubble sort -ms : %f \n",time_taken);
	
	// fill with ascending numbers 
	ascendingArray(arr,size);
	time_taken = countTime(arr,size);
	printf("ascending array - bubble sort -ms : %f \n",time_taken);
	// fill with descending numbers
	descendingArray(arr,size);
 	time_taken = countTime(arr,size);
 	printf("descending array - bubble sort -ms : %f \n",time_taken);
	
	return 0;
}
