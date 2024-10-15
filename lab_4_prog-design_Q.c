/*
    Program to take in user integer and check if
    it is a prime number.
    (Question from program design lecture yesterday)

    Author: Nathan Daniel
    [C24527823]

    Date: 15-10-2024
*/

#include<stdio.h>

// additional libraries for sqrt() function and boolean variable type
#include<math.h>
#include<stdbool.h>


int main()
{
    unsigned int userInt = 0;
    unsigned int sqrtUserInt;
    unsigned int d = 3;
    bool isPrime = false;
    
    //ask for user to input number
    printf("\nEnter a positive integer:\n");
    scanf(" %ld", &userInt);

    sqrtUserInt = sqrt(userInt);

    //check if number is even
    if(userInt % 2 != 0)
    {
        // while number is not divisible by d
        while( userInt % d != 0)
        {
            // set d to next odd number
            d += 2;
             
            // if d gets to be greater than the square root of
            // userInt without dividing it, userInt must be prime.
            
            if( d > sqrtUserInt )
            {
                isPrime = true;
                break;
            } // end if
        } // end while
    } // end if

    if(isPrime == false)
    {
        printf("\n%ld is not a prime number.\n ", userInt);
    }
    else
    {
        printf("\n%ld is a prime number.\n ", userInt);
    } // end if

    return 0;

} // end main