#include "monty.h"

/**
 * print - print any node.
 *
 * @node: node of storage.
 */
void print(stack_t *node)
{
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
	foreach(print, *stack, stack_t);
}
