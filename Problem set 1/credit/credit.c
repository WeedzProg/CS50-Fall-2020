/*
    CS-50 pset-1: Luhn's algorithm.
    description: check various credit cards company if card is valid or invalid by checking Credit card number
    @file credit.c
    @author Jeremy B.
    @version 1.0 28 Oct 2020
*/

#include <stdio.h>
#include <cs50.h>

void check_card(long get_number);

int main(void)
{
    //prompt user
    long get_number = get_long("Check your card Number: ");

    //pass input into card checking function
    check_card(get_number);
}

// --------------------------------------------------------------
// Function for checking validity or invalidity of a credit card.
// Luhn's algorithm
// --------------------------------------------------------------

//====================================================================
// For testing, here is a list:
//====================================================================
// Amex 15 digits start with 34 or 37
// Mastercard 16 digits start with 51 52 53 54 or 55
// visa 13 and 16 digits start with 4
//====================================================================
// amex test 378282246310005 371449635398431
// mastercard test 5555555555554444  5200828282828210 5105105105105100
// visa test 4003600000000014 4000056655665556 4242424242424242
// if total sum % 10 == 0 -> valid. else invalid
//====================================================================

void check_card(long get_number)
{
    //while loop counting digits length + selecting first two digits of the credit card number
    //ultimately card_digits' last iteration equal to the first digit of the card, serves to check visa cards

    long card_digits = get_number;
    int length = 1;
    int first_digits = 0;

    while (card_digits > 10)
    {
        card_digits = card_digits / 10;
        if (card_digits < 1000 && card_digits > 100)
        {
            //get first two digits
            first_digits = card_digits;
            first_digits /= 10;
            //go back to last iteration and get first one digit
        }
        //add one to length
        length++;
    }

    //check sum from last digit jumping over the previous one each time
    //long from_last = card_number;
    int sum = 0;
    long card_numb2 = get_number;
    while (card_numb2 > 0)
    {
        long from_last = card_numb2 % 10;
        sum = sum + from_last;
        card_numb2 = card_numb2 / 100;
    }

    long last2 = 0;
    long last3 = 0;
    int sum2 = 0;
    long card_numb3 = get_number / 10;
    while (card_numb3 > 0)
    {
        last3 = card_numb3 % 10;
        last2 = last3 * 2;
        sum = sum + (last2 % 10) + (last2 / 10);
        card_numb3 = card_numb3 / 100;
    }

    //Check validity/ invalidity. Sum combined to firsts digits of credit card
    if (sum % 10 == 0)
    {
        //Amex check
        if ((first_digits == 34 || first_digits == 37) && length == 15)
        {
            printf("AMEX\n");
        }
        //Mastercard check
        else if ((first_digits >= 51 && first_digits <= 55) && length == 16)
        {
            printf("MASTERCARD\n");
        }
        //Visa check
        else if ((length == 13 || length == 16) && card_digits == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}