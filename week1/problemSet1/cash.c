#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickles(int cents);
int calculate_penies(int cents);

int main(void)
{
    // Prompt the user for change owed, in cents
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    // Calculate how many quarters you should give customer
    int quarters = calculate_quarters(cents);

    //printf("%d\n", quarters);
    // Subtract the value of those quarters from cents
    cents = cents - (quarters * 25);

    // Calculate how many dimes you should give customer
    int dimes = calculate_dimes(cents);

    //printf("%d\n", dimes);
    // Subtract the value of those dimes from cents
    cents -= (dimes * 10);

    // Calculate how many nickles you should give customer
    int nickles = calculate_nickles(cents);

    //printf("%d\n", nickles);
    // Subtract the value of those nickles from cents
    cents -= (nickles * 5);

    // Calculate how many penies you should give customer
    int penies = calculate_penies(cents);

    //printf("%d\n", penies);
    // Subtract the value of those penies from cents
    cents -= (penies);


    int coins = quarters + dimes + nickles + penies;
    
    // output the coins
    printf("%d\n", coins);


}

int calculate_quarters(int cents)
{
    // Calculate how many quarters you should give customer
    int quarters = 0;
    while (cents >= 25)
    {
        quarters++;
        cents = cents - 25;
    }
    return quarters;
}

int calculate_dimes(int cents)
{
    // Calculate how many quarters you should give customer
    int dimes = 0;
    while (cents >= 10)
    {
        dimes++;
        cents = cents - 10;
    }
    return dimes;

}

int calculate_nickles(int cents)
{
    // Calculate how many quarters you should give customer
    int nickles = 0;
    while (cents >= 5)
    {
        nickles++;
        cents = cents - 10;
    }
    return nickles;
}

int calculate_penies(int cents)
{
  int penies = 0;
  while (cents >= 1)
  {
    penies++;
    cents--;
  }
  return penies;

}
