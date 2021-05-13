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

#define foreach(FUNCTION, LIST, DATA_LIST)                            \
do {                                                                  \
	DATA_LIST *_head = (LIST);                                        \
	int _i = 0;                                                       \
	for (_head = (LIST); _head != NULL; _head = _head->next, _i++)    \
		FUNCTION(_head, _i);                                          \
} while (false)

#define free_data(LIST)              \
do {                                 \
	if (LIST != NULL)                \
		free_storage(LIST);          \
	free(global_data.current_line);  \
	fclose(global_data.file_stream); \
	exit(EXIT_SUCCESS);              \
} while (false)

#endif /*GENERAL_METHODS*/
