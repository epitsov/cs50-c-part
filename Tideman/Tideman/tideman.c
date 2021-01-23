#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;
int winners[MAX];

bool cycle(int loser1, int winner1, int pairwinner);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }


    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        pairs[i].winner = get_int("winner:");
        pairs[i].loser = get_int("loser:");
        pair_count++;


    }
    lock_pairs();
    print_winner();
    return 0;
}

bool cycle(int loser1, int winner1, int pairwinner)
{
    printf("%i", loser1);
    printf("%i", winner1);
    printf("%i\n", pairwinner);
    if (loser1 == winner1)
    {
        return true;
    }
    for (int j = 0; j < pair_count; j++)
    {
        if (locked[loser1][j] == true)

        {
            return cycle(j, winner1, loser1);

        }

    }
    for (int i = loser1 + 1; i < pair_count; i++)
    {

        if (locked[pairwinner][i] == true)

        {
            return cycle(i, winner1, loser1);

        }
    }

    return false;
}
// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs()
{
    for (int i = 0; i < pair_count; i++)
    {
        if (!cycle(pairs[i].loser, pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
            winners[i] = pairs[i].winner;

        }
    }
}

// Print the winner of the election
void print_winner(void)
{
    int winner = 0;
    for (int row = 0; row < candidate_count; row++)
    {
        bool x = true;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][row] == true)
            {
                x = false;
            }
        }
        if (x)
        {
            winner = row;
        }
    }
    printf("%s\n", candidates[winner]);
    return;
}

