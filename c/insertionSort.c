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

void insertionSort(int* arr, int n){
	// start from the second element 
	for (int i = 1; i < n ; i++){
		// let ith element be the key
		int key = arr[i];
		// let j be the prev element of i
		int j = i-1;
		// checking the previous elements from ith pos
		while (j > 0 && arr[j] > key){
			// if the element is greater shift 
			arr[j+1] = arr[j];
			// and check the prev ones now 
			j--;
		}
		// finally set the key element to its correct position 
		arr[j+1] = key;
	}	
}
double countTime(int* arr, int size){
	// give the time for run 
	clock_t t;
        t = clock();
        insertionSort(arr, size);
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
		/*randomArray(arr, size);
		double time_taken = countTime(arr,size);
		printf("random array - insertion sort -ms : %f \n",time_taken);
		ascendingArray(arr,size);
        	time_taken = countTime(arr,size);
       	 	printf("ascending array -insertion sort -ms : %f \n",time_taken);
		*/
		descendingArray(arr,size);
        	double time_taken = countTime(arr,size);
        	//printf("descending array -insertion sort -ms : %f \n",time_taken);
		printf("%0.3f \n", time_taken);
	}
	return 0;
}
