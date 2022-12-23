#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * get_op - get the function corresponding to an opcode
 * @opcode: the opcode
 *
 * Return: a function pointer to the corresponding opcode function, or NULL
 * if the opcode is not recognized
 */
void (*get_op(char *opcode))(stack_t **, unsigned int)
{
    instruction_t ops[] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL}
    };
    int i;

    /* Search the instruction array for a matching opcode */
    for (i = 0; ops[i].opcode != NULL; i++)
        if (strcmp(ops[i].opcode, opcode) == 0)
            return (ops[i].f);

    /* Return NULL if no matching opcode was found */
    return (NULL);
}
