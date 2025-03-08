#include "cs50.h"
#include "stdio.h"


int main(int argc, char *argv[])
{
  int height =  get_int("Enter the hieght: ");

  for (int i = 0;i < height; i++) {
    printf("%*s%.*s\n", height - i, "", i+1, "########");
  };
  
}
