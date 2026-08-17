#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>

void generateRandom(int *a, int s)
{
    int i;
    for (i = 0; i < s; i++)
    {
        *(a + i) = rand() % s + 1;
    }
}

void swap(void *a, int i, int j, int sz)
{
    printf("swap");
    char *temp;
    char t1 = (char *)(a + isz);
    char t2 = (char *)(a + jsz);
    memcpy(temp, t1, sz);
    memcpy(t1, t2, sz);
    memcpy(t2, temp, sz);
}

void quick_sort(void *a, int L, int R, int (*cmp)(void *, void *), int sz)
{
    printf("quick_sort");
    if (L >= R)
        return;
    int p = L;
    int x = L;
    int i = L + 1;
    for (; i <= R; i++)
    {
        if (cmp(a + i * sz, a + p * sz) < 0)
        {
            swap(a, i, ++x, sz);
        }
    }
    swap(a, x, p, sz);
    quick_sort(a, L, x - 1, cmp, sz);
    quick_sort(a, x + 1, R, cmp, sz);
}

void printArray(int *array, int size) {
	printf("[");
	for(int i = 0; i < size; i++) {
		printf(" %d ", arr[i]);
	}
	printf("]\n");
}

struct student
{
    int id;
    float cgpa;
    char *name;
};

int intCmparator(void *i, void *j)
{
    printf("intCmparator");
    int x = *(int *)i;
    int y = *(int *)j;
    if (x == y)
        return 0;
    if (x < y)
        return -1;
    return +1;
}
//   float * = 120, 130    void *i = 120  void *j = 130 
int floatCmparator(void *i, void *j)
{
    float x = *(float *)i;
    float y = *(float *)j;
    if (x == y)
        return 0;
    if (x < y)
        return -1;
    return +1;
}

int studentIdCmp(void *i, void *j)
{
    struct student *x = (struct student *)i;
    struct student *y = (struct student *)j;
    return x->id - y->id;
}


void swap (int *heap, int pos1, int pos2) {
	int temp = heap[pos1];
	heap[pos1] = heap[pos2];
	heap[pos2] = temp;
}

void sink(int *heap, int size, int curr) {
	int root = curr;
	int left = curr * 2 + 1;
	int right = curr * 2 + 2;

	if (left < size && heap[left] > heap[root]) {
		root = left;
	}
	if (right < size && heap[right] > heap[root]) {
		root =  right;
	}

	if (curr != root) {
		swap(heap, curr, root);
		sink(heap, size, root);
	}
}


	// maybe the pointer required to be used is void 
void heapSort(int *heap, int size) {
	
	for (int i = (size/2) -1; i >= 0; i--) {
		sink(heap, size, current);
	}

	for (int i = size - 1; i >=0; i--) {
		swap(heap, 0, i);

		sink(heap, i, 0);
	}
}

int main() {

	// int array 
	int arr[] = {5,9,4,2.8,0};
	int size = sizeof(arr) / sizeof(arr[0]);

	generateRandom(arr, size);
	
	// print array 
	printArray(arr, size);
	

	// heapSort 
	heapSort(arr, size);
	print(a, size);

	// float Array 
	float f[6] = {1.2, 3.4, .7, .8, .4, .3};
    //quick_sort(f, 0, 5, floatCmparator, sizeof(float));
    
	//should print float array --> printArray()
	int i;
    	for (i = 0; i < 6; i++)
    	{
        	printf("%f ", f[i]);
    	}

	// Struct data type 
   	 int n = 7;
   	 struct student *d = (struct student *)(malloc(sizeof(struct student *) * n));

    	float cgpa[] = {1.2f, 2.2f, 1.3f, .7f, 5.4f, 2.3f, .9f};
    	char *names[] = {"ram", "tina", "tom", "sam", "tom", "david", "harry"};
   	for (i = 0; i < n; i++)
    	{
        	struct student *s = (struct student *)(malloc(sizeof(struct student *)));
        	s->id = rand() % 100;
        	s->cgpa = cgpa[i];
        	s->name = names[i];
        	d[i] = *s;
    	}
    	for (int i = 0; i < n; i++)
    	{
        	printf("%d:%s:%.2f, ", d[i].id, d[i].name, d[i].cgpa);
    	}
    	
	// heap Sort 	
//	quick_sort(d, 0, 6, studentIdCmp, sizeof(struct student *));

    	
	// print heap
	for (int i = 0; i < n; i++)
    	{
        	printf("%d:%s:%.2f, ", d[i].id, d[i].name, d[i].cgpa);
    	}

    	return 0;
}
