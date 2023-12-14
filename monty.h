#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void open_file(char *file);
void read_file(FILE *);
int parse_line(char *buffer, int line_num, int format);
void find_func(char *opcode, char *value, int line_num, int format);
void call_func(op_func func, char *op, char *value, int line_num, int format);

/*operations and node functions*/
stack_t *create_node(int n);
void push_in_queue(stack_t **new_node, unsigned int line_num);
void push_in_stack(stack_t **new_node, unsigned int line_num);
void print_stack(stack_t **stack, unsigned int line_num);
void pop_the_top(stack_t **stack, unsigned int line_num);
void print_the_top(stack_t **stack, unsigned int line_num);
void swap_opcode(stack_t **stack, unsigned int line_number);
void add_opcode(stack_t **stack, unsigned int line_number);
void nop_opcode(stack_t **stack, unsigned int line_number);
void sub_opcode(stack_t **stack, unsigned int line_number);
void div_opcode(stack_t **stack, unsigned int line_number);
void free_node(void);

/*errors functions*/
void error_func1(int err, ...);
void error_func2(int err, ...);
void string_error(int err, ...);

#endif
