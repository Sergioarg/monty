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
	new_top->n = current_data;

	if (*top != NULL)
		(*top)->prev = new_top;

	*top = new_top;

	return (new_top);
}

/* Eliminar el primer elemento de una lista doblemante enlazada */
