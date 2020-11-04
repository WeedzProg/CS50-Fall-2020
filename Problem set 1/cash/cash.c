/*
    CS-50 pset-1: Greedy algorithm.
    description: Output how many coins should been given back to the customers. not how many of each coins.
    @file cash.c
    @author Jeremy B.
    @version 1.0 25 Oct 2020
*/

#include <cs50.h>
#include <stdio.h>
#include <math.h>

//initialize owed() function
int owed(int cent);

int main(void)
{
    //Prompt user the owed amount of money
    float change;

    do
    {
        change = get_float("Enter the change amount owed: $");
    }
    while (change < 0);

    //transform the float input in a round integer
    int cent = round(change * 100);

    //pass 'cent' argument in owed() for calculation and return result
    printf("Total Number of coins owed: %i\n", owed(cent));
}

// ------------------------------------------------------
// Here starts the function for "owed coins" calculation.
//      -----------------------------------------
// calculate the number of coins to give back from those
// quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢)
// ------------------------------------------------------

int owed(int cent)
{
    int coins_back = 0;

    while (cent > 0)
    {
        if (cent >= 25)
        {
            cent -= 25;
            coins_back++;
        }
        else if (cent >= 10)
        {
            cent -= 10;
            coins_back++;
        }
        else if (cent >= 5)
        {
            cent -= 5;
            coins_back++;
        }
        else if (cent >= 1)
        {
            cent -= 1;
            coins_back++;
        }
    }

    //output result
    return coins_back;
}