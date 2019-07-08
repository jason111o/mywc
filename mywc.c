// Created by Jason Pippin during the course of learning the C language
// It is a simple version to the Unix command wc, although it counts
// many more words (chars with no spaces in between), its line count
// and char count are spot on.

#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    // Check for one argument
    if (argc != 2)
    {
        printf("\nUsage: mywc [file]\n");
        printf("mywc is similar to the unix command wc.\n");
        printf("It will print out the byte, word, and line count of a file.\n\n");

        return 1;
    }

    // vars for counting
    int c, cc, wc, lc;
    c = cc = wc = lc = 0;

    // Open the argument passed in if it is a file
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        printf("\nUnable to open \"%s\"\n\n", argv[1]);
        return 1;
    }
    
    // Iterate through file chars
    while ((c = fgetc(file)) != EOF)
    {
        if (c != ' ' || c != '\n' || c != '\t')
        {
            ++cc; // Count chars
        }
        if (c == ' ' || c == '\n' || c == '\t')
        {
            ++wc; // Count words
        }
        if (c == '\n')
        {
            ++lc; // Count lines
        }
    }

    // Print to stdout
    printf(" %i %i %i\n", lc, wc, cc);

    // Close arg1
    fclose(file);

    return 0;
}
