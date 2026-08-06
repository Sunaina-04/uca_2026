#include "priority_queue.h"

void swap(VillageNode *temp1, VillageNode *temp2) {
	VillageNode temp = *temp1;
	*temp1 = *temp2;
	*temp2 = temp;
}

// Restore max-heap property upwards after insertion
void heapifyUp(VillageNode heap[], int index) {
	int parent = (index - 1)/2;

	while (index > 0 && heap[index].current_load > heap[parent].current_load) {
		swap (&heap[index], &heap[parent]);
		index = parent;
		parent = (index -1) / 2;
	}
}

// restore max-heap property downwards after extracting max
void heapifyDown(VillageNode heap[], int size, int index) {
	int largest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	if (left < size && heap[left].current_load > heap[largest].current_load) {
		largest = left;
	}	
	if (right < size && heap[right].current_load > heap[largest].current_load) {
		largest = right;
	}
	if (largest != index) {
		swap (&heap[index], &heap[largest]);
		heapifyDown(heap, size, largest);
	}
}

void insert(VillageNode heap[], int *size, VillageNode node) {
	heap[*size] = node;
	(*size)++;
	heapifyUp(heap, *size-1);
}

// aka delete node from max heap
VillageNode extractMax(VillageNode heap[], int *size) {
	VillageNode maxNode = heap[0];
	heap[0] = heap[*size -1];
	(*size)--;
	heapifyDown(heap, *size, 0);
	return maxNode;
}
