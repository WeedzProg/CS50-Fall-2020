/*
    CS-50 pset-2: Substitution cipher
    description: Message encryption, plaintext to ciphertext, alphabet lower / upper only, using alphabetical key encryption.
    @file substitution.c
    @author Jeremy B.
    @version 1.0 31 Oct 2020
*/

#include <stdio.h>
#include <cs50.h>
#include <string.h> //strlen
#include <ctype.h> //isalpha isalnum isdigit


int main(int argc, char *argv[])
{
    // check argument count and separating all different cases for different error messages.
    // even if some conditions can be concataned together which will disallow specific error message for a specific action.

    if (argc == 2)
    {
        // check argument lenght to 26 characters
        if (strlen(argv[1]) == 26)
        {
            //check if characters are alphabetical and convert it to lower.
            for (int i = 0; i < strlen(argv[1]); i++)
            {
                char check_alpha = tolower(argv[1][i]);

                //check if alphabetical
                if (isalpha(check_alpha))
                {
                    //check if characters are double or not by comparison on a basic of j = i + 1 "index after first value".
                    for (int j = i + 1; j < strlen(argv[1]); j++)
                    {
                        char check_double = tolower(argv[1][j]);

                        if (check_alpha == check_double)
                        {
                            printf("Error, duplicate found. Must not contain duplicate alphabet letters.\n");
                            printf("Usage reminder: ./substitution + alphabetical key of 26 characters.\n");
                            return 1;
                        }
                    }
                }

                else
                {
                    printf("Error, argument is not alphabetical characters.\n");
                    printf("Usage reminder: ./substitution + alphabetical key of 26 characters.\n");
                    return 1;
                }
            }
        }

        else
        {
            printf("Error, Argument vector is more or less than 26 characters.\n");
            printf("Usage reminder: ./substitution + alphabetical key of 26 characters.\n");
            return 1;
        }
    }

    else
    {
        printf("Error, There is more or less than 2 arguments.\n");
        printf("Usage reminder: ./substitution + alphabetical key without spaces.\n");
        return 1;
    }

    // ------------------------------------------------------
    // Usage of command line argument for running the program
    // ------------------------------------------------------
    // =====================Exemple==========================
    // ./substitution JTREKYAVOGDXPSNCUIZLFBMWHQ
    // plaintext:  hello, world
    // ciphertext: jrssb, ybwsp

    string plaintext = get_string("plaintext: ");

    //cipher and plaintext loop based on ASCII character integer for mapping plaintext to the chosen alphabetical key.

    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            plaintext[i] = toupper(argv[1][plaintext[i] - 65]);
        }
        else if (islower(plaintext[i]))
        {
            plaintext[i] = tolower(argv[1][plaintext[i] - 97]);
        }
    }
    printf("ciphertext: %s", plaintext);
    printf("\n");
    return 0;
}