/**  ----------------------------------------------------------------------------------------------------
*   Description:    Greedy Algorithm for making coinage change
*   Purpose:        Completing the 'Time for Change' portion of pset 1
*   Author:         Joel Tannas
*   Date:           Nov 14, 2016
*   
*   Licensing Info:
*   None
* ----------------------------------------------------------------------------------------------------- */

#include <stdio.h>
#include <cs50.h>
#include <math.h>

//Explicit Function Declarations before main:
// - none

int main (void)
{
    /*  -------------------------------------------------------------------------------------------------
    *   Description:    Determine the minimum numbers of coins to make a given amount of change
    *   Purpose:        Demonstrating greedy algorithms
    *   Author:         Joel Tannas
    *   Date:           Nov 14, 2016
    *
    *   Bugs, Limitations, and Other Notes:
    *   - Assumes coins for 0.25$, 0.10$, 0.05$, and 0.01$
    *   - Assumes an input in dollars, then rounds to the nearest penny
    *   - Assumes the input fits within a float
    * ------------------------------------------------------------------------------------------------- */
 
    //Get the amount of change and convert it to an int of cents
    float change;
    do
    {
        printf("Please input the amount of change in dollars: ");
        change = GetFloat();
    }
    while (change < 0);
    int cents = round(100 * change);
        
    /*  Concept: From the largest coin to the smallest...
    * 1) Divide the number of cents by the amount of the coin using integer math (which truncates decimals) to find how many fit. 
    * 2) Add the result of step 1 to the number of coins.
    * 3) Use the modulus operator to find how many cents remain after removing as many of the coin as is possible. */
    int coins = 0;
    
    //25 Cent portion
    coins += (cents / 25);
    cents %= 25;
    
    //10 Cent portion
    coins += (cents / 10);
    cents %= 10;
    
    //5 Cent portion
    coins += (cents / 5);
    cents %= 5;
    
    //1 Cent portion
    coins += (cents / 1);
    cents %= 1;
    
    //Verify that full change was made and output the number of coins needed
    if (cents == 0)
    {
        printf("%i\n",coins);
    }
    else
    {
        printf("An error was encountered and full change was not made \n");
    }
    
    return 0;
}
