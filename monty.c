#include "monty.h"

/**
 * main - ..
 * @argc: ..
 * @argv: ..
 * Return: ..
*/
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
    }

    stack_t *stack = NULL;

    char line[256];
    int line_number = 0;
    while (fgets(line, sizeof(line), fp))
    {
        line_number++;

        char *command = strtok(line, " \n");
        if (!command)
            continue;

        if (strcmp(command, "push") == 0)
        {
            char *arg = strtok(NULL, " \n");
            if (!arg)
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                return EXIT_FAILURE;
            }

            int value = atoi(arg);
            push(&stack, value);
        }
        else if (strcmp(command, "pall") == 0)
            pall(stack);
        else
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, command);
            return EXIT_FAILURE;
        }
    }

    fclose(fp);
    return 0;
}
