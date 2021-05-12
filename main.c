#include "monty.h"
/**
 * main - Entry point.
 *
 * @argc: Receive the file name to interpret.
 * @argv: Quantity of arguments receives.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	/* Vars */
	char *name_file = NULL;
	char *current_line = NULL;
	char *read_file = NULL;
	/* stack_t *storage = NULL; */
	FILE *file_stream = NULL;
	/* unsigned int line_numbers = 0; */

	/* Validation of quantity of arguments */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		return (EXIT_FAILURE);
	}

	name_file = argv[1];
	/* Validate be able to read the file */
	if (access(name_file, R_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s", name_file);
		return (EXIT_FAILURE);
	}
	/* Open the file */
	file_stream = fopen(read_file, "r");
	if (file_stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", name_file);
		return (EXIT_FAILURE);
	}

	/* Travel line number  */
	while (true)
	{
		if (getline(&current_line, NULL, file_stream) == EOF)
			break;
	}
	return (EXIT_SUCCESS);
}
