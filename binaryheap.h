#ifndef binary_heap_h
#define binary_heap_h

#include <stdio.h>

typedef struct binary_heap binary_heap;

void create_heap    (binary_heap** out, int capacity);

int  heap_size      (binary_heap* heap);
int  heap_capacity  (binary_heap* heap);

void free_heap      (binary_heap* heap);

int  push           (binary_heap* heap, int data);
int  peek           (binary_heap* heap);
int  pop            (binary_heap* heap);

void heap_sort      (int* array, int size);

void print          (binary_heap* heap);

#endif /* binary_heap_h */
