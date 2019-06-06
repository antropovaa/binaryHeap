#include "binaryheap.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

void    sift_up     (binary_heap* heap, int index);
void    sift_down   (binary_heap* heap, int index);
int     resize_heap (binary_heap* heap);

struct binary_heap {
    int *data;
    int size;
    int capacity;
};

int HEAP_CAPACITY_MAX = (int) - 1;

void create_heap(binary_heap** out, int capacity) {
    binary_heap* heap = (binary_heap*)malloc(capacity * sizeof(binary_heap));
    
    assert(heap);
    if (!heap)
        return;
    
    heap->data = (int*)malloc(capacity * sizeof(int));
    
    for (int i = 0; i < capacity; i++) {
        heap->data[i] = -1;
    }
    
    heap->size = 0;
    heap->capacity = capacity;
    
    *out = heap;
}

void free_heap(binary_heap* heap) {
    assert(heap);
    
    for (int i = 0; i < heap->size; ++i)
        free(&heap->data[i]);
    
    free(heap->data);
    free(heap);
}

int heap_size(binary_heap* heap) {
    assert(heap);
    return (heap->size);
}

int heap_capacity(binary_heap* heap) {
    assert(heap);
    return (heap->capacity);
}

void sift_up(binary_heap* heap, int index) {
    assert(heap);
    assert(index >= 0);
    assert(index < heap->size);
    
    if (index == 0)
        return;
    
    int parent_index = (index - 1) / 2;
    
    if (heap->data[index] < heap->data[parent_index]) {
        int temp = heap->data[index];
        heap->data[index] = heap->data[parent_index];
        heap->data[parent_index] = temp;
    }
    
    sift_up(heap, parent_index);
}

void sift_down(binary_heap* heap, int index) {
    assert(heap);
    assert(index >= 0);
    assert(index < heap->size);
    
    if (index == heap->size - 1)
        return;
    
    int swp = index;
    int left = (index << 1) + 1;
    int right = (index << 1) + 2;
    
    if (left < heap->size && heap->data[left] < heap->data[swp])
        swp = left;
    if (right < heap->size && heap->data[right] < heap->data[swp])
        swp = right;
    
    if (swp != index) {
        int temp = heap->data[index];
        heap->data[index] = heap->data[swp];
        heap->data[swp] = temp;
        
        sift_down(heap, swp);
    }
}

int push(binary_heap* heap, int data) {
    assert(heap);
    
    if (heap->size + 1 == HEAP_CAPACITY_MAX)
        return 0;
    
    if (heap->size == heap->capacity) {
        if (!resize_heap(heap))
            return 0;
    }
    
    heap->data[heap->size++] = data;
    sift_up(heap, heap->size - 1);

    return 1;
}

int resize_heap(binary_heap* heap) {
    int new_size = heap->capacity << 1;
    if (new_size < heap->capacity)
        return 0;
    
    heap->capacity = new_size;
    
    int* new_data = realloc(heap->data, heap->capacity * sizeof(int));
    
    if (new_data == NULL)
        return 0;
    
    heap->data = new_data;
    return 1;
}

int peek(binary_heap* heap) {
    assert(heap);
    return (heap->size >0 ? *heap->data : 0);
}

int pop(binary_heap* heap) {
    assert(heap);
    
    int max = *heap->data;
    
    if (--heap->size > 0) {
        *heap->data = heap->data[heap->size];
        sift_down(heap, 0);
    }
    
    return max;
}

void heap_sort(int* array, int size) {
    binary_heap* heap;
    create_heap(&heap, size);
    
    for (int i = 0; i < size; i++) {
        push(heap, array[i]);
    }
    
    print(heap);
    
    for (int i = 0; i < size; i++) {
        array[i] = pop(heap);
    }
}

void print(binary_heap* heap) {
    for (int i = 0; i < heap->size; i++) {
        if (heap->data[i] > 0) {
            printf("%d ", heap->data[i]);
        }
    }
    printf("\n" );
}
