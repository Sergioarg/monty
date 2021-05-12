#include "monty.h"
/**
 * handler_push - add to torage a value.
 *
 * @stack: storage the data.
 * @UNUSED: current number line of the file reader.
 */
void handler_push(stack_t **stack, unsigned int line_number UNUSED)
{
	add_stack(stack);
}



