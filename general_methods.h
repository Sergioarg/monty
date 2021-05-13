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
void DATA_LIST##_foreach(void (*f)(DATA_LIST *, int), DATA_LIST * list, int i)

#define foreach_facade(DATA_LIST)                                             \
void DATA_LIST##_foreach(void (*f)(DATA_LIST *, int), DATA_LIST * list, int i)\
{                                                                             \
	if (list == NULL)                                                         \
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
