#include "monty.h"

/**
 * add_to_queue - adds a node to the queue
 * @new_node: pointer to the new node
 * @line_num: line number of the opcode
 */

void add_to_queue(stack_t **new_node, unsigned int line_num)
{
	stack_t *current;
	(void) line_num;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	current = head;
	while (current->next != NULL)
		current = current->next;

	current->next = *new_node;
	(*new_node)->prev = current;

}

/**
 * pop_top - adds a node to the stack
 * @stack: pointer to a pointer pointing to top node of the stack
 * @line_num: interger representing the line number of of the opcode
 */

void pop_top(stack_t **stack, unsigned int line_num)
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
 * print_top - Prints the top node of the stack
 * @stack: pointer to a pointer pointing to top node of the stack
 * @line_num: interger representing the line number of of the opcode
 */

void print_top(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
		error_func2(6, line_num);
	printf("%d\n", (*stack)->n);
}
