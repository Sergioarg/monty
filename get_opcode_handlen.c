#include "monty.h"
/**
 * get_opcode_handler - Returns the specified option of option.
 *
 * @opcode: opcode calls
 * Return: handler_nop
 */
void (*get_opcode_handler(char *opcode))(stack_t **, unsigned int)
{
	int i = 0;

	instruction_t instructions[] = {
		{"push", handler_push},
		{NULL, NULL}
	};

	/* Select the function handler of opcode */
	for (i = 0; instructions[i].opcode != NULL; i++)
		if (strcmp(opcode, instructions[i].opcode) == 0)
			return (instructions[i].f);
	return (handler_nop);
}
