#include <cs50.h>
#include <stdio.h>

int left_tower(int height, int index);


int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Loop to print the pyramid
    for (int i = 1; i <= height; i++)
    {
      left_tower(height,i);

      // Print gap
      printf("  ");

      // Print right hashes
      for (int j = 0; j < i; j++)
      {
      printf("#");
      }

      // Move to next line
      printf("\n");
    }
}

int left_tower(int height, int index)
{
   // Print spaces for left alignment
  for (int j = 0; j < height - index; j++)
  {
    printf(" ");
  }

  // Print left hashes
  for (int j = 0; j < index; j++)
  {
  printf("#");
  }

}
