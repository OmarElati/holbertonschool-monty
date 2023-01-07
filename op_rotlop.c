#include "monty.h"

/**
 * rotlop - rotates stack to left
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void rotlop(stack_t **stack, unsigned int nline)
{
	stack_t *last, *tmp;

	(void)nline;
	if (!stack || !(*stack) || !((*stack)->next))
		return;

	tmp = *stack;
	last = tmp;

	while (last->next)
	{
		last = last->next;
	}

	last->next = tmp;
	tmp->prev = last;
	tmp->next->prev = NULL;
	*stack = tmp->next;
	tmp->next = NULL;
}
