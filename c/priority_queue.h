// header guard --> if not defined = ifndef, end = endif
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

typedef struct {
	int population;
	int clinics;
	double current_load;
} VillageNode;

// Function prototype
void insert (VillageNode heap[], int *heap_size, VillageNode node);
void swap(VillageNode *temp1, VillageNode *temp2);
void heapifyUp(VillageNode heap[], int index);
void heapifyDown(VillageNode heap[], int size, int index);
VillageNode extractMax(VillageNode heap[], int *size);

#endif
