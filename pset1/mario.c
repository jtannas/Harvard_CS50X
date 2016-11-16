/**  ----------------------------------------------------------------------------------------------------
*   Description:    Creates a half-pyramid of blocks of a specified height
*   Purpose:        Completing the 'Itsa Mario' exercise of pset1
*   Author:         Joel Tannas
*   Date:           Nov 14, 2016
*   
*   Licensing Info:
*   None
* ----------------------------------------------------------------------------------------------------- */

#include <stdio.h>
#include <cs50.h>

//Explicit Function Declarations before main:
// none

int main (void)
{
    /*  -------------------------------------------------------------------------------------------------
    *   Description:    Prints a half-pyramis made of # marks
    *   Purpose:        
    *   Author:         Joel Tannas
    *   Date:           Nov 14, 2016
    *
    *   Bugs, Limitations, and Other Notes:
    *   - For Height = 0, there is no pyramid
    *   - 
    * ------------------------------------------------------------------------------------------------- */
 
    //Get the Height of the Pyramid from the user
    int Height;
    do
    {
        printf("Height: ");
        Height = GetInt();
    }
    while ((Height < 0) || (Height > 23));
    
    //Set the width of the pyramid
    int Width = Height + 1;
    
    //Loop through the pyramid rows, top to bottom
    for (int row = 0; row < Height; row++)
    {
        //Calculate the number of blocks and blanks
        int Blocks = row + 2;
        int Blanks = Width - Blocks;
        
        //Create all the blanks on the given row
        for (int i = 0; i < Blanks; i++)
        {
            printf(" ");
        }
        
        //Create all the blocks on the given row
        for (int j = 0; j < Blocks; j++)
        {
            printf("#");
        }
        
        //Newline to go to the next row
        printf("\n");
    }

    return 0;
}