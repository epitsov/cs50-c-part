#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <string>
int count_letters(string text);
int count_word(string text);
int count_sentence(string text);
int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_word(text);
    int sentences = count_sentence(text);
    float num = 0.0;
    if (words < 100)
    {
        num = 100.0 / (float)words;

    }
    float avg_word = (float)letters * num;
    float avg_sentence = (float)sentences * num;
    float index = round(avg_word * 0.0588 - avg_sentence * 0.296 - 15.8);
    if (index <= 1)
    {
        index = 1.0;
        printf("Before Grade %.0f\n", index);

    }
    else if (index > 16)
    {
        index = 16.0;
        printf("Grade %.0f+\n", index);
    }
    else
    {
        printf("Grade %.0f\n", index);
    }

}
int count_letters(string text)
{
    int counter = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            counter++;
        }
    }
    return counter;
}
int count_word(string text)
{
    int counter = 0;
    int i = 0;
    while (i < strlen(text))
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            while ((text[i] == 45 || text[i] == 39) || ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122)))
            {
                i++;
            }
            counter++;
        }
        i++;
    }
    return counter;
}
int count_sentence(string text)
{
    int counter = 0;
    int i = 0;
    while (i < strlen(text))
    {
        if (((text[i] == 33) || (text[i] == 63) || (text[i] == 46)) && ((text[i + 1] == 32) || text[i + 1] == 34))
        {
            counter++;
        }
        if (((text[i] == 33) || (text[i] == 63) || (text[i] == 46)) && (i == strlen(text) - 1))
        {
            counter++;
        }
        i++;

    }

    return counter;

}