#ifndef test_h
#define test_h
#endif /* test_h */

void test_create();
void test_push();
void test_peek();
void test_pop();

int main(void) {
    test_create();
    test_push();
    test_peek();
    test_pop();
    printf("\nAll tests are passed!\n");
}
