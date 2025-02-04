/*-------------------------------------------------------------

    DESCRIPTION: Program to take in 3 numbers from user, and
    using 2 nested functions, sum() and average():
    I. compute the sum,
    II. divide this result by 3 to get the mean average, and
    III. display the average to the user.

    AUTHOR: Nathan Daniel
    [C24527823]

    DATE: 04-02-2025

-------------------------------------------------------------*/


#include <stdio.h>

//declaring functions

void sum(float num1, float num2, float num3);
void average(float sum);


int main()
{
    float num1, num2, num3;

    // get user inputted numbers
    printf("\nPlease enter 3 numbers:\n");
    scanf("%f", &num1);
    scanf("%f", &num2);
    scanf("%f", &num3);

    // call sum() with these numbers as parameters, sum() will call average()
    sum(num1, num2, num3);

    return 0;
}

// defining functions

void sum(float num1, float num2, float num3)
{
    // passes sum of these 3 as a parameter into average()
    average(num1 + num2 + num3);
}


void average(float sum)
{
    // computes and displays the mean average
    printf("\nAverage of your 3 numbers is: %6.2f\n ", (sum / 3));
}
