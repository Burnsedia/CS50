
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int compute_score(string word);

int POINTS[] = { 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10 };

int main(void)
{
    // Prompt the user for two words
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    // Compute the score of each word
    int p1 = compute_score(player1);
    int p2 = compute_score(player2);

    // Print the winner
    if (p1 > p2)
    {
        printf("Player 1 wins\n");
    }
    else if (p2 > p1)
    {
        printf("Player 2 wins\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Compute the score of each word
int compute_score(string word)
{
    int points = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        // Add the score for each letter
        if (isalpha(word[i]))
        {
            int letter_offset = toupper(word[i]) - 'A';
            points += POINTS[letter_offset];
        }
    }

    return points;
}

