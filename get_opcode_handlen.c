#include "monty.h"
/**
 * get_opcode_handler - Returns the specified option of option.
 *
 * @opcode: opcode calls
 * @line_number: opcode calls
 * Return: handler_nop
 */
void (*get_opcode_handler(char *opcode, UI_T line_number))(OPCODE_ARGS)
{
	int i = 0;

	instruction_t instructions[] = {
		{"nop", handler_nop},
		{"push", handler_push},
		{"pall", handler_pall},
		{"pint", handler_pint},
		{"pop", handler_pop},
		{"swap", handler_swap},
		{"add", handler_add},
		{"sub", handler_sub},
		{"mul", handler_mul},
		{"div", handler_divs},
		{"mod", handler_mod},
		{"pchar", handler_pchar},
		{"pstr", handler_pstr},
		{"rotl", handler_rotl},
		{"rotr", handler_rotr},
		{NULL, NULL}
	};

	/* Select the function handler of opcode */
	for (i = 0; instructions[i].opcode != NULL; i++)
		if (strcmp(opcode, instructions[i].opcode) == 0)
			return (instructions[i].f);

	fprintf(stderr, ERROR_UKNOWN, line_number, opcode);
	exit(EXIT_FAILURE);
}
