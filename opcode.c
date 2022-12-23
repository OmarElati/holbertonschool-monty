#include "monty.h"

/**
 * push - pushes a node to the top of stack
 * @stack: pointer to the head node pointer of the stack
 * @line_number: the line number
 *
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
    stack_t *new;

    /* Check if the stack exists */
    if (stack == NULL)
    {
        fprintf(stderr, "L%u: stack not found\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Allocate memory for the new node */
    new = malloc(sizeof(stack_t));
    if (new == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        free_stack(stack);
        exit(EXIT_FAILURE);
    }

    /* Set the values for the new node */
    new->next = *stack;
    new->prev = NULL;
    new->n = arg.arg;

    /* Update the pointers of the adjacent nodes */
    if (*stack)
        (*stack)->prev = new;
    *stack = new;
}

/**
 * pall - prints the data of all nodes in stack
 * @stack: pointer to the head node pointer of stack
 * @line_number: the line number
 *
 * Return: Nothing.
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *node;

    (void)line_number;

    /* Iterate through the stack and print the data of each node */
    for (node = *stack; node; node = node->next)
        printf("%d\n", node->n);
}
