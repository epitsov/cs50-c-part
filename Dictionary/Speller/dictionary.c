// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include "dictionary.h"
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;

// Number of buckets in hash table
const unsigned int N = 55;
int words = 0;
// Hash table
node* table[N];

// Returns true if word is in dictionary else false
bool check(const char* word)
{
    int num = hash(word);

    if (table[num] == NULL)
    {
        return false;
    }
    node* cursor = NULL;
    while (table[num]->next != NULL)
    {
        cursor = table[num]->next;
        if (strcasecmp(word, table[num]->word) == 0)
        {
            return false;
        }
        else
        {
            table[num] = cursor;
        }
    }

    return true;
}

// Hashes word to a number
// Used DJ2B function by http://www.cse.yorku.ca/~oz/hash.html
unsigned int hash(const char* word)
{
    unsigned int hash = 5381;
    int c;

    while ((c = *word++))
    {
        hash = ((hash << 5) + hash) + tolower(c);
    }
    return hash % N;

}

// Loads dictionary into memory, returning true if successful else false
bool load(const char* dictionary)
{
    FILE* file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("File could not be opened.\n");
        return false;
    }
    char word1[LENGTH + 1];
    while (fscanf(file, "%s", word1) != EOF)
    {
        node* n = malloc(sizeof(node));
        if (n == NULL)
        {
            unload();
            return 1;
        }
        strcpy(n->word, word1);
        n->next = NULL;
        words++;
        int index = hash(word1);
        if (table[index] == NULL)
        {
            table[index] = n;
        }
        else
        {
            n->next = table[index];
            table[index] = n;
        }
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return words;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node* tmp = NULL;
        node* cursor = table[i];
        while (cursor != NULL)
        {
            tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
