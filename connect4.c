/*

*/

#include<stdio.h>

#define COLS 7
#define ROWS 6

int main()
{
    char gameBoard[ROWS][COLS];

    int i = 0;
    int j = 0;
    int k = 0;

    char currentPlayer = 'O';
    char winningPlayer = '.';

    int selectedCol = 0;
    int selectedRow = 0;
    short validSelection = 0;

    int consecutivePieces = 0;

    //fill board with . to setup
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            gameBoard[i][j] = '.';
        }
    }

    //print board
    for(i = 0; i < ROWS; i++)
    {
        printf("\n\n");

        for(j = 0; j < COLS; j++)
        {
            printf("%4c", gameBoard[i][j]);
        }
    }

    while (winningPlayer == '.')
    {

        do
        {
            printf("\n\nChoose a column 1 - %d: ", COLS);
            scanf(" %d", &selectedCol);

            selectedCol--;
            i = ROWS - 1;

            while(gameBoard[i][selectedCol] != '.' && i > -1)
            {
                i--;
            }

            if(i > -1)
            {
                gameBoard[i][selectedCol] = currentPlayer;

                selectedRow = i;
                validSelection = 1;
            }
            else
            {
                printf("Invalid selection: column full!");
            }

        } while (validSelection == 0);

        validSelection = 0;


        //--------------------------------check for win--------------------------------

        //check vertical
        consecutivePieces = 0;
        for(int k = 0; k < ROWS; k++)
        {
            if(gameBoard[k][selectedCol] == currentPlayer)
            {
                consecutivePieces++;

                if(consecutivePieces == 4)
                {
                    winningPlayer = currentPlayer;
                }
            }
            else
            {
                consecutivePieces = 0;
            }
        }

        //check horizontal
        consecutivePieces = 0;
        for(j = 0; j < COLS; j++)
        {
            if(gameBoard[selectedRow][j] == currentPlayer)
            {
                consecutivePieces++;

                if(consecutivePieces == 4)
                {
                    winningPlayer = currentPlayer;
                }
            }
            else
            {
                consecutivePieces = 0;
            }
        }

        //----------------check diagonal TL --> BR ----------------

        //position "cursor" at the top LEFT of diagonal current piece is on
        j = selectedCol;
        i = selectedRow;
        while( i > 0 )
        {
            if(j > 0)
            {
                j--;
            }
            else
            {
                break;
            }

            i--;
        }

        consecutivePieces = 0;
        for(i; i < ROWS; i++)
        {
            if(gameBoard[i][j] == currentPlayer)
            {
                consecutivePieces++;

                if(consecutivePieces == 4)
                {
                    winningPlayer = currentPlayer;
                }
            }
            else
            {
                consecutivePieces = 0;
            }

            j++;

            if(j > COLS)
            {
                break;
            }
        }


        //----------------check diagonal TR --> BL----------------

        //position "cursor" at the top RIGHT of diagonal current piece is on
        j = selectedCol;
        i = selectedRow;
        while( i > 0 )
        {
            if(j < COLS)
            {
                j++;
            }
            else
            {
                break;
            }

            i--;
        }

        consecutivePieces = 0;
        for(i; i < ROWS; i++)
        {
            if(gameBoard[i][j] == currentPlayer)
            {
                consecutivePieces++;

                if(consecutivePieces == 4)
                {
                    winningPlayer = currentPlayer;
                }
            }
            else
            {
                consecutivePieces = 0;
            }

            j--;

            if(j < 0)
            {
                break;
            }
        }


        //change current player

        if (currentPlayer == 'O')
        {
            currentPlayer = '#';
        }
        else
        {
            currentPlayer = 'O';
        }
        
         //print board
        for(i = 0; i < ROWS; i++)
        {
            printf("\n\n");

            for(j = 0; j < COLS; j++)
            {
                printf("%4c", gameBoard[i][j]);
            }
        }
    }

    printf("\n\nPLAYER %c WINS!", winningPlayer);

    return 0;
}

