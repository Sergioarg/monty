#include "monty.h"

/**
 * extract_token_line - Extract data and opcode of each file line.
 *
 * @current_line: linea leaded.
 * @current_opcode: to save current opcode.
 * Return: Always 0.
 */
void extract_token_line(char *current_line, char **current_opcode)
{
	char *current_token = NULL;
	size_t i = 0;

	current_token = current_line;
	current_data = -1;
	for (i = 0; current_token != NULL; i++)
	{
		current_token = strtok(i == 0 ? current_token : NULL, DELIMITER_LINE);
		if (i == 0)
			*current_opcode = current_token;
		if (i == 1 && current_token != NULL && is_number(current_token))
			current_data = atoi(current_token);
	}
}
