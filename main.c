#include "monty.h"

global_data_t global_data = {NULL, NULL, -1, false};

foreach_facade(stack_t)

/**
 * main - Entry point.
 *
 * @argc: Receive the file name to interpret.
 * @argv: Quantity of arguments receives.
 * Return: Always 0.
 */
int main(int argc, char const *argv[])
{
	/* Vars */
	const char *name_file = NULL;
	char *current_opcode = NULL;
	stack_t *storage = NULL;
	size_t size_current_line = 0, line_numbers = 0;

	/* Validation of quantity of arguments */
	if (argc != 2)
	{
		fprintf(stderr, ERROR_FILE);
		exit(EXIT_FAILURE);
	}

	name_file = argv[1];
	/* Open the file */
	global_data.file_stream = fopen(name_file, "r");
	if (global_data.file_stream == NULL)
	{
		fprintf(stderr, ERROR_OPEN, name_file);
		exit(EXIT_FAILURE);
	}
	/* Travel line number  */
	for (line_numbers = 1; true; line_numbers++)
	{
		if (getline(&global_data.current_line, &size_current_line,
				global_data.file_stream) == EOF)
			break;
		extract_token_line(global_data.current_line, &current_opcode);
		if (current_opcode != NULL)
			get_opcode_handler(current_opcode, line_numbers)
				(&storage, line_numbers);
	}
	if (storage != NULL)
		free_storage(storage);
	free(global_data.current_line);
	fclose(global_data.file_stream);
	return (EXIT_SUCCESS);
}
