
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = get_int("Enter the height: ");

    // Validate input
    if (height < 1 || height > 8)
    {
        printf("Invalid input. Please enter a number between 1 and 8.\n");
        return 1;
    }

    // Loop through each row
    for (int i = 0; i < height; i++)
    {
        // Print spaces
        for (int j = 0; j < height - (i + 1); j++)
        {
            printf(" ");
        }

        // Print hashes
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        printf(" ");
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }

        printf("\n");  // Move to next line (only once per row)
    }
}

