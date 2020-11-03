/*
    CS-50 pset-1: prompt user for name, then Hello + name
    @file hello.c
    @author Jeremy B.
    @version 1.0 25 Oct 2020
*/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prompt user for their names
    string name = get_string("What is your name?\n");

    //print out Hello + user's name
    printf("hello, %s\n", name);
}