// https://youtu.be/zuegQmMdy8M
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
    // 4 bytes = 32 bits. We need int* because we need to tell compiler it is 4 bytes as for the pointer points to the
    // Start of the memory address and compiler takes care of rest.
    // Bc add one is essentially move to next memory address.
    printf("Size of integer is %d bytes\n", sizeof(int));
    printf("Address p+1 %d\n", p+1);
    printf("Value p+1 %d\n", *(p+1));
}

void pointerTypesEtc() {
    int a = 1025;
    int* p = &a;

    printf("Size of integer is %d bytes\n", sizeof(int));
    printf("Address = %d, value = %d\n", p, *p);
    printf("Address = %d, value = %d\n", p+1, *(p+1));

    // Char is one byte. Cast p into char pointer.
    char* p0 = (char*)p;
    printf("Size of char is %d bytes\n", sizeof(char));
    printf("Address = %d, value = %d\n", p0, *p0);
    // You can only add/subtract integers to pointers.
    printf("Address = %d, value = %d\n", p0+1, *(p0+1));
    // 1025 = 00000000 00000000 00000100 00000001
    // 00000001 = 1.
    // 00000100 = 4;

    /**
     * Void pointers.
     * Cannot deference or do arithmetic with.
     */
     void* pVoid = p;
    printf("Void pointer address = %d\n", pVoid);
    // Next lines will error.
//    printf("Void value = %d\n", *pVoid);
//    printf("Void+1 address = %d\n", pVoid+1);
}

void pointerToPointer() {
    int x = 5;
    int* p = &x;

    int** q = &p;
    // Change value of x.
    // Best way to do this is to draw it out.
    **q = 10;

    printf("%d\n", **q);
    **q = *p + 2;
    printf("%d\n", **q);
    // More pointers just add *.
}

int main() {
//    workingWithPointers();
//    pointerArithmetic();
//    pointerTypesEtc();
    pointerToPointer();

    return 0;
}