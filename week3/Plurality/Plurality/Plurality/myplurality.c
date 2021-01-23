#include <stdio.h>
#include <cs50.h>
#include <string.h>
typedef struct
{
    string name;
    int count;
}
candidate;
candidate candidates[9];
bool vote(string name);
void print_winner();
int main(int argc, string argv[])
{
    for (int i = 1; i < 9; i++)
    {
        candidates[i - 1].name = argv[i];
    }
    int votes = get_int("Number of voters: ");
    for (int i = 0; i < votes; i++)
    {
        string name = get_string("Vote: ");
        if (vote(name) == false)
        {
            printf("Invalid vote.\n");
        }
    }
    print_winner();


}
bool vote(string name)
{
    for (int i = 0; i < 9; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].count += 1;
            return true;
        }
    }
    return false;
}
void print_winner()
{
    int counter = 0;
    for (int i = 0; i < 9; i++)
    {
        if (candidates[i].count >= counter)
        {
            counter = candidates[i].count;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (candidates[i].count == counter)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}