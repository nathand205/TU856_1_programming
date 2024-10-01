/*
    Program to
    I. calculate surface area & volume of a closed box and
    II. calculate area of a circle.

    Name: Nathan Daniel
    [C24527823]

    Date: 1-10-2024
*/

#include <stdio.h>

int main()
{
    //initializing variables and assigning them values... H = Height, W = Width, L = Length, R = Radius, all in cm.
    float boxH;
    float boxL;
    float boxW;
    float boxVolume;
    float boxSurfaceArea;

    float circleR;
    float circleArea;

    boxH = 10;
    boxL = 11.5;
    boxW = 2.5;
    circleR = 4.8;


    //calculating box volume using [Volume = L*W*H]
    boxVolume = boxH * boxL * boxW;

    //calculating box surface area using [Surface Area = 2*(H*L + W*L + H*W)]
    boxSurfaceArea = 2 * (boxH * boxL + boxW * boxL + boxH * boxW);

    //displaying box information
    printf("\nBox dimensions are %.1f cm by %.1f cm by %.1f cm.\n\n", boxH, boxL, boxW);
    printf("Box volume is %.1f cm^3.\n", boxVolume);
    printf("Box surface area is %.1f cm^2.\n\n", boxSurfaceArea);
    

    //calculating circle area using [Area = R^2 * pi]
    circleArea = circleR * circleR * 3.14;

    //displaying circle information
    printf("\nCircle has a radius of %.1f cm.\n", circleR);
    printf("Circle area is %.1f cm^2.\n ", circleArea);

    return 0;
}
