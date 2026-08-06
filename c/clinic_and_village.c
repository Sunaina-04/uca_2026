#include <stdio.h>
#include "priority_queue.h"
#include <stdlib.h>

double minLoad(int villages, int avail_clinics, int population[]) {
        // 1. dynamic allocation of space for n villages	
	VillageNode *heap = (VillageNode *)malloc(villages * sizeof(VillageNode));
	if (heap == NULL) {
		printf("Memory allocation failede! \n");
		return -1;
	}
	// used to track heap elements 
	int heap_size = 0;
	
	//2. give 1 clinic to each village 
	//and add data to max heap 
	for (int i = 0; i < villages; i++) {
		VillageNode node;
		node.population = population[i];
		node.clinics = 1;
		node.current_load = (double)population[i]/1.0;
		insert(heap, &heap_size, node);
	}

	// 3. distribute remaining (avail_clinics -villages) clinics greedily
	int remaining_clinics = avail_clinics - villages;
	while (remaining_clinics > 0) {
		VillageNode maxVillage = extractMax(heap, &heap_size);

		maxVillage.clinics++;
		maxVillage.current_load = (double)maxVillage.population / maxVillage.clinics;
		
		insert(heap, &heap_size, maxVillage);

		remaining_clinics--;
	}

	// 4. save final max_load 
	double max_load = heap[0].current_load;

	// 5. free dynamically allocated heap memory 
	free(heap);
	
	return max_load;
}

int main() {

	int villages, clinics;
	int n;
	int population[villages];

	villages = 3;
	clinics = 5;
	int test_population[3] = {200,20,50};
	

	for (int i = 0; i < villages ; i++) {
		//int n = scanf("%d", &n);

		population[i] = test_population[i];
	}
	
	double min_load_per_clinic = minLoad(villages, clinics, population);
	printf("Min possible maximum load is : %.2f \n", min_load_per_clinic);

	return 0;
}
