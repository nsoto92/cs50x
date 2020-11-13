// #include <cs50.h>
// #include <stdio.h>
// #include <ctype.h>
// #include <stdlib.h>
// #include <string.h>

//main will take an additional argument now
int main(int argc, string k[])
{
    // If your program is executed without
    // any command-line arguments or with more
    // than one command-line argument, print an error
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // If any of the characters of the command-line argument
    // is not a decimal digit, print an error
    for (int i = 0; i < strlen(k[1]); i++)
    {
        if (!isdigit(k[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Request text to be encrypted k[i] times
    string plain = get_string("plaintext:");
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plain); i++)
    {
        int key = atoi(k[1]);
        // Checks if plain[i] is uppercase and verifies conditions
        if (isupper(plain[i]))
        {
            if (plain[i] + key > 90)
            {
                char ci = (plain[i] + (key % 26));
                if (ci > 90)
                {
                    printf("%c", ci - 26);
                }
                else if ((plain[i] + key - 26) > 90)
                {
                    printf("%c", (plain[i] + key) - 52);
                }
                else
                {
                    printf("%c", (plain[i] + key) - 26);
                }
            }
            else
            {
                printf("%c", plain[i] + key);
            }
        }
        // Checks if plain[i] is lowercase and verifies conditions
        else if (islower(plain[i]))
        {
            if (plain[i] + key > 122)
            {
                char ci = (plain[i] + (key % 26));
                if (ci > 122)
                {
                    printf("%c", ci - 26);
                }
                else if ((plain[i] + key - 26) > 122)
                {
                    printf("%c", (plain[i] + key) - 52);
                }
                else
                {
                    printf("%c", (plain[i] + key) - 26);
                }
            }
            else
            {
                printf("%c", plain[i] + key);
            }
        }
        // If not lower or uppercase, print plain[i] as is
        else
        {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
    return 0;
}