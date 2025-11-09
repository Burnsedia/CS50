#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

string encrypt(string text, int key);


int main(void)
{
    string text = get_string("Give your text to encrypt: ");
    int key = get_int("Give me your key: ");

    string cypherText = encrypt(text , key);

    printf("Encrypted message: %s\n", cypherText);
}


string encypt(string text, int key){
  // Visit character by character
    for (int i = 0; text[i] != '\0'; i++)
    {
        char ch = text[i];

        // Lowercase characters
        if (islower(ch))
        {
            ch = (ch - 'a' + key) % 26 + 'a';
        }
        // Uppercase characters
        else if (isupper(ch))
        {
            ch = (ch - 'A' + key) % 26 + 'A';
        }
        // Numbers
        else if (isdigit(ch))
        {
            ch = (ch - '0' + key) % 10 + '0';
        }
        // For punctuation, spaces, etc. — just leave as is

        text[i] = ch;
    }
    return text;
}
