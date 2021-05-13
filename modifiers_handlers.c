#include "monty.h"

/**
 * handler_push - add to torage a value.
 *
 * @stack: storage the data.
 * @line_number: current number line of the file reader.
 */
void handler_push(stack_t **stack, unsigned int line_number)
{
	if (global_data.current_data == -1)
	{
		dprintf(STDERR_FILENO, ERROR_PUSH, line_number);
		if (stack != NULL)
			free_data(*stack);
	}
	add_stack(stack);
}


/**
 * handler_pop - removes the top element of the stack.
 *
 * @stack: storage the data.
 * @UNUSED: current number line of the file reader.
 */
void handler_pop(stack_t **stack, unsigned int line_number UNUSED)
{
	pop_stack(stack);
}
