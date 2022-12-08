#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char h, int n);
int main (int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if(argc < 2 || argc > 2 )
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Make sure every character in argv[1] is a digit
    bool isdigits = only_digits(argv[1]);
    if(isdigits == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Convert argv[1] from a string to an int
    int key = atoi(argv[1]);
    // Prompt user for plaintext
    string text = get_string("plaintext: ");
    // For each character in the plaintext:
    printf("ciphertext: ");
    for(int c = 0; c <  strlen(text); c++)
    {
        // Rotate the character if it's a lettee
            char ct = rotate(text[c], key);
            printf("%c", ct);
    }
    printf("\n");
}
    bool only_digits(string s)
    {
        for(int i = 0; i < strlen(s); i++)
        {
            if(isdigit(s[i]) == false)
            {
                return false;
            }
        }
        return true;
    }
    char rotate(char h, int n)
    {
        if(isalpha(h))
        {
            if isupper(h)
            {
                char upperh = h - 65;
                char cipher = (upperh + n) % 26 + 65;
                return cipher;
            }
            else if(islower(h))
            {
                char lowerh = h - 97;
                char cipher = (lowerh + n) % 26 + 97;
                return cipher;
            }
        }
        else
        {
            char cipher = h;
            return cipher;
        }
        return false;
    }
