/*==============================================================

    Description: Program to take in integers from user, store
    them in an array, and then display contents of that array
    in 3 formats.

    Author: Nathan Daniel
    [C24527823]

    Date: 12-11-2024

==============================================================*/

#include <stdio.h>

#define SIZE 15 

int main()
{
    //declare variables
    int numberArray[SIZE];

    //display instructions
    printf("Please enter %d integers.\n", SIZE);

    //take in values to fill array
    for (int i = 0; i < SIZE; i++)
    {
        //shows user which number they are inputting
        printf("%d: ", i + 1);
        
        scanf(" %d", &numberArray[i]);
    }
    //for readability in terminal
    printf("\n\n");


    //display contents of array, one element per line
    for(int i = 0; i < SIZE; i++)
    {
        printf("\n%d", numberArray[i]);
    }
    printf("\n\n");


    //display contents of array, elements on same line
    for(int i = 0; i < SIZE; i++)
    {
        printf("%d ", numberArray[i]);
    }
    printf("\n\n");


    //display contents of array, elements on same line, in reverse order
    for(int i = 0; i < SIZE; i++)
    {
        printf("%d ", numberArray[SIZE - 1 - i]);
    }
    printf("\n\n");


    return 0;
}