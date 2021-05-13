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
		fprintf(stderr, "L%i: usage: push integer", line_number);
		if (stack != NULL && *stack != NULL)
			free_storage(*stack);
		fclose(global_data.file_stream);
		exit(EXIT_FAILURE);
	}
	add_stack(stack);
}
