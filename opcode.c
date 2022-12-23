#include "monty.h"

/**
 * push - add a new element to the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the command being processed
 *
 * Return: Empty
 */
void push(stack_t **stack, unsigned int line_number)
{
	int x = 0;
	stack_t *new;

	/* Read the value to push from the command line */
	if (stack == NULL)
	{
		fprintf(stderr, "L%u: invalid push argument\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Allocate memory for the new element */
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* Initialize the new element and add it to the top of the stack */
	new->n = x;
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;

}

/**
 * pall - print all the values on the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the command being processed (unused)
 *
 * Return: Empty
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void) line_number;

	/* Print the values on the stack, from the top down */
	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
