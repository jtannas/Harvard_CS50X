/* -----------------------------------------------------------------------------
*   Description:    Solution for the pset2 'Hail, Caesar!' exercise
*   Purpose:        Getting comfortable with character manipulation
*   Author:         Joel Tannas
*   Date:           Nov 28, 2016
*   
*   Licensing Info:
*   None
* ----------------------------------------------------------------------------*/

// Includes:
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototypes:
int ROTk(int key, int chr);

// Implementation:
int main(int argc, string argv[])
{
    /* -------------------------------------------------------------------------
    *   Description:    Encrypts a string using a provided key
    *   Purpose:        Completing the pset2 'Hail, Caesar!' exercise
    *   Author:         Joel Tannas
    *   Date:           Nov 28, 2016
    *
    *   Bugs, Limitations, and Other Notes:
    *   - the encryption key is provided via a command line argument
    *   - no other command line arguments will be acceptable
    *   - the string to encrypt is prompted for
    * ------------------------------------------------------------------------*/
 
    // Check command line args & retrieve the integer encryption key
    int k;

    switch (argc)
    {
        case 1:
            printf("An integer key is needed as an argument\n");
            return 1;
            break;
            
        case 2:
            k = atoi(argv[1]);
            break;
            
        default:
            return 1;
            break;
    }
    
    // Prompt for a string & catch null
    string plain_msg = GetString();
    if (plain_msg == NULL)
    {
        return 1;
    }
    
    // Iterate through rotating the chars, rotating them
    for (int i = 0, n = strlen(plain_msg); i < n; i++)
    {
        printf("%c",ROTk(k, plain_msg[i]));
    }
    
    // Newline & End
    printf("\n");
    return 0;
}

int ROTk(int key, int chr)
{
    /* -------------------------------------------------------------------------
    *   Description:    Rotates a letter chr by a given integer key
    *   Purpose:        Implementing rotating encryption methods
    *   Author:         Joel Tannas
    *   Date:           Nov 28, 2016
    *
    *   Bugs, Limitations, and Other Notes:
    *   - preserves upper and lowercase letters
    *   - other characters are unaffected
    *   - assumes ASCII 26 letter alphabet
    * ------------------------------------------------------------------------*/
    
    // Rotate by the provided key, maintaining upper & lower cases
    if (islower(chr))
    {
        return 'a' + (chr + key - 'a') % 26;
    }
    else if (isupper(chr))
    {
        return 'A' + (chr + key - 'A') % 26;
    }
    else
    {
        return chr;
    }
}