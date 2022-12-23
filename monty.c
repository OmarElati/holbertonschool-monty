#include "monty.h"

/**
 * main - ..
 * @argc: ..
 * @argv: ..
 * Return: ..
*/
int main(int argc, char *argv[])
{
    FILE *file;

    /* Check for the correct number of arguments */
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    /* Open the input file */
    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
}
