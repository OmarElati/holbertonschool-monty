#include "monty.h"

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/**
 * push - pushes an element to the stack
 * @stack: pointer to the stack
 * @line_number: line number of the instruction
 */
void push(stack_t **stack, unsigned int line_number)
{
    int value;
    char *token;

    token = strtok(NULL, " \n");
    if (!token || !isdigit(*token))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = atoi(token);

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
