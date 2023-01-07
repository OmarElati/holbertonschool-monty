#include "monty.h"

#include <stdio.h>

/**
 * pall - ..
 * @stack: ..
 * Return: ..
*/
void pall(const stack_t *stack)
{
    while (stack)
    {
        printf("%d\n", stack->n);
        stack = stack->next;
    }
}

