#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp)
    {
        fprintf(stderr, "Error: failed to open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    stack_t *stack = NULL;

    instruction_t ops[] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL}
    };

    char line[256];
    int line_number = 0;
    while (fgets(line, sizeof(line), fp))
    {
        line_number++;

        char *command = strtok(line, " \n");
        if (!command)
            continue;

        int i;
        for (i = 0; ops[i].opcode; i++)
            if (strcmp(command, ops[i].opcode) == 0)
                break;

        if (ops[i].opcode)
            ops[i].f(&stack, line_number);
        else
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, command);
            return EXIT_FAILURE;
        }
    }

    fclose(fp);
    return 0;
}
