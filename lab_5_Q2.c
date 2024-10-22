/*====================================================================

    Decription:
    Program to modify a user-entered integer (userNumber) as follows:
    If userNumber is odd, userNumber = userNumber * 3 + 1.
    If userNumber is even, userNumber = userNumber / 2.
    The program stops when userNumber = 1.

    Author: Nathan Daniel
    C24527823

    Date: 22-10-2024

====================================================================*/

#include <stdio.h>

int main()
{
    // initialise variables
    int userNumber = 0;
    int i = 0;
    

    // display instructions to user and get input
    printf("\nThis program will modify an integer, n, as follows:\nIf n is even, n = n / 2.\nIf n is odd, n = (n * 3) + 1.\n\nThe program will stop when n = 1.\n\nEnter a value of n | n > 0.\n");
    scanf("%d", &userNumber);


    // if user's input is invalid, display error message and ask for new input
    while(userNumber < 1)
    {
        printf("\nError. Your number is not valid. Enter a value for n | n > 0.\n");
        scanf("%d", &userNumber);
    }// end while
    
    // repeats the mathematical operations until userNumber is 1. 'i' is number of steps to reach 1.
    for (i = 0; userNumber != 1; i++)
    {
        switch (userNumber % 2)
        {
            // if number is odd
            case 1:
            {
                printf("%3d * 3 + 1 =", userNumber);
                userNumber = (userNumber * 3) + 1;
                break;
            }
            // if number is even
            case 0:
            {
                printf("    %3d / 2 =", userNumber);
                userNumber = userNumber / 2;
                break;
            }
        }// end switch

        printf("%4d\n", userNumber);

    }// end for

    printf("\nSteps to reach 1: %d\n ", i);

    return 0;
}// end main