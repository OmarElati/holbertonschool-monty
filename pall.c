#include "monty.h"

#include <stdio.h>

/**
 * pall - prints all the values on the stack
 * @stack: pointer to the stack
 * @line_number: line number of the instruction
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *node = *stack;

    (void)line_number;

    while (node)
    {
        printf("%d\n", node->n);
        node = node->next;
    }
}
