#include "monty.h"

/**
 * pall - prints the data of all nodes in stack
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 *
 * Return: Nothing.
 */
void pall(stack_t **stack, unsigned int nline)
{
	stack_t *temp = *stack;

	nline += 0;
	if (temp == NULL)
	{
		printf("0\n");
	}
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
