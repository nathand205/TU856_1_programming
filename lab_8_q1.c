/*===================================================================
    
    DESCRIPTION: Program to create and initialise 2 arrays, then get
    the products of their elements and store them in a 3rd array.
    i.e: arrayProduct[1] = array1[1] * array2[1]

    AUTHOR: Nathan Daniel
    [C24527823]

    DATE: 19-11-24

===================================================================*/
#include<stdio.h>

#define ROWS 3
#define COLS 4

int main()
{
    //declare array which will store product
    int arrayProduct[ROWS][COLS];

    //declare and initialise arrays
    int array1[ROWS][COLS] = {  1, 2, 3, 4,
                                5, 6, 7, 8,
                                9,10,11,12  };

    int array2[ROWS][COLS] = {  2, 4, 6, 8,
                                10,12,14,16,
                                18,20,22,24  };
    
    

    //go through each row
    for(int i = 0; i < ROWS; i++)
    {
        //go through each column (in each row)
        for(int j = 0; j < COLS; j++)
        {
            //fill each element of arrayProduct with product of corresponding elements from arrays 1 & 2
            arrayProduct[i][j] = array1[i][j] * array2[i][j];
            //display operation to terminal
            printf("%2d x %2d = %3d\n", array1[i][j], array2[i][j], arrayProduct[i][j]);
        }
    }

    return 0;
}