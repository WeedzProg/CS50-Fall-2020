/*
    CS-50 pset-1: prompt user a number that build a one side mario like pyramid
    @file mario.c (less version)
    @author Jeremy B.
    @version 1.0 25 Oct 2020
*/

#include <cs50.h>
#include <stdio.h>

//initialize the make_pyramid function built at the bottom
void make_pyramid(int pyramid_height);

int main(void)
{
    // prompt user height + guardian pattern against malicious inputs
    int pyramid_height;
    do
    {
        pyramid_height = get_int("Enter the height you want for a Mario's pyramid: ");
    }
    while (pyramid_height < 1 || pyramid_height > 8);

    //Call make_pyramid function
    make_pyramid(pyramid_height);
}



// ------------------------------------------------------
// Here starts the make_pyramid() function
// ------------------------------------------------------

void make_pyramid(pyramid_height)
{
    // For loop, do a new line at each iteration
    for (int pyramid_level = 0; pyramid_level < pyramid_height; pyramid_level++)
    {
        // For loop, iterating the side space between border and pyramid
        for (int side_space = pyramid_height - pyramid_level - 1; side_space > 0; side_space--)
        {
            printf(" ");
        }

        // For loop, iterating hash (#) incremented at each row
        for (int pyramid_row = -1; pyramid_row < pyramid_level; pyramid_row++)
        {
            printf("#");
        }
        printf("\n");
    }
}
