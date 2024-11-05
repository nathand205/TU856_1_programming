/*===========================================================

    Description: Program to take in user values to an array,
    then fill a second array with those values in reverse.

    Author: Nathan Daniel
    [C24527823]

    Date: 5-11-2024

===========================================================*/
#include<stdio.h>

#define SIZE 5

int main()
{
    //define variables
    int array1[SIZE];
    int array2[SIZE];
    int i = 0;
    int j = 0;

    //display instructions to user
    printf("\nPlease provide integers to create a sequence of length %d.\n", SIZE);

    //take in user values for elements of array1
    for(i = 0; i < SIZE; i++)
    {
        printf("Enter integer %d:", i + 1);
        scanf(" %d", &array1[i]);
    }

    //i = SIZE, i - 1 = index of last element in an array of size SIZE
    i--;

    printf("\nYour sequence in reverse is:");

    //fill array2 from elements of array1 in reverse order
    for(j = 0; j < SIZE; j++)
    {
        array2[j] = array1[i];

        //display current element of array2
        printf("\n%d", array2[j]);

        i--;
    }

    return 0;
}