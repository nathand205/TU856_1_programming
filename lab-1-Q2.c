/*
    Program to illustrate errors & debugging in C (Programming lab 1)

    Nathan Daniel

    24-9-2024
*/

#include <stdio.h>

int main()
{

    int num1, num2;
    float num3;

    num1 = 400;
    num2 = 600;
    num3 = num2;

    printf("\nnum1 contains %d \n", num1);

    printf("num2 contains %d and num3 contains %f\n ", num2, num3);

    return 0;

}
