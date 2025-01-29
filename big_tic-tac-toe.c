#include<stdio.h>

#define X 3
#define Y 3

char gameBoard[X][X][Y][Y];
int currentGame = 4;
char currentPlayer = 'X';
char winningPlayer = '.';
char cellState[3][3] =   {  '.','.','.',
                            '.','.','.',
                            '.','.','.'  };

char winXDisplay[3][3] = {  ' ',' ',' ',
                            ' ','X',' ',
                            ' ',' ',' '  };

char winODisplay[3][3] = {  ' ',' ',' ',
                            ' ','O',' ',
                            ' ',' ',' '  };

char drawDisplay[3][3] = {  ' ',' ',' ',
                            ' ','=',' ',
                            ' ',' ',' '  };

short row;
short col;
short subRow;
short subCol;

int gameRound = 1;


void intialiseBoard()
{
    for (int i = 0; i < X; i++)//row of big game
    {
        for(int k = 0; k < X; k++)//row of small game
        {
            for(int j = 0; j < Y; j++)//column of big game
            {
                for(int l = 0; l < Y; l++)//column of small game
                {
                    gameBoard[i][j][k][l] = '.';
                }
            }
        }
    }
}

void printBoard()
{
    int a, b, cG;
    int cellCount = 1;

    printf("\n\n\n\n");
    for (int i = 0; i < X; i++)//row of big game
    {
        printf("===================================================\n|               ||               ||               |\n");

        for(int k = 0; k < X; k++)//row of small game
        {
            for(int j = 0; j < Y; j++)//column of big game
            {
                printf("|");
                for(int l = 0; l < Y; l++)//column of small game
                {
                    
                    //convert current game 0-8 to grid reference (a,b) | 0 <= a <= 2, 0 <= b <= 2
                    {
                        cG = currentGame;
                    
                        b = cG % 3;
                        
                        for(a = 0; cG > 2; a++)
                        {
                            cG = cG - 3;
                        }
                    }

                    //if this game is no longer playable
                    if (cellState[i][j] == 'X')
                    {
                        printf("%4c", winXDisplay[k][l]);
                    }
                    else if (cellState[i][j] == 'O')
                    {
                        printf("%4c", winODisplay[k][l]);
                    }
                    else if (cellState[i][j] == '=')
                    {
                        printf("%4c", drawDisplay[k][l]);
                    }
                    // if this is the current game
                    else if(i == a && j == b)
                    {
                        if(gameBoard[i][j][k][l] == '.')
                        {
                            printf("%4d", cellCount);
                        }
                        else
                        {
                            printf("%4c", gameBoard[i][j][k][l]);
                        }

                        cellCount++;
                    }
                    else
                    {
                        printf("%4c", gameBoard[i][j][k][l]);
                    }

                }
                printf("   |");
            }
            printf("\n|               ||               ||               |\n");
        }
        
    }
    printf("===================================================");
    printf("\nActive game: %d                 %c's Turn. | Round:%2d", currentGame + 1, currentPlayer, gameRound);

}

void switchPlayer()
{
    if(currentPlayer == 'X')
    {
        currentPlayer = 'O';
    }
    else
    {
        currentPlayer = 'X';
        gameRound++;
    }
}

void getInput()
{
    int selectedCell;
    short isValidInput = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int n = 0;
    int cG;
    int sC;


    //check if current game is decided already:
    do
    {
        //convert int 0-8 to grid reference (m,n) | 0 <= m <= 2, 0 <= n <= 2
        cG = currentGame;
        n = cG % 3;

        for(m = 0; cG > 2; m++)
        {
            cG = cG - 3;
        }

        if(cellState[m][n] != '.')
        {
            printf("\nGame %d is already decided.\nChoose any open game to play in 1-9: ", currentGame + 1);
            scanf(" %d", &currentGame);
            currentGame--;
            
            printBoard();
        }
    } while(cellState[m][n] != '.');

    do
    {
        printf("\nChoose a cell 1-9: ");
        scanf(" %d", &selectedCell);
        selectedCell--;

        
    
        //convert int 0-8 to grid reference (i,j) | 0 <= i <= 2, 0 <= j <= 2
            cG = currentGame;
            j = cG % 3;

            for(i = 0; cG > 2; i++)
            {
                cG = cG - 3;
            }

        //convert int 0-8 to grid reference (k,l) | 0 <= k <= 2, 0 <= l <= 2
            sC = selectedCell;
            l = sC % 3;

            for(k = 0; sC > 2; k++)
            {
                sC = sC - 3;
            }

        if( !(gameBoard[i][j][k][l] == 'X' || gameBoard[i][j][k][l] == 'O') )
        {
            isValidInput = 1;
        }
        else
        {
            printf("\nCell full! Invalid move.");
        }

    } while (isValidInput == 0);

    row = i;
    col = j;
    subRow = k;
    subCol = l;

    gameBoard[row][col][subRow][subCol] = currentPlayer;
    currentGame = selectedCell;

}

