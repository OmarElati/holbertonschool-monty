#include "monty.h"

/**
 * main - ..
 * @argc: ..
 * @argv: ..
 * Return: ..
*/
int main(int argc, char *argv[])
{
	FILE *file;

	/* Check for the correct number of arguments */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/* Open the input file */
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	parsefile(file);
	return (EXIT_FAILURE);
}

/**
 * free_stack - frees all nodes in a stack
 * @stack: pointer to the head node pointer of stack
 *
 * Return: Nothing.
 */
void free_stack(stack_t **stack)
{
    stack_t *node;

    /* Check for a valid stack */
    if (stack == NULL || *stack == NULL)
        return;

    /* Iterate through the stack and free each node */
    while (*stack != NULL)
    {
        node = (*stack)->next;
        free(*stack);
        *stack = node;
    }
}

/**
 * nop - does literally nothing
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */

void nop(stack_t **stack, unsigned int nline)
{
    (void)stack;
    (void)nline;
}

/**
 * _isalpha - checks if int is in alphabet
 * @c: int
 * Return: 1 if yes, 0 if no
 */
int _isalpha(int c)
{
    return isalpha(c);
}

/**
 * parseline - tokenizes a line of text, storing it in line struct
 * @line: struct containing line contents and line number
 * @buffer: string of text read from script file
 *
 * Return: Nothing
 */
void parseline(line_t *line, char *buffer)
{
    unsigned int i;
    char *token;

    line->content = malloc(sizeof(char *) * 3);
    if (!line->content)
    {
        fprintf(stderr, "Error: malloc failed");
        exit(EXIT_FAILURE);
    }

    for (i = 0; (token = strsep(&buffer, " \n")) && i < 2; i++)
    {
        line->content[i] = token;
    }

    line->content[i] = NULL;
}

/**
 * parsefile - reads and parses file one line at a time
 * @file: the script to be read
 *
 * Return: Nothing
 */
void parsefile(FILE *file)
{
    meta_t *meta;
    line_t line;
    char *buffer;
    size_t size = 0;

    meta = malloc(sizeof(meta_t));
    if (!meta)
    {
        fprintf(stderr, "Error: malloc failed");
        exit(EXIT_FAILURE);
    }

    line.number = 0;


    line.content = NULL;

    meta->file = file;
    meta->stack = NULL;
    meta->buf = NULL;

    buffer = malloc(sizeof(char) * BUFSIZ);
    if (!buffer)
    {
        fprintf(stderr, "Error: malloc failed");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, BUFSIZ, meta->file) != NULL)
    {
        line.number++;
        parseline(&line, buffer);
        if (line.content)
            get_op_func(line, meta)(&(meta->stack), line.number);
    }

    free(buffer);
    free_stack(&(meta->stack));
    fclose(meta->file);
    free(meta);
}
