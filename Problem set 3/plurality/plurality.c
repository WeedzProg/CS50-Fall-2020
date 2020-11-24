/*
    CS-50 pset-2: Plurality election
    description: plurality vote for election. winner(s) == most obtained vote.
    @file plurality.c
    @author Jeremy B.
    @version 1.0 2 nov 2020
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO - iteration through candidate name using candidate count as "length", then compare strings to bool 0 for match or not.
    // if name match, vote incrementation.
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            //printf("name found\n");
            candidates[i].votes += 1;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO - check for highest vote value using candidate_count as "lenght", first vote value is compared to the next value
    // most vote value equal the highest value compared
    int highest_vote = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > highest_vote)
        {
            highest_vote = candidates[i].votes;
            //printf("Most votes for a candidate is: %i\n", highest_vote);
        }
    }

    // check for winner comparing each candidates vote amount against highest vote value that we kept above
    // if candidates are tied return multiple winners

    for (int j = 0; j < candidate_count; j++)
    {
        if (candidates[j].votes == highest_vote)
        {
            printf("%s\n", candidates[j].name);
        }
    }

    return;
}

