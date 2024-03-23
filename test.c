// #include <bits/stdc++.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct with a function pointer as a member
struct Operation
{
    int (*perform)(int, int);
};

// Functions that can be pointed to
int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

// Function to initialize the struct with a specific operation
struct Operation *createOperation(int (*opFunc)(int, int))
{
    struct Operation *op = malloc(sizeof(struct Operation));
    if (op)
    {
        op->perform = opFunc;
    }
    return op;
}

int main()
{
    // Create struct instances with different operations
    struct Operation *addOp = createOperation(add);
    struct Operation *subOp = createOperation(subtract);

    // Use the function pointers
    printf("Addition: %d\n", addOp->perform(10, 5));    // Output: Addition: 15
    printf("Subtraction: %d\n", subOp->perform(10, 5)); // Output: Subtraction: 5

    // Clean up
    free(addOp);
    free(subOp);

    return 0;
}
