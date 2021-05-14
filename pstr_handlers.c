#include "monty.h"

/**
 * print_all - print any node.
 *
 * @node: node of storage.
 * @UNUSED: index of node.
 */
void print_all(stack_t *node, int i UNUSED)
{
	stack_t *node_copy = NULL;

	if (node == NULL)
		return;
	node_copy = node->prev;
	while (node_copy != NULL)
	{
		if (node_copy->n == 0)
			return;
		if (node_copy->n > 255 || node_copy->n < 32)
			return;
		node_copy = node_copy->prev;
	}
	if (node->n == 0)
		printf("\n");
	else if (node->n > 255 || node->n < 32)
		printf("\n");
	else if (node->next == NULL)
		printf("\n");
	else if (node->n <= 255 && node->n >= 32)
		printf("%c", node->n);
}

/**
 * handler_pstr - print all values of list storage.
 *
 * @stack: storage the data.
 * @UNUSED: current number line of the file reader.
 */
void handler_pstr(stack_t **stack, unsigned int line_number UNUSED)
{
	if (stack == NULL || stack_empy(*stack))
	{
		printf("\n");
		return;
	}
	foreach(print_all, *stack, stack_t);
}

