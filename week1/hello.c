#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get user inpput
    string name = get_string("What's your name? ");
    // output to the terminal
    printf("Hello, %s!\n", name);
    // return zero for no errors
    return 0;
}
