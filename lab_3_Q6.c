/*-------------------------------------------------------------
    Program to convert user inputted temperature from one of F,
    C, or K to the other 2.

    Name: Nathan Daniel
    C24527823

    Date: 8-10-24
-------------------------------------------------------------*/

#include <stdio.h>

int main()
{

    float inputTemp, tempC, tempK, tempF;
    char tempUnit;


    printf("\n\nEnter a character to indicate the scale your temperature is in: F / C / K\n");
    scanf("%c", &tempUnit);

    printf("\nInput temperature to be converted as just a number: ");
    scanf("%f", &inputTemp);

    if (tempUnit == 'C' || tempUnit == 'c')
    {
        tempC = inputTemp;
        tempF = tempC * 9/5 + 32;
        tempK = tempC + 273.15;

    } else if (tempUnit == 'F' || tempUnit == 'f')
    {
        tempF = inputTemp;
        tempC = (tempF - 32) * 5/9;
        tempK = tempC + 273.15;

    } else if (tempUnit == 'K' || tempUnit == 'k')
    {
        tempK = inputTemp;
        tempC = tempK + 273.15;
        tempF = tempC * 9/5 + 32;

    } //end if

    printf("\nYour temperature in:\nCelsius: %9.1f degrees\nFarenheit: %9.1f degrees\nKelvin: %9.1f\n ", tempC, tempF, tempK);

} //end main
