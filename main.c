#include "monty.h"

int current_data = -1;
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
	char *current_line = NULL;
	/* char *read_file = NULL; */
	stack_t *storage = NULL;
	FILE *file_stream = NULL;
	size_t size_current_line = 0;
	unsigned int line_numbers = 0, i = 0;
	char *current_token = NULL;
	char *current_opcode = NULL;

	/* Validation of quantity of arguments */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	name_file = argv[1];
	/* Validate be able to read the file */
	if (access(name_file, R_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", name_file);
		return (EXIT_FAILURE);
	}
	/* Open the file */
	file_stream = fopen(name_file, "r");
	if (file_stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", name_file);
		return (EXIT_FAILURE);
	}

	/* Travel line number  */
	for (line_numbers = 0; true; line_numbers++)
	{
		if (getline(&current_line, &size_current_line, file_stream) == EOF)
			break;

		/* Extract data and opcode of each file line */
		current_token = current_line;
		current_data = -1;
		for (i = 0; current_token != NULL; i++)
		{
			current_token = strtok(i == 0 ? current_token : NULL, DELIMITER_LINE);
			if (i == 0)
				current_opcode = current_token;
			if (i == 1 && current_token != NULL && is_digit(current_token))
				current_data = atoi(current_token);
		}
		if (current_opcode != NULL)
			get_opcode_handler(current_opcode)(&storage, line_numbers);
	}
	return (EXIT_SUCCESS);
}
