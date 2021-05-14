#ifndef GENERAL_METHODS
#define GENERAL_METHODS
/**
* hola - ?
* #define map_prototype(D, T)                                               \
* T *D##_T##_map(T (*f)(D *, int, T *)), D * top, D * list, T *array, int i)
*
* #define map_facade(D, T)                                                    \
* T *D##_T##_map(T (*f)(D *, int, T *), D * top, D * list, T *array, int i) \
* {                                                                           \
* if (array == NULL)                                                      \
* array = malloc(sizeof(T) * len(top, true));                         \
* if (i == len(top, false) || list == NULL)                               \
* return (array);                                                     \
* array[i] = (T)f(list, i, array);                                        \
* return (D##_T##_map(f, top, list->next, array, i + 1));                 \
* }
* @DATA_LIST: ?
* #define map(F, L, DL, TA) DL##DL##_map(F, L, L, NULL, 0)
*/
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

#define foreach(F, L, DL) DL##_foreach(F, L, 0)

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
		free_data(stack);                                       \
	}                                                                \
	if (                                                             \
		(*stack)->n == 0                                             \
		&& (strcmp(#METHOD, "divs") == 0                             \
			|| strcmp(#METHOD, "mod") == 0)                          \
		)                                                            \
	{                                                                \
		fprintf(stderr, ERROR_ZERO, line_number);                    \
		free_data(stack);                                       \
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

#endif /*GENERAL_METHODS*/
