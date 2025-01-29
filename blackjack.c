
#include <stdio.h>
#include <stdlib.h>
#include <time.h>





char availableCards[4][13] = {  'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K',
                                'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K',
                                'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K',
                                'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'   };

//stores all player cards -- 5 players, maximum of 6 cards each. 6th player slot is reserved for the dealer
char tableCards[6][6];

void initialDeal();
void playerTurn();
void npcTurns();
void dealerTurn();
void deal(int seatNumber);
void printBoard(int dealerTurn);
void printResults();
int evaluateTotal(int seatNumber);

int main()
{
    

   

    //initialises tableCards to be filled with 0s
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            tableCards[i][j] = '0';
        }
    }

    initialDeal();
    printBoard(0);
    printf("\nInitial Deal. Press ENTER to proceed.\n\n");
    getchar();

    npcTurns();
    playerTurn();
    dealerTurn();

    printResults();



    return 0;
}

void printResults()
{
    int scores[6] = {evaluateTotal(0), evaluateTotal(1), evaluateTotal(2), evaluateTotal(3), evaluateTotal(4), evaluateTotal(5)};

    if(scores[5] < 21)
    {
        for(int i = 0; i < 5; i++)
        {
            if (scores[i] < scores[5])
            {
                scores[i] = -1;
            }
            else if (scores[i] == scores[5])
            {
                scores[i] = 0;
            }
            else if (scores[i] < 22)
            {
                scores[i] = 1;
            }
        }
    }
    else if (scores[5] > 21)
    {
        for(int i = 0; i < 5; i++)
        {
            if (scores[i] < 22)
            {
                scores[i] = 1;
            }
            else
            {
                scores[i] = -1;
            }
        }
    }
    else
    {
        for(int i = 0; i < 5; i++)
        {
            if (scores[i] != 21)
            {
                scores[i] = -1;
            }
            else
            {
                scores[i] = 0;
            }
        }
    }

    printf("     ");

    for(int i = 3; i < 8; i++)
    {
        if(scores[i % 5] == 1)
        {
            printf("        WIN          ");
        }
        else if (scores[i % 5] == 0)
        {
            printf("        TIE          ");
        }
        else
        {
            printf("        LOSS         ");
        }
    }

    printf("\n ");
    
}

void initialDeal()
{
    int i, j;

    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            deal(i);
        }
    }
}


void playerTurn()
{
    int handValue;
    int choice = 0;
    int stand = 0;

    do
    {
        printBoard(0);
        printf("\nYour Turn.\n1. Hit  |  2. Stand\n", evaluateTotal(0));

        //get player's choice
        do
        {  
            
            scanf("%d", &choice);

            if(choice != 1 && choice != 2)
            {
                printf("Invalid Selection! Enter 1 or 2.");
            }

        } while (choice != 1 && choice !=2);
        
        switch(choice)
        {
            case 1:
                deal(0);
                break;
            
            case 2:
                stand = 1;
                break;
        }

    } while (evaluateTotal(0) < 21 && stand == 0);

    printBoard(1);
}


void npcTurns()
{
    //player occupies seat 0
    int currentSeat = 1;
    int standNumber;


    for(currentSeat = 1; currentSeat < 5; currentSeat++)
    {
        standNumber = 14 + (rand() % 5);

        while (evaluateTotal(currentSeat) < standNumber)
        {
            deal(currentSeat);
        }
    }


}


void deal(int seatNumber)
{
    int k = 0;
    int suit, rank;

    srand(time(NULL));


    while(tableCards[seatNumber][k] != '0')
    {
        k++;
    }

    do
    {
        suit = rand() % 4;
        rank = rand() % 13;

    } while (availableCards[suit][rank] == '0');

        tableCards[seatNumber][k] = availableCards[suit][rank];

        //mark this card as dealt i.e. no longer in the deck
        availableCards[suit][rank] = '0';

}


int evaluateTotal(int seatNumber)
{
    int k = 0;
    char currentCard;
    int currentCardValue;
    int totalValue = 0;
    int numberOfAces = 0;


    while (tableCards[seatNumber][k] != '0')
    {
        currentCard = tableCards[seatNumber][k];

        switch(currentCard)
        {
            case 'T':
            case 'J':
            case 'Q':
            case 'K':
                currentCardValue = 10;
                break;
            
            case 'A':
                currentCardValue = 1;
                numberOfAces++;
                break;
            
            default:
                currentCardValue = currentCard - '0';
        }

        totalValue += currentCardValue;
        k++;
    }

    if(totalValue < 12 && numberOfAces > 0)
    {
        totalValue += 10;
    }

    return totalValue;
}


void dealerTurn()
{
    getchar();

    while(evaluateTotal(5) < 17)
    {
        printf("\nPress ENTER to take the dealer's turn.\n\n");
        getchar();

        deal(5);

        printBoard(1);
    }


}


void printBoard(int dealerTurn)
{
    int i;
    int k;
    int currentCard;

    printf("\n\n\n\n\n\n\n\n\n                                              ______________________                                          \n");
    printf("                                              |                    |                                          \n");
    printf("                                              |    ");

    if(dealerTurn == 1)
    {
        for(k = 0; k < 6; k++)
        {
            currentCard = tableCards[5][k];

            if(currentCard == '0')
            {
                printf("  ");
            }
            else
            {
                printf("%c ", currentCard);
            }
            
        }
    }
    else
    {
        printf("%c ", tableCards[5][0]);
        printf("[?]       ");
    }
    printf("    |\n");
    printf("                                              |--------------------|                                          \n");
    printf      ("                                              |       DEALER       |                                          \n");

    if(dealerTurn  == 0)
    {
        
        printf      ("                                              |      TOTAL: ??     |                                          \n");
    }
    else
    {
        
    printf      ("                                              |      TOTAL: %2d     |                                          \n", evaluateTotal(5));
    }

    printf      ("                                              |--------------------|                                          \n");

    printf("\n\n\n    __________________________________________________________________________________________________________\n");
    printf("    |                    |                    |                    |                    |                    |\n");
    for (i = 3; i < 8; i++)
    {
        printf("    |    ");

        for(k = 0; k < 6; k++)
        {
            currentCard = tableCards[i % 5][k];

            if(currentCard == '0')
            {
                printf("  ");
            }
            else
            {
                printf("%c ", currentCard);
            }
            
        }
    }
    printf("    |    \n");
    printf("    |--------------------|--------------------|--------------------|--------------------|--------------------|    \n");
    printf("    |        P1          |        P2          |     ---YOU---      |        P3          |        P4          |    \n");
    printf("    |      TOTAL: %2d     |      TOTAL: %2d     |      TOTAL: %2d     |      TOTAL: %2d     |      TOTAL: %2d     |    \n", evaluateTotal(3), evaluateTotal(4), evaluateTotal(0), evaluateTotal(1), evaluateTotal(2));
    printf("    |--------------------|--------------------|--------------------|--------------------|--------------------|\n ");
}