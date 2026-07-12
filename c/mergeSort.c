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

void merge(int* arr, int left, int mid, int right){
	int nl = mid - left + 1;
	int nr = right - mid;
	// make a left and right array		
	int left_array[nl]; 
	int right_array[nr];

	for (int i = 0 ; i < nl ; i++){
		left_array[i] = arr[left+i];
	}

	for (int i = 0 ; i < nr ; i++){
                right_array[i] = arr[mid+1+i];
        }

	// combine both according to element
	int i = 0 , j = 0, k = left; 
	while (i < nl && j < nr){
		if (left_array[i] <= right_array[j]){
			arr[k] = left_array[i];
			i++;
		}else{
			arr[k] = right_array[j];
			j++;
		}
		k++;
	}

	while (i < nl){
		arr[k] = left_array[i];
		i++;
		k++;
	}
	while (j < nr){
		arr[k] = right_array[j];
		j++;
		k++;
	}

}

void mergeSort(int* arr, int left, int right){
	if (left < right){
		int mid = left + (right -left) /2;

		mergeSort(arr, left, mid);
		mergeSort(arr, mid+1, right);

		merge(arr, left, mid, right);
	}	
}
double countTime(int* arr, int size){
	// give the time for run 
	clock_t t;
        t = clock();
        mergeSort(arr,0, size);
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
		printf("random array - merge sort -ms : %f \n",time_taken);
		ascendingArray(arr,size);
        	time_taken = countTime(arr,size);
       	 	printf("ascending array - merge sort -ms : %f \n",time_taken);
		descendingArray(arr,size);
        	time_taken = countTime(arr,size);
        	printf("descending array - merge sort -ms : %f \n",time_taken);
	}
	return 0;
}
