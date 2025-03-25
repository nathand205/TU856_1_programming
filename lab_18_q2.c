/*
    DESCRIPTION: Program to store passenger details and display them in an array of structures.

    AUTHOR: Nathan Daniel
    C24527823

    DATE: 25-03-2025
*/

#include<stdio.h>
#include<string.h>

struct passenger_details
{
    char airline[64];
    char flightNo[16];
    char surName[64];
    char seatNo[8];
    char destination[64];
    char baggageAmount[5];
};

// parameters: passenger #, airline, flight, name, seat, destination, bags
void fillDetails(short, char[], char[], char[], char[], char[], char[]);
void getDetails();
void printDetails(short);


struct passenger_details passengers[2];

int main()
{
    getDetails();
    getDetails();

    printDetails(0);
    printDetails(1);



    return 0;
}

void getDetails()
{
    // will only be intialised once
    static short passengerNo = 0;

    char airline[64];
    char flightNo[16];
    char surName[64];
    char seatNo[8];
    char destination[64];
    char baggageAmount[16];

    // get info from user
    printf("Airline Name:       ");
    fgets(airline, 64, stdin);
    airline[strcspn(airline, "\n")] = '\0';

    printf("Flight No:          ");
    fgets(flightNo, 16, stdin);
    flightNo[strcspn(flightNo, "\n")] = '\0';

    printf("Passenger Surname:  ");
    fgets(surName, 64, stdin);
    surName[strcspn(surName, "\n")] = '\0';

    
    printf("Destination:        ");
    fgets(destination, 64, stdin);
    destination[strcspn(destination, "\n")] = '\0';


    printf("Baggage Amount:     ");
    fgets(baggageAmount, 16, stdin);
    baggageAmount[strcspn(baggageAmount, "\n")] = '\0';

    printf("Seat No:            ");
    fgets(seatNo, 8, stdin);
    seatNo[strcspn(seatNo, "\n")] = '\0';



    // fill structure with info
    fillDetails(passengerNo, airline, flightNo, surName, seatNo, destination, baggageAmount);
    

    // next time this function runs, the next element in the array will be modified
    passengerNo++;

}

void fillDetails(short passengerNo, char airline[], char flightNo[], char surName[], char seatNo[], char destination[], char baggageAmount[])
{
    // fill the relevant passenger's details
    strcpy(passengers[passengerNo].airline, airline);
    strcpy(passengers[passengerNo].flightNo, flightNo);
    strcpy(passengers[passengerNo].surName, surName);
    strcpy(passengers[passengerNo].destination, destination);
    strcpy(passengers[passengerNo].seatNo, seatNo);
    strcpy(passengers[passengerNo].baggageAmount, baggageAmount);
}

void printDetails(short passengerNo)
{
    printf("\n\n\nPassenger No. %d", passengerNo + 1);
    printf("\nAirline Name:       %s", passengers[passengerNo].airline);
    printf("\nDestination:        %s", passengers[passengerNo].destination);
    printf("\nFlight No:          %s", passengers[passengerNo].flightNo);
    printf("\nPassenger Surname:  %s", passengers[passengerNo].surName);
    printf("\nSeat No:            %s", passengers[passengerNo].seatNo);
    printf("\nNumber of Bags:     %s", passengers[passengerNo].baggageAmount);
}