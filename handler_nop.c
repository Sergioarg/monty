#include "monty.h"

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
