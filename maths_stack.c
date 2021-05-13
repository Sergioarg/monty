#include "monty.h"

stack_t *_pop_stack(stack_t **top)
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












