#include "monty.h"
/**
 * get_opcode_handler - Returns the specified option of option.
 *
 * @opcode: opcode calls
 * Return: handler_nop
 */
void (*get_opcode_handler(
	char *opcode,
	unsigned int line_number
))(stack_t **, unsigned int)
{
	int i = 0;

	instruction_t instructions[] = {
		{"nop", handler_nop},
		{"push", handler_push},
		{"pall", handler_pall},
		{"pint", handler_pint},
		{"pop", handler_pop},
		{NULL, NULL}
	};

	/* Select the function handler of opcode */
	for (i = 0; instructions[i].opcode != NULL; i++)
		if (strcmp(opcode, instructions[i].opcode) == 0)
			return (instructions[i].f);
	fprintf(stderr, ERROR_UKNOWN, line_number, opcode);
	exit(EXIT_FAILURE);
	return (handler_nop);
}
