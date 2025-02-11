/*=============================================================================================

    DESCRIPTION: Program to demonstrate pass by reference into a function.
    An integer is printed, then its address into a function. The integer is
    incremented by 2 and printed, then printed again to see if it has been changed.

    AUTHOR: Nathan Daniel
    [C24527823]

    DATE: 11-02-2025

=============================================================================================*/

#include<stdio.h>

void increment(int *);

int main()
{
    int num = 1;
    int *ptr1;

    // ptr1 contains address of num1
    ptr1 = &num;


    printf("\nValue of number 1: %d\n", *ptr1);

    // increments parameter by 2 and prints result
    increment(ptr1);

    printf("Value of number 1 after incrementing in function: %d\n ", *ptr1);


    return 0;
}

void increment(int *num2)
{
    *num2 = *num2 + 2;

    // pass by reference means that this function accesses
    // the address of the variable and modifies it.
    printf("Value of number 1 + 2: %d\n", *num2);
}
