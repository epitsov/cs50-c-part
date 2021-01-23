#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("./substitution key\n");
        return 1;
    }
    int counter = 0;
    for (int i = 0; i < 26; i++)
    {
        counter++;
        if (!((argv[1][i] >= 65 && argv[1][i] <= 90) || (argv[1][i] >= 97 && argv[1][i] <= 122)))
        {
            printf("Key must contain only aplphabetic characters.\n");
            return 1;
            break;
        }
        if (argv[1][i] == 0)
        {
            break;
        }

    }
    if (counter < 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int i = 0; i < 25; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("Key must not contain repeated characters.\n");
                return 1;

            }

        }
    }
    for (int z = 0; z < 26; z++)
    {
        if (argv[1][z] >= 65 && argv[1][z] <= 90)
        {
            argv[1][z] += 32;
        }
    }
    int encrypt[26];
    string text = get_string("plaintext:  ");
    string previous_text = text;
    int char_value = 97;
    for (int i = 0; i < 26; i++)
    {
        int difference = argv[1][i] - char_value;
        encrypt[i] = difference;
        char_value++;
    }
    for (int i = 0; i < strlen(text); i++)
    {
        if (!((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122)))
        {
            continue;
        }
        if (text[i] >= 65 && text[i] <= 90)
        {
            text[i] += 32;
            int encryptedNum = text[i] - 97;
            text[i] = text[i] + encrypt[encryptedNum];
            text[i] -= 32;
        }
        if (text[i] >= 97 && text[i] <= 122)
        {
            int encryptedNum = text[i] - 97;
            text[i] = text[i] + encrypt[encryptedNum];

        }


    }
    printf("ciphertext: %s\n", text);
    return 0;
}
