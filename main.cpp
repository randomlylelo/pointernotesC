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

}

int main() {
//    workingWithPointers();
    pointerArithmetic();

    return 0;
}