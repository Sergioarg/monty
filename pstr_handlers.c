#include "monty.h"

/**
 * print_all - print any node.
 *
 * @node: node of storage.
 * @UNUSED: index of node.
 * Return: true if continue for each
 */
bool print_all(stack_t *node, int i UNUSED)
{
	if (node == NULL)
		return (false);
	if ((node->n == 0)
		|| (node->n < 32 || node->n > 255)
		|| (node->next == NULL)
	)
	{
		printf("\n");
		return (false);
	}

	printf("%c", node->n);
	return (true);
}

/**
 * handler_pstr - print all values of list storage.
 *
 * @stack: storage the data.
 * @UNUSED: current number line of the file reader.
 */
void handler_pstr(stack_t **stack, unsigned int line_number UNUSED)
{
	if (stack == NULL || stack_empty(*stack))
	{
		printf("\n");
		return;
	}
	foreach(print_all, *stack, stack_t);
}
