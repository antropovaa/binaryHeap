#include <stdio.h>
#include "binaryheap.h"
#include <assert.h>
#include "test.h"

void test_create() {
    binary_heap* heap_test;
    create_heap(&heap_test, 10);
    
    assert(heap_size(heap_test) == 0);
    assert(heap_capacity(heap_test) == 10);
    printf("Test of creating is passed\n");
}

void test_push() {
    binary_heap* heap_test;
    create_heap(&heap_test, 10);
    
    push(heap_test, 10);
    push(heap_test, 11);
    push(heap_test, 12);
    push(heap_test, 14);
    
    assert(heap_size(heap_test) == 4);
    printf("Test of pushing is passed\n");
}

void test_peek() {
    binary_heap* heap_test;
    create_heap(&heap_test, 10);
    
    push(heap_test, 10);
    push(heap_test, 11);
    push(heap_test, 12);
    push(heap_test, 14);
    
    assert(peek(heap_test) == 10);
    assert(heap_size(heap_test) == 4);
    printf("Test of peeking is passed\n");
}

void test_pop() {
    binary_heap* heap_test;
    create_heap(&heap_test, 10);
    
    push(heap_test, 10);
    push(heap_test, 11);
    push(heap_test, 12);
    push(heap_test, 14);
    
    assert(pop(heap_test) == 10);
    assert(heap_size(heap_test) == 3);
    printf("Test of popping is passed\n");
}
