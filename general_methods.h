#ifndef GENERAL_METHODS
#define GENERAL_METHODS

#define map(FUNCTION, LIST, DATA_TYPE, ARRAY)      \
do {                                               \
	stack_t *_head = (LIST);                       \
	int _len = len((LIST), true);                  \
		ARRAY = malloc(sizeof(DATA_TYPE) * _len);  \
	for (int _i = 0; _head != NULL; _i++)          \
	{                                              \
		ARRAY[_i] = FUNCTION(_head);               \
		_head = _head->next;                       \
	}                                              \
	ARRAY[_i] = (DATA_TYPE)0;                      \
} while (false)


#define foreach(FUNCTION, LIST, DATA_LIST)         \
do {                                               \
	DATA_LIST *_head = (LIST);                     \
	for (int _i = 0; _head != NULL; _i++)          \
	{                                              \
			FUNCTION(_head);                       \
		_head = _head->next;                       \
	}                                              \
} while (false)
#endif /*GENERAL_METHODS*/
