#ifndef MONTY_H
#define MONTY_H

#define MAX_STACK_SIZE 1024

typedef struct stack
{
	int data[MAX_STACK_SIZE];
	int top;
} Stack;

void push(Stack *stack, int value);
void pall(const Stack *stack);

#endif
