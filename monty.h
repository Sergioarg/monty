#ifndef MONTY_H
#define MONTY_H

/* ┌­­─────────┐ */
/* │ MACROS  │ */
/* ­­└─────────┘ */

#define true (1)
#define false (!true)
#define DELIMITER_LINE (" \n	")
#define UNUSED __attribute__((unused))
#define OPCODE_ARGS stack_t **stack, unsigned int line_number
#define UI_T unsigned int
#define ERROR_PUSH "L%u: usage: push integer\n"
#define ERROR_POP "L%u: can't pop an empty stack\n"
#define ERROR_SWAP "L%u: can't swap, stack too short\n"
#define ERROR_ADD "L%u: can't add, stack too short\n"
#define ERROR_SUB "L%u: can't sub, stack too short\n"
#define ERROR_DIV "L%u: can't div, stack too short\n"
#define ERROR_MUL "L%u: can't mul, stack too short\n"
#define ERROR_MOD "L%u: can't mod, stack too short\n"
#define ERROR_UKNOWN "L%u: unknown instruction %s\n"
#define ERROR_PINT "L%u: can't pint, stack empty\n"
#define ERROR_SHORT(TYPE) "L%u: can't "#TYPE", stack too short\n"
#define ERROR_FILE "USAGE: monty file\n"
#define ERROR_OPEN "Error: Can't open file %s\n"
#define ERROR_ZERO "L%u: division by zero\n"
#define ERROR_PCHARE "L%u: can't pchar, stack empty\n"
#define ERROR_PCHARR "L%u: can't pchar, value out of range\n"

/* ┌­­───────────────────┐ */
/* │ DEFINE DATATYPES  │ */
/* ­­└───────────────────┘ */
typedef unsigned char bool;

/* ┌­­───────────────┐ */
/* │ STANDAR LIBS  │ */
/* ­­└───────────────┘ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "general_methods.h"

/* ┌­­───────────────┐ */
/* │  STRUCTURES   │ */
/* ­­└───────────────┘ */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct data_to_handler_s - opcode and its function
 * @opcode: the opcode
 * @data: data to handler
 * @line_number: current number line
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct data_to_handler_s
{
	char *opcode;
	int data;
	unsigned int line_number;
} data_to_handler_t;

/**
 * struct global_data - global data
 * @file_stream: the opcode
 * @current_line: line to handler
 * @current_data: data to handler
 * @have_current_data: have to handler
 *
 * Description: global data
 */
typedef struct global_data
{
	FILE *file_stream;
	char *current_line;
	int current_data;
	bool have_current_data;
} global_data_t;

/* ┌­­───────────────┐ */
/* │  PROTORYPES   │ */
/* ­­└───────────────┘ */
void (*get_opcode_handler(
	char *opcode,
	unsigned int line_number
))(stack_t **, unsigned int);
bool is_number(char *string);
int len(stack_t *node, bool count_null);
void extract_token_line(char *current_line, char **current_opcode);
bool is_comment(char *string);

/* ┌­­───────────────────────────────┐ */
/* │  PROTORYPES OPCODES HANDLER   │ */
/* ­­└───────────────────────────────┘ */

void handler_push(OPCODE_ARGS);
void handler_nop(stack_t **stack UNUSED, unsigned int line_number UNUSED);
void handler_pall(OPCODE_ARGS UNUSED);
void handler_pint(OPCODE_ARGS UNUSED);
void handler_pop(OPCODE_ARGS UNUSED);
void handler_swap(OPCODE_ARGS);
void handler_add(OPCODE_ARGS);
void handler_sub(OPCODE_ARGS);
void handler_divs(OPCODE_ARGS);
void handler_mul(OPCODE_ARGS);
void handler_mod(OPCODE_ARGS);
void handler_pchar(stack_t **stack, unsigned int line_number);
void handler_pstr(stack_t **stack, unsigned int line_number UNUSED);
void handler_rotl(stack_t **stack, unsigned int line_number UNUSED);
void handler_rotr(stack_t **stack, unsigned int line_number UNUSED);

/* ┌­­───────────────────────────────┐ */
/* │  PROTOTYPES STACK METHODS     │ */
/* ­­└───────────────────────────────┘ */

stack_t *add_stack(stack_t **top);
void free_storage(stack_t *node);
stack_t *pop_stack(stack_t **top);
stack_t *swap_stack(stack_t **top);
foreach_prototype(stack_t);
stack_t *add_last_stack(stack_t **top);
stack_t *sub_last_stack(stack_t **top);
stack_t *mul_last_stack(stack_t **top);
stack_t *divs_last_stack(stack_t **top);
stack_t *mod_last_stack(stack_t **top);
int stack_empty(stack_t *node);
stack_t *rotl_stack(stack_t **top, stack_t *node);
stack_t *rotr_stack(stack_t **top, stack_t *node);

/* ┌­­───────────────────────────────┐ */
/* │  GLOBAL VARIABLES	    	   │ */
/* ­­└───────────────────────────────┘ */
/*map_prototype(stack_t, char);*/
extern global_data_t global_data;

#endif /*MONTY_H*/
