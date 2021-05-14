#include "monty.h"

/**
* add_stack - adds a new node at the beginning of a stack_t list.
*
* @top: top of the list.
* Return: new top.
*/
stack_t *add_stack(stack_t **top)
{
	stack_t *new_top;

	if (top == NULL)
		return (NULL);

	new_top = malloc(sizeof(stack_t));

	if (new_top == NULL)
		return (NULL);

	new_top->prev = NULL;
	new_top->next = *top;
	new_top->n = global_data.current_data;

	if (*top != NULL)
		(*top)->prev = new_top;

	*top = new_top;

	return (*top);
}

/**
* pop_stack - adds a new node at the beginning of a stack_t list.
*
* @top: top of the list.
* Return: new top.
*/
stack_t *pop_stack(stack_t **top)
{

	if (top == NULL || *top == NULL)
		return (NULL);

	*top = (*top)->next;

	if (*top != NULL)
	{
		free((*top)->prev);
		(*top)->prev = NULL;
	}

	return (*top);
}

/**
* swap_stack -  the top two elements of the stack.
*
* @top: top of the list.
* Return: new top.
*/
stack_t *swap_stack(stack_t **top)
{
	int to_swap = 0;

	if (top == NULL || *top == NULL)
		return (NULL);

	to_swap = (*top)->n;
	(*top)->n = (*top)->next->n;
	(*top)->next->n = to_swap;

	return (*top);
}
