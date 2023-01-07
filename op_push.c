#include "monty.h"

/**
 * push - pushes a new element to the top of the stack
 * @stack: pointer to the head node pointer of the stack
 * @nline: the line number
 *
 * This function adds a new element to the top of the stack and updates the
 * head node pointer to point to the new element.
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int nline)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", nline);
		free(new);
		exit(EXIT_FAILURE);
	}

	new->n = arg.arg;
	new->prev = NULL;
	new->next = *stack;

	if (*stack)
		(*stack)->prev = new;

	*stack = new;
}
