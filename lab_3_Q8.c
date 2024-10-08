/*-------------------------------------------------------
    Program to take user inputted floats and calculate:
    I. their sum and
    II. their mean average.

    Name: Nathan Daniel
    C24527823

    Date: 8-10-24
-------------------------------------------------------*/


#include <stdio.h>

int main()
{
    //initialise variables
    float num1, num2, num3;
    float meanAverage, sum;


    //instructions for user
    printf("\nEnter three real numbers.");
    
    //take in 3 floats from user input
    printf("\nFirst number: ");
    scanf("%f", &num1);

    printf("\nSecond number: ");
    scanf("%f", &num2);

    printf("\nThird number: ");
    scanf("%f", &num3);


    //calculate sum and mean average... [ mean average = (sum) / (number of numbers) ]
    sum = num1 + num2 + num3;
    meanAverage = (sum)/3;

    //display results
    printf("\n\nThe sum of %.3f, %.3f, and %.3f is:\n%.3f.", num1, num2, num3, sum);

    printf("\n\nThe mean average of these numbers is %.3f.\n ", meanAverage);

    return 0;

} //end main
