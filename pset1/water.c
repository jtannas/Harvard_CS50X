/**  ----------------------------------------------------------------------------------------------------
*   Description:    Tells the user how many bottles of water their shower would use
*   Purpose:        pset1, Smart Water exercise
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
    *   Description:    Main Function, Converts the shower duration into a # of water bottles
    *   Purpose:        pset1, Smart Water exercise, main function
    *   Author:         Joel Tannas
    *   Date:           Nov 14, 2016
    *
    *   Bugs, Limitations, and Other Notes:
    *   - Per directions, assumes the user will provide a positive integer
    * ------------------------------------------------------------------------------------------------- */
 
    //Get the duration of the shower
    printf("minutes: ");
    int shower_minutes = GetInt();
    
    //Declare the conversion factors and apply them
    float Shower_GPM = 1.5;
    float Ounces_per_Gallon = 128.0;
    float Ounces_per_Bottle = 16.0;
    int bottles = shower_minutes * Shower_GPM * Ounces_per_Gallon / Ounces_per_Bottle;
    
    //Print the output to the user
    printf("bottles: %i\n", bottles);
    
    return 0;
}
 