void checkForCellWin()
{
    int i;
    int j;
    int charCount = 0;

    if (cellState[row][col] == '.')
    {
         //check vertical win
        if(gameBoard[row][col][0][subCol] == gameBoard[row][col][1][subCol] && gameBoard[row][col][1][subCol] == gameBoard[row][col][2][subCol] && gameBoard[row][col][0][subCol] != '.')
        {
            cellState[row][col] = currentPlayer;
        }
        //check horizontal win
        else if(gameBoard[row][col][subRow][0] == gameBoard[row][col][subRow][1] && gameBoard[row][col][subRow][2] == gameBoard[row][col][subRow][1] && gameBoard[row][col][subRow][0] != '.')
        {
            cellState[row][col] = currentPlayer;
        }
        //check TL --> BR win
        else if(gameBoard[row][col][0][0] == gameBoard[row][col][1][1] && gameBoard[row][col][1][1] == gameBoard[row][col][2][2] && gameBoard[row][col][0][0] != '.')
        {
            cellState[row][col] = currentPlayer;
        }
        //check BL --> TR win
        else if(gameBoard[row][col][2][0] == gameBoard[row][col][1][1] && gameBoard[row][col][1][1] == gameBoard[row][col][0][2] && gameBoard[row][col][2][0] != '.')
        {
            cellState[row][col] = currentPlayer;
        }
        //check for draw
        else
        {
            for(i = 0; i < 3; i++)
            {
                for(j = 0; j < 3; j++)
                {
                    if(gameBoard[row][col][i][j] != '.')
                    {
                        charCount++;
                    }
                }
            }

            if(charCount == 9)
            {
                cellState[row][col] = '=';
            }
        }
    }
   
    
}

void checkForGameWin()
{

    //check vertical win
    if(cellState[0][0] == cellState[1][0] && cellState[1][0] == cellState[2][0] && cellState[0][0] != '.')
    {
        winningPlayer = currentPlayer;
    }
    else if(cellState[0][1] == cellState[1][1] && cellState[1][1] == cellState[2][1] && cellState[0][1] != '.')
    {
        winningPlayer = currentPlayer;
    }
    else if(cellState[0][2] == cellState[1][2] && cellState[1][2] == cellState[2][2] && cellState[0][2] != '.')
    {
        winningPlayer = currentPlayer;
    }

    //check horizontal win
    else if(cellState[0][0] == cellState[0][1] && cellState[0][2] == cellState[0][1] && cellState[0][0] != '.')
    {
        winningPlayer = currentPlayer;
    }
    else if(cellState[1][0] == cellState[1][1] && cellState[1][2] == cellState[1][1] && cellState[1][0] != '.')
    {
        winningPlayer = currentPlayer;
    }
    else if(cellState[2][0] == cellState[2][1] && cellState[2][2] == cellState[2][1] && cellState[2][0] != '.')
    {
        winningPlayer = currentPlayer;
    }

    //check TL --> BR win
    else if(cellState[0][0] == cellState[1][1] && cellState[1][1] == cellState[2][2] && cellState[0][0] != '.')
    {
        winningPlayer = currentPlayer;
    }
    //check BL --> TR win
    else if(cellState[2][0] == cellState[1][1] && cellState[1][1] == cellState[0][2] && cellState[2][0] != '.')
    {
        winningPlayer = currentPlayer;
    }

}

int main()
{
    intialiseBoard();
    printBoard();

    do
    {
        getInput();
        checkForCellWin();
        checkForGameWin();
        switchPlayer();
        printBoard();

    } while(winningPlayer == '.');

    printf("\n\n-------------------PLAYER %c WINS!-------------------\n\n ", winningPlayer);

    return 0;
}