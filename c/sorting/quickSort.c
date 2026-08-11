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
		arr[i] = n-i;
	}
}

void swap (int* num1, int* num2){
        int temp = *num1;
        *num1 = *num2 ;
        *num2 = temp;
}

int partition(int* arr , int low, int high){
	int pivot = arr[high];

	int i = low-1;

	for (int j = low ; j < high ; j++){
		if (arr[j] < pivot ){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);
	return i+1;
}
void quickSort(int* arr , int low , int high){
	if (low < high){

		int pi = partition(arr, low,high);
		quickSort(arr, low , pi-1);
		quickSort(arr , pi+1, high);
	}
}
double countTime(int* arr, int size){
	// give the time for run 
	clock_t t;
        t = clock();
        quickSort(arr, 0, size-1);
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
		printf("random array - quick sort -ms : %f \n",time_taken);
		ascendingArray(arr,size);
        	time_taken = countTime(arr,size);
       	 	printf("ascending array - quick sort -ms : %f \n",time_taken);
		descendingArray(arr,size);
        	time_taken = countTime(arr,size);
        	printf("descending array - quick sort -ms : %f \n",time_taken);
	}
	return 0;
}
