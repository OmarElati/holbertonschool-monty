#include "monty.h"

/**
 * get_op - function searches for a match between opcode and text
 * and returns the corresponding function
 * @opcode: the opcode string
 * @argument: the argument string
 *
 * Return: pointer to the matching function
 */
void (*get_op(char *opcode, char *argument))(stack_t **, unsigned int)
{
    unsigned int i = 0;
    instruction_t ops[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"nop", nop},
        {NULL, NULL}
    };

    /* Check if the opcode is a comment */
    if (opcode[0] == '#')
        return (nop);

    /* Search for a matching opcode */
    while (ops[i].opcode)
    {
        if (strcmp(ops[i].opcode, opcode) == 0)
        {
            /* Check for a queue push opcode */
            if (arg.flag == 1 && strcmp(ops[i].opcode, "push") == 0)
                return (qpush);

            return (ops[i].f);
        }

        i++;
    }

    fprintf(stderr, "Error: unknown instruction %s\n", opcode);
    exit(EXIT_FAILURE);
}
