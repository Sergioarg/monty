#ifndef GENERAL_METHODS
#define GENERAL_METHODS

#define foreach_prototype(DATA_LIST)                                          \
void DATA_LIST##_foreach(bool (*f)(DATA_LIST *, int), DATA_LIST * list, int i)

#define foreach_facade(DATA_LIST)                                             \
void DATA_LIST##_foreach(bool (*f)(DATA_LIST *, int), DATA_LIST * list, int i)\
{                                                                             \
	if (list == NULL)                                                         \
		return;                                                               \
	if (!f(list, i))                                                          \
		return;                                                               \
	DATA_LIST##_foreach(f, list->next, i + 1);                                \
}

#define foreach(FUNCTION, LIST, DATA_L) DATA_L##_foreach(FUNCTION, LIST, 0)

#define free_data(LIST)               \
do {                                  \
	if (LIST != NULL && *LIST != NULL)\
		free_storage(*LIST);          \
	free(global_data.current_line);   \
	fclose(global_data.file_stream);  \
	exit(EXIT_FAILURE);               \
} while (false)

#define maths_handler(METHOD, ERROR)                                 \
void handler_##METHOD(stack_t **stack, unsigned int line_number)     \
{                                                                    \
	if (len(*stack, false) < 2)                                      \
	{                                                                \
		fprintf(stderr, ERROR, line_number);                         \
		free_data(stack);                                            \
	}                                                                \
	if (                                                             \
		(*stack)->n == 0                                             \
		&& (strcmp(#METHOD, "divs") == 0                             \
			|| strcmp(#METHOD, "mod") == 0)                          \
		)                                                            \
	{                                                                \
		fprintf(stderr, ERROR_ZERO, line_number);                    \
		free_data(stack);                                            \
	}                                                                \
	METHOD##_last_stack(stack);                                      \
}

#define maths_methods(OP, METHOD)           \
stack_t *METHOD##_last_stack(stack_t **top) \
{                                           \
	if (top == NULL || *top == NULL)        \
		return (NULL);                      \
	*top = (*top)->next;                    \
	if (*top != NULL)                       \
	{                                       \
		(*top)->n OP(*top)->prev->n;        \
		free((*top)->prev);                 \
		(*top)->prev = NULL;                \
	}                                       \
	return (*top);                          \
}

#define swap(VARIABLE_A, VARIABLE_B, TYPE) \
do {                                       \
	TYPE _TMP_SWAP = VARIABLE_A;           \
	VARIABLE_A = VARIABLE_B;               \
	VARIABLE_B = _TMP_SWAP;                \
} while (false)                            \

#endif /*GENERAL_METHODS*/
