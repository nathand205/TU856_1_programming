/*==================================================================

DESCRIPTION: Program to take in floats from user and store them in
an array. Then copy the contents of that array to a 2nd array, and
display the contents of both arrays. (all using pointer notation)

AUTHOR: Nathan Daniel
[C24527823]

DATE: 03-12-2024

==================================================================*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

int main()
{
    float *ptr1;
    float *ptr2;
    int i;


    //allocate memory needed for arrays
    ptr1 = calloc(SIZE, sizeof(float));
    ptr2 = calloc(SIZE, sizeof(float));

    //if memory allocation fails, exit program
    if (ptr1 == NULL || ptr2 == NULL)
    {
        printf("Memory allocation failed. Exiting program.");

        return 0;
    }


    //get values from user
    printf("\nEnter %d floats into array 1:\n", SIZE);

    for(i = 0; i < SIZE; i++)
    {
        scanf("%f", ptr1 + i);
    }


    //fill array 2 from array 1
    for(i = 0; i < SIZE; i++)
    {
        *(ptr2 + i) = *(ptr1 + i);
    }


    //display contents of both arrays to user
    printf("\nContents of array 1:");
    for(i = 0; i < SIZE; i++)
    {
        printf("\n%.2f", *(ptr1 + i));
    }

    printf("\nContents of array 2:");
    for(i = 0; i < SIZE; i++)
    {
        printf("\n%.2f", *(ptr2 + i));
    }


    return 0;
}