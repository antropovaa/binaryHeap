#include <stdio.h>
#include "binary_heap.h"
#include <assert.h>

int main(void) {
    int array[7] = {10, 4, 5, 3, 11, 22, 43};
    printf("Source array:\t");
    for (int i = 0; i < 7; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    printf("Sorted array:\t");
    heap_sort(array, 7);
}
