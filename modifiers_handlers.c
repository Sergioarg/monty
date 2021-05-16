#include "monty.h"

/**
 * handler_push - add to torage a value.
 *
 * @stack: storage the data.
 * @line_number: current number line of the file reader.
 */
void handler_push(stack_t **stack, unsigned int line_number)
{
	if (global_data.have_current_data == false)
	{
		fprintf(stderr, ERROR_PUSH, line_number);
		free_data(stack);
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
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, ERROR_POP, line_number);
		free_data(stack);
	}
	pop_stack(stack);
}

/**
 * handler_swap -  the top two elements of the stack.
 *
 * @stack: storage the data.
 * @UNUSED: current number line of the file reader.
 */
void handler_swap(stack_t **stack, unsigned int line_number UNUSED)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, ERROR_SWAP, line_number);
		free_data(stack);
	}
	swap_stack(stack);
}

/**
 * handler_rotl -  the top two elements of the stack.
 *
 * @stack: storage the data.
 * @UNUSED: current number line of the file reader.
 */
void handler_rotl(stack_t **stack, unsigned int line_number UNUSED)
{
	rotl_stack(stack, NULL);
}

/**
 * handler_rotr -  the top two elements of the stack.
 *
 * @stack: storage the data.
 * @UNUSED: current number line of the file reader.
 */
void handler_rotr(stack_t **stack, unsigned int line_number UNUSED)
{
	rotr_stack(stack, NULL);
}
