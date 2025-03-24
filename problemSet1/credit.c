#include <cs50.h>
#include <stdio.h>

int get_length(long number);
int get_start_digits(long number, int length);
bool luhn_check(long number);

int main(void)
{
    long number = get_long("Number: ");

    if (luhn_check(number))
    {
        int length = get_length(number);
        int start = get_start_digits(number, length);

        // Check for card type
        if ((start == 34 || start == 37) && length == 15)
        {
            printf("AMEX\n");
        }
        else if (start >= 51 && start <= 55 && length == 16)
        {
            printf("MASTERCARD\n");
        }
        else if (start / 10 == 4 && (length == 13 || length == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

bool luhn_check(long number)
{
    int sum = 0;
    bool second = false;

    while (number > 0)
    {
        int digit = number % 10;

        if (second)
        {
            digit *= 2;
            if (digit > 9)
                digit -= 9;
        }

        sum += digit;
        number /= 10;
        second = !second;
    }

    return (sum % 10 == 0);
}

int get_length(long number)
{
    int length = 0;
    while (number > 0)
    {
        number /= 10;
        length++;
    }
    return length;
}

int get_start_digits(long number, int length)
{
    // Reduce number to first two digits
    while (length > 2)
    {
        number /= 10;
        length--;
    }
    return (int) number;
}
