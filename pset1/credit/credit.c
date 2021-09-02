#include <cs50.h>
#include <stdio.h>
#include <math.h>

// call my functions
int check_len(long n);
int get_first_two_digits(long n);
int check_card_company(long n);

int main(void)
{
    // initial variables to be used
    long card_number;
    int card_len;
    int card_num_sum = 0;

    // Ask user to add card number
    card_number = get_long("Number: ");

    // Get length of the card number
    card_len = check_len(card_number);

    // check if card has valid numbers length
    if (card_len != 15 && card_len != 16 && card_len != 13)
    {
        printf("INVALID\n");
        return 0;
    }
    else if (check_card_company(card_number) == 0)
    {
        // check card belongs to which company
        printf("INVALID\n");
    }
    else
    {
        // Check if card is valid using Luhn’s Algorithm
        while (card_number != 0)
        {
            int x1 = card_number % 10;
            card_num_sum += x1;
            int x2 = 2 * ((card_number / 10) % 10);
            int y1 = (x2 % 10) + floor((x2 / 10) % 10);
            card_num_sum += y1;
            card_number /= 100;
        }

        // if last digit of the sum is not zero mark card invalid
        if (card_num_sum % 10 != 0)
        {
            printf("INVALID\n");
            return 0;
        }
    }

}

// return how long the card number is
int check_len(long n)
{
    int length = 0;
    long num = n;
    while (num > 0)
    {
        num = num / 10;
        length += 1;
    }
    return length;
}

// return first two digits of the card number
int get_first_two_digits(long n)
{
    long num = n;
    do
    {
        num = num / 10;
    }
    while (num > 100);
    return num;
}


// Prints company to which card belongs
int check_card_company(long n)
{
    int first_2_digit = get_first_two_digits(n);

    if (first_2_digit == 34 || first_2_digit == 37)
    {
        printf("AMEX\n");
        return 1;
    }
    else if ((first_2_digit / 10 == 5) && (0 < first_2_digit % 10 && first_2_digit % 10 < 6))
    {
        printf("MASTERCARD\n");
        return 1;
    }
    else if ((first_2_digit / 10 == 4))
    {
        printf("VISA\n");
        return 1;
    }
    else
    {
        return 0;

    }
}
