#include "monty.h"

/**
 * print_one - print any node.
 *
 * @node: node of storage.
 * @i: index of node.
 */
void print_one(stack_t *node, int i)
{
	if (node  != NULL && i == 0)
		printf("%c\n", node->n);
}

/**
 * handler_pchar - print all values of list storage.
 *
 * @stack: storage the data.
 * @line_number: current number line of the file reader.
 */
void handler_pchar(stack_t **stack, unsigned int line_number)
{
	if (stack_empy(*stack))
	{
		dprintf(STDERR_FILENO, ERROR_PCHARE, line_number);
		if (stack != NULL)
			free_data(*stack);
	}
	if ((*stack)->n > 255 || (*stack)->n < 32)
	{
		dprintf(STDERR_FILENO, ERROR_PCHARR, line_number);
		if (stack != NULL)
			free_data(*stack);
	}
	if (*stack != NULL || *stack != NULL)
		foreach(print_one, *stack, stack_t);
}

/**
 * print-first - print any node.
 *
 * @node: node of storage.
 * @UNUSED: index of node.
 */
void print(stack_t *node, int i UNUSED)
{
	if (node  != NULL)
		printf("%i\n", node->n);
}

/**
 * handler_pall - print all values of list storage.
 *
 * @stack: storage the data.
 * @UNUSED: current number line of the file reader.
 */
void handler_pall(stack_t **stack, unsigned int line_number UNUSED)
{
	if (*stack != NULL || *stack != NULL)
		foreach(print, *stack, stack_t);
}

/**
 * handler_pint - prints the value at the top of the stack.
 *
 * @stack: storage the data.
 * @UNUSED: current number line of the file reader.
 */
void handler_pint(stack_t **stack, unsigned int line_number UNUSED)
{
	if (stack_empy(*stack))
		dprintf(STDERR_FILENO, ERROR_PINT, line_number);

	printf("%i\n", (*stack)->n);
}
