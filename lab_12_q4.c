/*=============================================================================================

    DESCRIPTION: Program to demonstrate pass by value into a function.
    An integer is printed, then passed into a function as a parameter.
    The parameter is incremented by 2 and printed, then the original
    number is printed again to see if it has been changed.
    
    AUTHOR: Nathan Daniel
    [C24527823]

    DATE: 11-02-2025

=============================================================================================*/
#include<stdio.h>

void increment(int num2);

int main()
{
    int num = 1;


    printf("\nValue of number 1: %d\n", num);

    // increments parameter by 2 and prints result
    increment(num);

    printf("Value of number 1 after incrementing in function: %d\n ", num);


    return 0;
}

void increment(int num2)
{
    num2 = num2 + 2;

    // pass by value means this function only changes the value
    // of this copy of the number and not the number itself.
    printf("Value of number 1 + 2: %d\n", num2);
}
