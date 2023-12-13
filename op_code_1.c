#include "monty.h"


/**
 * pop_the_top - adds a node to the stack
 * @stack: pointer to a pointer pointing to top node of the stack
 * @line_num: interger representing the line number of of the opcode
 */

void pop_the_top(stack_t **stack, unsigned int line_num)
{
	stack_t *current;

	if (stack == NULL || *stack == NULL)
		error_func2(7, line_num);

	current = *stack;
	*stack = current->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(current);
}

/**
 * print_the_top - Prints the top node of the stack
 * @stack: pointer to a pointer pointing to top node of the stack
 * @line_num: interger representing the line number of of the opcode
 */

void print_the_top(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
		error_func2(6, line_num);
	printf("%d\n", (*stack)->n);
}

/**
 * swap_opcode - swaps the top two elements of the stack
 * @stack: Pointer to a pointer pointing to top node of the stack
 * @line_number: Interger representing the line number of of the opcode
 */

void swap_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_func2(8, line_number, "swap");

	current = (*stack)->next;
	(*stack)->next = current->next;

	if (current->next != NULL)
		current->next->prev = *stack;

	current->next = *stack;
	(*stack)->prev = current;
	current->prev = NULL;
	*stack = current;
}

/**
 * add_opcode - adds the top two elements of the stack
 * @stack: Pointer to a pointer pointing to top node of the stack
 * @line_number: Interger representing the line number of of the opcode
 */

void add_opcode(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_func2(8, line_number, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * nop_opcode - does nothing
 * @stack: Pointer to a pointer pointing to top node of the stack
 * @line_number: Interger representing the line number of of the opcode
 */

void nop_opcode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
