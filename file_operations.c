#include "monty.h"

/**
 * open_file - opens a file
 * @file: the file namepath
 * Return: returns nothing
 */

void open_file(char *file)
{
	FILE *fd = fopen(file, "r");

	if (file == NULL || fd == NULL)
		error_func1(2, file);

	read_file(fd);
	fclose(fd);
}

/**
 * read_file - reads a file
 * @fd: pointer to file descriptor
 * Return: returns nothing
 */

void read_file(FILE *fd)
{
	char *buffer = NULL;
	size_t size = 0;
	int line_num, format = 0;

	for (line_num = 1; getline(&buffer, &size, fd) != -1; line_num++)
	{
		format = parse_line(buffer, line_num, format);
	}
	free(buffer);
}

/**
 * parse_line - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line_num: line number
 * @format: storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue
 */

int parse_line(char *buffer, int line_num, int format)
{
	const char *delim = "\n ";
	char *opcode, *value;

	if (buffer == NULL)
		error_func1(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_func(opcode, value, line_num, format);
	return (format);
}

/**
 * find_func - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack
 * @line_num: line number
 * if 1 nodes will be entered as a queue
 * Return: nothing
 */

void find_func(char *opcode, char *value, int line_num, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", push_in_stack},
		{"pall", print_stack},
		{"pint", print_the_top},
		{"pop", pop_the_top},
		{"swap", swap_opcode},
		{"add", add_opcode},
		{"nop", nop_opcode},

		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_func(func_list[i].f, opcode, value, line_num, format);
			flag = 0;
		}
	}
	if (flag == 1)
		error_func1(3, line_num, opcode);
}

/**
 * call_func - calls the required function
 * @func: Pointer to the function that is about to be called
 * @op: string representing the opcode
 * @value: string representing a numeric value
 * @line_num: line numeber for the instruction
 * @format: Format specifier. If 0 Nodes will be entered as a stack
 * if 1 nodes will be entered as a queue
 */

void call_func(op_func func, char *op, char *value, int line_num, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			flag = -1;
		}
		if (value == NULL)
			error_func1(5, line_num);
		for (i = 0; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
				error_func1(5, line_num);
		}
		node = create_node(atoi(value) * flag);
		if (format == 0)
			func(&node, line_num);
		if (format == 1)
			push_in_queue(&node, line_num);
	}
	else
		func(&head, line_num);
}
