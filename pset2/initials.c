/*------------------------------------------------------------------------------
*   Description:    Solution for the pset2 'Initializing' exercise
*   Purpose:        Getting comfortable with strings
*   Author:         Joel Tannas
*   Date:           Nov 28, 2016
*   
*   Licensing Info:
*   None
* ----------------------------------------------------------------------------*/

// Includes:
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// Prototypes:

// Implementation:
int main(void)
{
    /* -------------------------------------------------------------------------
    *   Description:    Outputs uppercase initials from a provided name
    *   Purpose:        Completing the pset2 'Initializing' exercise
    *   Author:         Joel Tannas
    *   Date:           Nov 28, 2016
    *
    *   Bugs, Limitations, and Other Notes:
    *   - Provided Design Assumption: only letters and single spaces
    *       -- Does not handle hyphenated names correctly
    *   - Defining characteristics of an initial:
    *       -- the first letter of a name (other chars are not valid)
    *       -- therefore, is either the 1st letter or is preceeded by a space
    *       -- isalpha will be used to check for letters
    * ------------------------------------------------------------------------*/
 
    // Prompt the user for their full name & catch null
    string full_name = GetString();
    if (full_name == NULL)
    {
        return 1;
    }
    
    // Check the first char to see if it's a letter, output if true
    if (isalpha(full_name[0]))
    {
        printf("%c",toupper(full_name[0]));
    }
    
    // Iterate through the remaining letters, testing & printing
    for (int i = 1, n = strlen(full_name); i < n; i++)
    {
        if (full_name[i - 1] == ' ' && isalpha(full_name[i]))
        {
            printf("%c",toupper(full_name[i]));
        }
    }
    
    // Newline & End
    printf("\n");
    return 0;
}
