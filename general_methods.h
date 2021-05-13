#ifndef GENERAL_METHODS
#define GENERAL_METHODS

#define map(FUNCTION, LIST, DATA_TYPE, ARRAY)                \
do {                                                         \
	stack_t *_head = (LIST);                                 \
	int _len = len((LIST), true);                            \
		ARRAY = malloc(sizeof(DATA_TYPE) * _len);            \
	int _i = 0;                                              \
	for (_i = 0; _head != NULL; _i++, _head = _head->next)   \
		ARRAY[_i] = FUNCTION(_head, _i);                     \
	ARRAY[_i] = (DATA_TYPE)0;                                \
} while (false)

#define foreach_prototype(DATA_LIST)                                         \
void DATA_LIST##_foreach(void (*f)(DATA_LIST *, int), DATA_LIST *list, int i)

#define foreach_facade(DATA_LIST)                                             \
void DATA_LIST##_foreach(void (*f)(DATA_LIST *, int), DATA_LIST *list, int i) \
{                                                                             \
	if (list != NULL)                                                         \
		return;                                                               \
	f(list, i);                                                               \
	DATA_LIST##_foreach(f, list->next, i + 1);                                \
}

#define foreach(F, L, DL) DL##_foreach(F, L, 0)

#define free_data(LIST)              \
do {                                 \
	if (LIST != NULL)                \
		free_storage(LIST);          \
	free(global_data.current_line);  \
	fclose(global_data.file_stream); \
	exit(EXIT_SUCCESS);              \
} while (false)

#endif /*GENERAL_METHODS*/
