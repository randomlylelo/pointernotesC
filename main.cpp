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

void increment(int* p) {
    // This is called "Call by reference"
    // It uses less memory because it essentially doesn't clone the variable to modify it and return, instead it
    // uses the variable in memory already and increment it.
    // Does add to the stack of calls, but overall less memory use.
    *p = *p + 1;
}
void pointerFunc() {
    int a = 10;
    printf("%d\n", a);
    increment(&a);
    printf("%d\n", a);
}

void pointersAndArrays() {
    int A[] = {10, 4, 65, 34, 95};

    // The address of the array is the same address as the first element in array.
//    printf("Address %d\n", A);
//    printf("Address %d\n", &A[0]);

    int* p = A;
    // We can do, as for it will go to the next element in array.
//    p++;
    // But not
//    A++;

    for(int i = 0; i < 5; i++) {
        printf("Address at element %d in array is %d\n", i, A+i);
        // Note it is additive by 4 because an int takes 4 bytes.
        printf("Value at element %d in array is %d\n", i, *(A+i));

        // We can also access the array normally:
//        printf("Address at element %d in array is %d\n", i, &A[i]);
//        printf("Value at element %d in array is %d\n", i, A[i]);
    }

    // We can also do
//    for(int i = 0; i < 5; i++) {
//        printf("Address at element %d in array is %d\n", i, p);
//        printf("Value at element %d in array is %d\n", i, *p);
//        p++;
//    }
}

int sumOfElements(int A[], int size) {
    // Compiler interprets as int* A. So only gets the first element pointer of A. Doesn't make a copy
    // Which makes sense because arrays can be very big.
    // So the next line wouldn't work because it would be 4/4 = 1.
//    int size2 = sizeof(A) / sizeof(A[0]);
    printf("SOE: Size of A = %d, size of A[0] = %d\n", sizeof(A), sizeof(A[0]));
    // This C++ 14 compiler weird. sizeof(A) should be 4, doesn't matter. Just how they made the compiler.
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += A[i];
    }

    return sum;
}
void doubleArrElems(int A[], int size) {
    // See it is like pointers, can modify.
    for(int i = 0; i < size; i++) {
        A[i] += A[i];
    }
}
void reduceArrElems(int* A, int size) {
    for(int i = 0; i < size; i++) {
        *(A + i) -= *(A + i)/2;
    }
}
void arraysAsFuncArgs() {
    int A[] = {10, 4, 65, 34, 95};
    int size = sizeof(A) / sizeof(A[0]);
    int total = sumOfElements(A, size);

    printf("Sum of elements = %d\n", total);
    printf("Main: Size of A = %d, size of A[0] = %d\n", sizeof(A), sizeof(A[0]));

    printf("Double array elements:\n");
    doubleArrElems(A, size);
    for(int i = 0; i < size; i++) {
        printf("%d\n", A[i]);
    }
    printf("Reduce array elements:\n");
    // Can also be &A[0] instead of A.
    reduceArrElems(A, size);
    for(int i = 0; i < size; i++) {
        printf("%d\n", A[i]);
    }
}

void charArrPrint(char* C) {
    // As long as the char is not the zero character.
    while(*C != '\0') {
        printf("%c", *C);
        C++; // Move to next char by adding 1.
    }
    printf("\n");
}
void charArrAndPointers() {
    char string[20];
    string[0] = 'J';
    string[1] = 'O';
    string[2] = 'H';
    string[3] = 'N';
    string[4] = '\0'; // Always end with zero character. Used to terminate the string.
    printf("%s\n", string);

    char C[20] = "Hello world!"; // This automatically adds the \0.
    // This will pass in the memory location of the first char, aka the location of 'H'.
    charArrPrint(C);
}

int main() {
//    workingWithPointers();
//    pointerArithmetic();
//    pointerTypesEtc();
//    pointerToPointer();
//    pointerFunc();
//    pointersAndArrays();
//    arraysAsFuncArgs();
    charArrAndPointers();

    return 0;
}