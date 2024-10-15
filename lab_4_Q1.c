/*----------------------------------------------------------
    
    Program to take in a character from the user and check
    if it is a vowel or not.

    Author: Nathan Daniel
    [C24527823]

    Date: 15-10-2024

----------------------------------------------------------*/
#include<stdio.h>

int main()
{
    //intialise variable, assign value
    char userChar = ' ';

    //print instructions and get user character
    printf("\nEnter a letter:\n");
    scanf(" %c", &userChar);

    //switch statement checks if user character is a vowel or not
    switch (userChar)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        {
            printf("'%c' is a vowel.", userChar);
            break;
        }

        default:
        {
            printf("'%c' is not a vowel.", userChar);
            break;
        }

    } //end switch

    return 0;

} //end main