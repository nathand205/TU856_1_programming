/*=======================================================================

    DESCRIPTION: Program using puts() and fgets() to input and display
    user name as a string. String is modified to put spaces between
    each character using a loop.

    AUTHOR: Nathan Daniel
    [ C24527823 ]

    DATE: 25-02-2025

=======================================================================*/

#include<stdio.h>

//max name length that will display correctly = (SIZE / 2) - 1
#define SIZE 64

int main()
{
    char name[SIZE];
    char currentChar;
    char char2;

    printf("\nEnter your name: ");

    //get user inputted string
    fgets(name, sizeof(name), stdin);


    for (int i = 1; i < SIZE-1; i++)
    {
        //grab name[i]
        currentChar = name[i];

        //replace it with a space
        name[i] = ' ';

            //then shift all subsequent elements one to the right
            //so: a, b, c, d, e, f, ...  ----->  a,  , b, c, d, e, f, ...
            for(int j = i + 1; j < SIZE-1; j++)
            {
                char2 = name[j];

                name[j] = currentChar;

                currentChar = char2;
            }

        //additional increment to skip over space
        i++;
    }

    printf("\nName with spaces: ");
    puts(name);


    return 0;
}
