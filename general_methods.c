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
