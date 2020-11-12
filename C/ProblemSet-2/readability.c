// #include <stdio.h>
// #include <cs50.h>
// #include <ctype.h>
// #include <string.h>
// #include <math.h>

int letterCount(string);
int wordCount(string);
int sentenceCount(string);

int main(void)
{
    string text = get_string("Text: ");
    int lCount = letterCount(text);
    int wCount = wordCount(text);
    int sCount = sentenceCount(text);
    //Variables for Coleman-Liau Index
    float L = (100.0 * lCount) / wCount;
    float S = (100.0 * sCount) / wCount;
    //Coleman-Liau Index formula
    float index = 0.0588 * L - 0.296 * S - 15.8;
    //Result of Coleman-Liau rounded
    int result = round(index);
    // printf("%i letters\n%i words\n%i sentences\n", lCount, wCount, sCount);
    //Print Results:
    if (result < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (result >= 1 && result <= 16)
    {
        printf("Grade %i\n", result);
    }
    else
    {
        printf("Grade 16+\n");
    }
}
//Count letters
int letterCount(string a)
{
    int letterCount = 0;
    for (int i = 0; i < strlen(a); i++)
    {
        // check if [i] is alphanumeric to add 1 to letter count
        if (isalpha(a[i]))
        {
            letterCount++;
        }
    }
    return letterCount;
}
//Count words
int wordCount(string a)
{
    int wordCount = 0;
    for (int i = 0; i <= strlen(a); i++)
    {
        // check if [i] is space or '-' to add 1 to word count
        if (isspace(a[i]) || a[i] == '\0')
        {
            wordCount++;
        }
    }
    return wordCount;
}
// Count sentences
int sentenceCount(string a)
{
    int sentenceCount = 0;
    for (int i = 0; i < strlen(a); i++)
    {
        // check if [i] is ., !, or ? to add 1 to sentence count
        if ('.' == a[i])
        {
            sentenceCount++;
        }
        else if ('!' == a[i])
        {
            sentenceCount++;
        }
        else if ('?' == a[i])
        {
            sentenceCount++;
        }
    }
    return sentenceCount;
}