#include "monty.h"

/**
 * print - print any node.
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
