#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count

typedef struct
{
    int winnerscore;
}
winner;

typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];
winner winners[MAX];

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
        winners[i].winnerscore = 0;
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
    //( TODO
    for(int i = 0; i < candidate_count; i++)
    {
       if(strcmp(candidates[i].name, name) == 0)
       {
        candidates[i].votes++;
        return true;
       }
    }
    return false;
}


void print_winner(void)
{

    //Keeping track fo the max vote tally
    int max_votes = 0;

    //Loopinf through the candidates to find the maximum vote tally for a single candidate
    for(int i = 0; i < candidate_count; i++)
    {
        if(candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    if(max_votes == 0)
    {
        printf("No candidate got any votes\n");
        return;
    }

    //Print all candidate names that got the maximum vote tally
    for(int i = 0; i < candidate_count; i++)
    {
        if(candidates[i].votes == max_votes){
            printf("%s\n", candidates[i].name);
        }
    }

    return;
}