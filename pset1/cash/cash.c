#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Create varibale to store money owned
    float dollar;

    // Repeat until user enters positive value
    do
    {
        dollar = get_float("Change Owed: ");
    }

    while(dollar < 0);

    // Convert value to cents and round it
    int cents = round(dollar * 100);

    int count = 0;
    while (cents > 0)
    {
        //printf("input, %i\n", cents);
        if(cents >= 25)
        {
            count += cents / 25;
            cents = cents % 25;
        }
        else if ( cents <= 24 && cents >= 10)
        {
            count += cents / 10;
            cents = cents % 10;
        }
        else if ( cents <= 9 && cents >= 5)
        {
            count += cents / 5;
            cents = cents % 5;
        }
        else
        {
            count += cents;
            cents -= cents;
        }
    }
    printf("%i",count);

}