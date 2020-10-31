// #include <stdio.h>
// #include <cs50.h>

int get_height(void);

int main(void)
{
    //Calls get_height function to determine pyramid height
    int i = get_height();
    //For Loop that runs <= i times
    for (int j = 1; j <= i; j++)
    {
        //Nested For loop that runs i-j times and prints blank spaces for right-aligned pyramids
        for (int d = 1; d <= i - j; d++)
        {
            printf(" ");
        }
        //Nested For loop that will run as j increases and prints pyramid blocks
        for (int n = 1; n <= j; n++)
        {
            printf("#");
        }
        printf("\n");
    }
}

int get_height(void)
{
    //Create int variable that takes user input
    int h;
    //Set do...while loop to ensure input meets criteria of number between 1 & 8
    do
    {
        h = get_int("Enter height:");
    } while (h < 1 || h > 8);
    return h;
}