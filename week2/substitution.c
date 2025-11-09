#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool valid_key(string key);
string encrypt(string text, string key);

int main(int argc, string argv[])
{
    // Check input is the correct number of CLI args
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    // Validate the key
    if (!valid_key(key))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }

    // Get plaintext
    string text = get_string("plaintext: ");

    // Encrypt using substitution key
    string cypherText = encrypt(text, key);

    // Output ciphertext
    printf("ciphertext: %s\n", cypherText);

    return 0;
}

string encrypt(string text, string key)
{
    // Visit character by character
    for (int i = 0; text[i] != '\0'; i++)
    {
        char ch = text[i];

        if (isupper(ch))
        {
            int index = ch - 'A';
            ch = toupper(key[index]);
        }
        else if (islower(ch))
        {
            int index = ch - 'a';
            ch = tolower(key[index]);
        }
        // else: non-letters unchanged

        text[i] = ch;
    }
    return text;
}

bool valid_key(string key)
{
    int len = strlen(key);
    if (len != 26)
    {
        return false;
    }

    bool seen[26] = {false};

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }

        int index = toupper(key[i]) - 'A';
        if (seen[index])
        {
            // Duplicate letter
            return false;
        }
        seen[index] = true;
    }
    return true;
}

