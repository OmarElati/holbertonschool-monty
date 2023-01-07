#include "monty.h"

#include <stdio.h>
#include <stdlib.h>

void push(Stack *stack, int value)
{
	if (stack->top == MAX_STACK_SIZE - 1)
	{
		fprintf(stderr, "Error: stack overflow\n");
		exit(EXIT_FAILURE);
	}

	stack->data[++stack->top] = value;
}