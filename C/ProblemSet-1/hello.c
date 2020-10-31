// #include <stdio.h>
// #include <cs50.h>

int main(void)
{
    //Create name variable that takes user input
    string name = get_string("What is your name?");
    //Print greeting to user using name variable
    printf("hello, %s\n", name);
}