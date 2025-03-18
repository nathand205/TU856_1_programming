/*
    PROGRAM DESCRIPTION: 
    rogram creates structure to hold pesonal information, then
    creates 2 instances of that structure, persons 1 and 2. Data
    is entered for person 1 and then copied to person 2 before
    being modified. Both people's information is displayed to user.

    AUTHOR: Nathan Daniel
    [C24527823]

    DATE: 18-03-2025s
*/

#include<stdio.h>
#include<string.h>


struct personal_data
{
    char firstName[32];
    char surName[32];
    char birthDate[11];
    char eyeColour[32];
    short weight;
    short height;
    char citizenship[64];
};


int main()
{

    struct personal_data person1, person2;


    // assign info for person 1
    strcpy(person1.firstName, "John");
    strcpy(person1.surName, "Johnson");
    strcpy(person1.birthDate, "14-12-1990");
    strcpy(person1.eyeColour, "Brown");
    strcpy(person1.citizenship, "Ireland");
    person1.weight = 80;
    person1.height = 170;

    // display person 1 information
    printf("\nPerson 1 personal data:\n=========================");
    printf("\nFirst Name: %s", person1.firstName);
    printf("\nLast Name: %s", person1.surName);
    printf("\nDate of Birth: %s", person1.birthDate);
    printf("\nEye Colour: %s", person1.eyeColour);
    printf("\nWeight: %d kg", person1.weight);
    printf("\nHeight: %d cm", person1.height);
    printf("\nCountry of Citizenship: %s\n", person1.citizenship);

    // copy all person 1 data to person 2
    person2 = person1;

    // modify data for person 2
    strcpy(person2.firstName, "Bob");
    strcpy(person2.eyeColour, "Green");
    strcpy(person2.birthDate, "01-08-1994");
    person2.weight = 105;
    person2.height = 180;

    // display person 2 information
    printf("\nPerson 2 personal data:\n=========================");
    printf("\nFirst Name: %s", person2.firstName);
    printf("\nLast Name: %s", person2.surName);
    printf("\nDate of Birth: %s", person2.birthDate);
    printf("\nEye Colour: %s", person2.eyeColour);
    printf("\nWeight: %d kg", person2.weight);
    printf("\nHeight: %d cm", person2.height);
    printf("\nCountry of Citizenship: %s\n\n", person2.citizenship);


    return 0;
}