#ifndef MONTY_H
#define MONTY_H

/* MACROS */
#define true (1)
#define false (!true)
#define DELIMITER_LINE (" \n	")
#define UNUSED __attribute__((unused))
/* DEFINE DATA TYPES */
typedef unsigned char bool;

/* STANDARS LIBS */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <errno.h>
#include <unistd.h>
#include <unistd.h>
#include "general_methods.h"

/* STRUCTURES */
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
 * struct global_data_s - global data
 * @file_stream: the opcode
 * @current_data: data to handler
 *
 * Description: global data
 */
typedef struct global_data
{
	FILE *file_stream;
	char *current_line;
	int current_data;
} global_data_t;

/* PROTORYPES */
void (*get_opcode_handler(char *opcode))(stack_t **, unsigned int);
bool is_number(char *string);
int len(stack_t *node, bool count_null);
void extract_token_line(char *current_line, char **current_opcode);

/* PROTORYPES OPCODES HANDLER */
void handler_push(stack_t **, unsigned int line_number);
void handler_nop(stack_t **stack UNUSED, unsigned int line_number UNUSED);
void handler_pall(stack_t **stack, unsigned int line_number UNUSED);
void handler_pint(stack_t **stack, unsigned int line_number UNUSED);

/* PROTOTYPES STACK METHODS */
stack_t *add_stack(stack_t **top);
void free_storage(stack_t *node);

/* GLOBAL VARIABLES */
extern global_data_t global_data;

#endif /*MONTY_H*/
