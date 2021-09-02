#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Ask user to enter positive tower height
    int height;
    do
    {
        height = get_int("Enter tower height: ");
    }
    while (height < 1 || height >= 9);

    // Build tower
    for (int i = 0; i < height ; i++)
    {
        // print blank spaces
        for (int j = height - i; j > 1 ; j--)
        {
            printf(" ");
        }

        // print #
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }

        // give two space
        for (int z = 0; z <= 1; z++)
        {
            printf(" ");
        }

        // print #
        for (int s = 0; s <= i; s++)
        {
            printf("#");
        }

        // move to next line
        printf("\n");
    }
}
