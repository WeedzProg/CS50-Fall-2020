/*
    CS-50 pset-1: prompt user a number that build 2 mario like pyramid opposed by white spaces
    @file mario.c (more version)
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
    // For loop pyramid's rows build by new line iteration.
    for (int pyramid_row = 0; pyramid_row < pyramid_height; pyramid_row++)
    {
        // For loop, iterating the side space between border and left pyramid
        for (int side_space = pyramid_height - pyramid_row - 1; side_space > 0; side_space--)
        {
            printf(" ");
        }

        // For loop, left pyramid hash (#) iteration, incremented at each row
        for (int left_side = -1; left_side < pyramid_row; left_side++)
        {
            printf("#");
        }

        //gap between pyramids.
        printf("  ");

        // right pyramid, hash (#) iteration, incremented at each row.
        for (int right_side = -1; right_side < pyramid_row; right_side++)
        {
            printf("#");
        }
        printf("\n");
    }
}