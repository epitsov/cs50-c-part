#include <cs50.h>
#include <stduio.h>
typedef struct
{
    string name;
    string number;
}
person;
int main(void)
{
    person people[4];
    people[0].name = "emma";
    people[0].number = "617-555-0100";
    people[1].name = "ivan";
    people[1].number = "618-555-0100";
    people[2].name = "gosho";
    people[2].number = "625-555-0120";
}