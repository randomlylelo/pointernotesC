#include<stdio.h>

void workingWithPointers() {
    /**
     * Working with pointers in video.
     */
    int a;
    int* p;

    p = &a;

    *p = 10; // deference p, essentially sets a.
    printf("%d\n", p);
    printf("%d\n", *p);

    // Create new variable b.
    int b = 20;
    // Now set a to same value as b but using pointer.
    *p = b;
    printf("%d\n", p);
    printf("%d\n", *p);
}

void pointerArithmetic() {
    int a = 10;
    int* p = &a;

    printf("Address p %d\n", p);
    printf("Value p %d\n", *p);
    // +1, adds 4 to the memory address because an int has 4 bytes in memory.
    // Bc add one is essentially move to next memory address.
    printf("Size of integer is %d bytes\n", sizeof(int));
    printf("Address p+1 %d\n", p+1);
    printf("Value p+1 %d\n", *(p+1));
}

int main() {
//    workingWithPointers();
    pointerArithmetic();

    return 0;
}