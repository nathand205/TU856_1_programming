/*===========================================================================

    DESCRIPTION: Program which takes user-inputted array of numbers and uses
    a function to check whether each number is odd or even.

    The function returns the total number of even numbers to main().
    This number is displayed to the user.


    AUTHOR: Nathan Daniel
    [C24527823]

    DATE: 18-02-2025

===========================================================================*/

#include<stdio.h>

#define SIZE 5


int evenOrOdd(int[]);

int main()
{
    int userNumbers[SIZE];
    
    // instructions for user
    printf("\nPlease enter a sequence of %d numbers.\n", SIZE);

    // fill array with user-inputted numbers
    for (int i = 0; i < SIZE; i++)
    {
        printf("Number %d of %d: ", i + 1, SIZE);
        scanf(" %d", &userNumbers[i]);
    }

    // calls evenOrOdd() function
    printf("\n\nThere are %d even numbers in your sequence.\n ", evenOrOdd(userNumbers));

    return 0;
}

int evenOrOdd(int array[])
{
    int evenNumbers = 0;

    // checks each number in array to see whether it is even or not
    for(int i = 0; i < SIZE; i++)
    {
        if (array[i] % 2 == 0)
        {
            printf("\n%4d is even.", array[i]);
            evenNumbers++;
        }
        else
        {
            printf("\n%4d is odd.", array[i]);
        }
    }

    // return number of even numbers
    return evenNumbers;
}
