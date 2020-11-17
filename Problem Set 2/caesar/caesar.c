/*
    CS-50 pset-2: Ceasar cipher
    description: Message encryption, plaintext to ciphertext, alphabet lower / upper only, integer key.
    formula: c.i = (p.i + k) % 26
    @file caesar.c
    @author Jeremy B.
    @version 1.0 30 Oct 2020
*/

#include <stdio.h>
#include <stdlib.h> // atoi
#include <cs50.h>
#include <string.h> //strlen
#include <ctype.h> //isalpha isalnum isdigit


int main(int argc, char *argv[])
{
    printf("argc is: %i\n", argc);
    if (argc == 2) //if argument ./caesar + key
    {
        for (int check_int = 0; check_int < strlen(argv[1]); check_int++)
        {
            if (isdigit(argv[1][check_int]))
            {
                //printf("it s an integer");
            }

            else
            {
                printf("Error, command line must be an integer argument.\n");
                printf("Usage: ./caesar + key\n");
                return 1;
            }
        }
    }

    else //if no argument or more than 1 argument
    {
        printf("Error, command line must contain an integer number argument.\n");
        printf("Usage: ./caesar + key\n");
        return 1;
    }
    // ------------------------------------------------------
    // Usage of command line argument for running the program
    // ------------------------------------------------------
    // =====================Exemple==========================
    // ./caesar 13
    // plaintext:  hello, world
    // ciphertext: uryyb, jbeyq

    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext: ");
    printf("\n");

    //cipher plaintext loop

    for (int i = 0, length = strlen(plaintext); i < length; i++)
    {
        if (isupper(plaintext[i]))
        {
            plaintext[i] = ((plaintext[i] - 65 + key) % 26) + 65;
        }
        else if (islower(plaintext[i]))
        {
            plaintext[i] = ((plaintext[i] - 97 + key) % 26) + 97;
        }
        //test one letter affected by key rotation per line iteration
        //printf("Letter: %c\n", plaintext[i]);
    }
    printf("ciphertext: %s", plaintext);
    printf("\n");
    return 0;
}