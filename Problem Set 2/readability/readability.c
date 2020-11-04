/*
    CS-50 pset-2: Coleman-Liau's algorithm.
    description: evaluate a text / book to a specific reading grade.
    formula: index = 0.0588 * L - 0.296 * S - 15.8
    formula description: L == Letters count, S == Sentences count are average per 100 words each
    @file readability.c
    @author Jeremy B.
    @version 1.0 27 Oct 2020
*/

#include <stdio.h>
#include <cs50.h>
#include <string.h> //strlen()
#include <ctype.h> //isalpha() and isalnum()
#include <math.h>

void grade(string text_prompt);

int main(void)
{
    //prompt user to input text and print it out

    string text_prompt = get_string("Text: ");
    printf("\n");
    //get the grade, grade(string parameter)
    grade(text_prompt);
}


// ------------------------------------------------------
// Here starts the function grade calculation.
// ------------------------------------------------------


void grade(string text_prompt)
{
    //get text length for letter count
    int len = strlen(text_prompt);

    //for loop that count each totals
    int total_letter = 0, total_words = 1, total_sentences = 0;

    for (int letters_count = 0; letters_count < len; letters_count++)
    {
        //letters count in the text
        if (isalnum(text_prompt[letters_count]))
        {
            total_letter += 1;
        }

        //words count
        if (text_prompt[letters_count] == ' ')
        {
            total_words += 1;
        }

        //sentence count
        if (text_prompt[letters_count] == '.' || text_prompt[letters_count] == '!' || text_prompt[letters_count] == '?')
        {
            total_sentences += 1;
        }
    }

    //output each totals
    //printf("Total letters count: %i\n", total_letter);
    //printf("Total words count: %i\n", total_words);
    //printf("Total sentences count: %i\n", total_sentences);

    //average calculation
    float L = ((float) total_letter / (float) total_words) * 100;
    //printf("Letters / words average: %.0f\n", round(L));

    float S = ((float) total_sentences / (float) total_words) * 100;
    //printf("Sentences / words average: %.0f\n", round(S));

    //grade calculation
    float index = 0.0588 * L - 0.296 * S - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %0.f\n", round(index));
    }
}