#include "monty.h"

#include <stdio.h>

void pall(const Stack *stack)
{
    for (int i = stack->top; i >= 0; --i)
        printf("%d\n", stack->data[i]);
}
