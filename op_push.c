#include "monty.h"

#include <stdlib.h>

/**
 * pall - ..
 * @stack: ..
 * @value: ..
 * Return: ..
*/
void push(stack_t **stack, int value)
{
    stack_t *node = malloc(sizeof(stack_t));
    if (!node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    node->n = value;
    node->prev = NULL;
    node->next = *stack;
    if (*stack)
        (*stack)->prev = node;
    *stack = node;
}
