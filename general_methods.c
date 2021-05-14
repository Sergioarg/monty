#include "monty.h"
/**
 * free_storage - frees the allocations mades.
 * @node: node declarate of the DLL.
**/
void free_storage(stack_t *node)
{
	if (node == NULL)
		return;
	/* free node node by one  */
	free_storage(node->next);
	/* free DLL */
	free(node);
}

/**
 * len - frees the allocations mades.
 * @node: node declarate of the DLL.
 * @count_null: boolean define if conunt the null value.
 * Return: intiger to length of linkend list
**/
int len(stack_t *node, bool count_null)
{
	if (node == NULL)
		return ((int)count_null);

	return (1 + len(node->next, count_null));
}
/**
 * stack_empty - validate if the stack is empty.
 *
 * @node: node declarate of the DLL.
 * @return true if the stack is empty.
 * Return: true if the file is empty.
 */
int stack_empty(stack_t *node)
{
	if (node != NULL)
		return (false);
	return (true);
}

/**
 * handler_nop - Doesn’t do anything.
 *
 * @stack: unused parameter.
 * @line_number: unused parameter.
 */
void handler_nop(stack_t **stack, unsigned int line_number)
{
	(void)*stack;
	(void)line_number;
}
