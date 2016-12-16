/* -----------------------------------------------------------------------------
*   Description:    Solution for the pset2 'Parlez-vous francais' exercise
*   Purpose:        Learning more cipher algorithms
*   Author:         Joel Tannas
*   Date:           Nov 29, 2016
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
    *   Description:    Encrypts a string using a provided keyword (Vigenere)
    *   Purpose:        Completing the pset2 'Parlez-vous francais' exercise
    *   Author:         Joel Tannas
    *   Date:           Nov 29, 2016
    *
    *   Bugs, Limitations, and Other Notes:
    *   - forked much of the code from caeser.c of pset2
    * ------------------------------------------------------------------------*/
 
    // Check the # of command line args
    if (argc != 2)
    {
        printf("A single word is needed as an argument\n");
        return 1;
    }
    
    // Test the keyword for invalid characters
    int n_key = strlen(argv[1]);
    for (int i = 0; i < n_key; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Only alphabet characters are allowed in the keyword\n");
            return 1;
        }
    }
    
    // Prompt for a string & catch null
    string plain_msg = GetString();
    if (plain_msg == NULL)
    {
        return 1;
    }
    
    // Initialize useful numbers
    int n_msg = strlen(plain_msg);
    
    // Iterate through the letters, rotating them
    for (int i = 0, j = 0; i < n_msg; i++)
    {
        // Encipher letters, print anything else directly
        if (isalpha(plain_msg[i]))
        {
            // Grab a key letter from the keyword, reindex to 'A' = 0
            int k = argv[1][j % n_key];
            k = toupper(k) - 'A';
            j++;
            
            // Rotate the message
            printf("%c",ROTk(k, plain_msg[i])); 
        }
        else
        {
            printf("%c",plain_msg[i]); 
        }

    }
    
    // Newline & End
    printf("\n");
    return 0;
}

int ROTk(int key, int chr)
{
    /* -------------------------------------------------------------------------
    *   Description:    Rotates a letter chr by a given integer key
    *   Purpose:        Implementing encryption methods
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