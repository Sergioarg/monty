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
	stack_t *will_free;

	if (top == NULL || *top == NULL)
		return (NULL);

	will_free = *top;
	*top = (*top)->next;

	free(will_free);
	if (*top != NULL)
		(*top)->prev = NULL;

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
	if (top == NULL || *top == NULL)
		return (NULL);

	swap((*top)->n, (*top)->next->n, int);

	return (*top);
}
