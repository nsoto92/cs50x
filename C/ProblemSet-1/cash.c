// #include <stdio.h>
// #include <cs50.h>
// #include <math.h>

float get_amount(void);

int main(void)
{
    // Calls get_amount to determine amount of change
    float amnt = get_amount();
    // Convert float to integer by rounding to nearest penny
    int cents = round(amnt * 100);
    //Create empty variable to count coins
    int owed = 0;
    // Begin Do.. While loop to determine coins to be given
    do
    {
        //Check if amount is higher than a quarter
        if (cents >= 25)
        {
            int qtr = 25;
            //Substract qtr from cents using "-=" for substracting (Personal Hurdle to figure out)
            cents -= qtr;
            owed++;
        }
        //Check if amount is higher than a dime but lower than a quarter
        if (cents >= 10 && cents < 25)
        {
            int dme = 10;
            cents -= dme;
            owed++;
        }
        //Check if amount is higher than a nickel but lower than a dime
        if (cents >= 5 && cents < 10)
        {
            int nckl = 5;
            cents -= nckl;
            owed++;
        }
        //Check if amount is higher than a penny but lower than a nickel
        if (cents >= 1 && cents < 5)
        {
            int pny = 1;
            cents -= pny;
            owed++;
        }
    }

    while (cents > 0);

    printf("%i coins in change\n", owed);
}

float get_amount(void)
{
    //Create float variable that takes user input
    float p;
    //Set do...while loop to ensure input meets criteria of positive value
    do
    {
        p = get_float("Enter how much change is owed:\n");
    } while (p < 0);
    return p;
}