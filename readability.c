#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float letters;
float word;
float sentence;

int main(void)
{
    string full = get_string("Input a text to see the grade level of the text:\n");
    float length = count_letters(full);
    float words = count_words(full);
    float sentences = count_sentences(full);
    float L = length / words * 100;
    float S = sentences / words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int gradelevel = round(index);

    if(gradelevel >= 16)
    {
        printf("Grade 16+\n");
    }
    else if(gradelevel < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", gradelevel);
    }

}
int count_letters(string text)
{
    for(int i = 0; i < strlen(text); i++)
    {
        if(isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    for(int i = 0; i < strlen(text); i++)
    {
        if(text[i] == ' ')
        {
            word++;
        }
    }
    return word + 1;
}

int count_sentences(string text)
{
    for(int i = 0; i < strlen(text); i++)
    {
        if(text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentence++;
        }
    }
    return sentence;
}