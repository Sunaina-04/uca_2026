#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Generic Swap function using raw memory buffers
void genericSwap(void *a, void *b, size_t elem_size) {
    void *temp = malloc(elem_size);
    memcpy(temp, a, elem_size);
    memcpy(a, b, elem_size);
    memcpy(b, temp, elem_size);
    free(temp);
}

// Generic Sink (Heapify Down) function
void genericSink(void *arr, int size, int curr, int (*cmp)(const void *, const void *), size_t elem_size) {
    int root = curr;
    int left = curr * 2 + 1;
    int right = curr * 2 + 2;

    // Calculate byte offsets for dynamic array indexing: arr + index * elem_size
    void *root_ptr = (char *)arr + root * elem_size;
    void *left_ptr = (char *)arr + left * elem_size;
    void *right_ptr = (char *)arr + right * elem_size;

    // Compare left child with root
    if (left < size && cmp(left_ptr, root_ptr) > 0) {
        root = left;
        root_ptr = left_ptr;
    }
    // Compare right child with current largest
    if (right < size && cmp(right_ptr, root_ptr) > 0) {
        root = right;
        root_ptr = right_ptr;
    }

    // Swap and recurse down if root changed
    if (curr != root) {
        void *curr_ptr = (char *)arr + curr * elem_size;
        genericSwap(curr_ptr, root_ptr, elem_size);
        genericSink(arr, size, root, cmp, elem_size);
    }
}

// Generic Heap Sort Function
void genericHeapSort(void *arr, int size, int (*cmp)(const void *, const void *), size_t elem_size) {
    // Step 1: Build Max-Heap (Heapify from non-leaf nodes up)
    for (int i = (size / 2) - 1; i >= 0; i--) {
        genericSink(arr, size, i, cmp, elem_size);
    }

    // Step 2: Extract elements one by one from top of heap
    for (int i = size - 1; i > 0; i--) {
        void *first_ptr = arr;
        void *last_ptr = (char *)arr + i * elem_size;

        genericSwap(first_ptr, last_ptr, elem_size);
        genericSink(arr, i, 0, cmp, elem_size);
    }
}

// ==================== COMPARATOR FUNCTIONS ====================

int intComparator(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

int floatComparator(const void *a, const void *b) {
    float x = *(const float *)a;
    float y = *(const float *)b;
    if (x == y) return 0;
    return (x > y) ? 1 : -1;
}

struct student {
    int id;
    float cgpa;
    char *name;
};

int studentIdComparator(const void *a, const void *b) {
    const struct student *x = (const struct student *)a;
    const struct student *y = (const struct student *)b;
    return x->id - y->id;
}

// ==================== MAIN DEMO ====================

int main() {
    // 1. INTEGER ARRAY DEMO
    int arr[] = {5, 9, 4, 2, 8, 0};
    int int_size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Int Array: ");
    for (int i = 0; i < int_size; i++) printf("%d ", arr[i]);
    printf("\n");

    genericHeapSort(arr, int_size, intComparator, sizeof(int));

    printf("Sorted Int Array:   ");
    for (int i = 0; i < int_size; i++) printf("%d ", arr[i]);
    printf("\n\n");

    // 2. FLOAT ARRAY DEMO
    float f[] = {1.2f, 3.4f, 0.7f, 0.8f, 0.4f, 0.3f};
    int float_size = sizeof(f) / sizeof(f[0]);

    printf("Original Float Array: ");
    for (int i = 0; i < float_size; i++) printf("%.1f ", f[i]);
    printf("\n");

    genericHeapSort(f, float_size, floatComparator, sizeof(float));

    printf("Sorted Float Array:   ");
    for (int i = 0; i < float_size; i++) printf("%.1f ", f[i]);
    printf("\n\n");

    // 3. STRUCT ARRAY DEMO
    int n = 7;
    struct student d[7];
    float cgpa[] = {1.2f, 2.2f, 1.3f, 0.7f, 5.4f, 2.3f, 0.9f};
    char *names[] = {"ram", "sham", "tom", "raj", "tom", "sam", "harry"};

    for (int i = 0; i < n; i++) {
        d[i].id = rand() % 100;
        d[i].cgpa = cgpa[i];
        d[i].name = names[i];
    }

    printf("Original Student Structs:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %2d | Name: %-5s | CGPA: %.2f\n", d[i].id, d[i].name, d[i].cgpa);
    }

    genericHeapSort(d, n, studentIdComparator, sizeof(struct student));

    printf("\nSorted Student Structs (by ID):\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %2d | Name: %-5s | CGPA: %.2f\n", d[i].id, d[i].name, d[i].cgpa);
    }

    return 0;
}
