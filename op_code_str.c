#include "monty.h"

/**
 * print_c - prints a char using ascii value
 * @stack: pointer to a pointer pointing to top node of the stack
 * @line_number: interger representing the line number of of the opcode
 */

void print_c(stack_t **stack, unsigned int line_num)
{
	int i;

	if (stack == NULL || *stack == NULL)
		string_error(11, line_num);

	i = (*stack)->n;
	if (i < 0 || i > 127)
		string_error(10, line_num);

	printf("%c\n", i);
}

/**
 * print_str - prints a string using ascii value
 * @stack: pointer to a pointer pointing to top node of the stack
 * @line_num: interger representing the line number of of the opcode
 */

void print_str(stack_t **stack, unsigned int line_num)
{
	int i;
	stack_t *current;
	(void) line_num;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	current = *stack;
	while (current != NULL)
	{
		i = current->n;
		if (i <= 0 || i > 127)
			break;

		printf("%c", i);
		current = current->next;
	}
	printf("\n");
}

/**
 * rotate_l - rotates the first node of the stack to the bottom
 * @stack: pointer to a pointer pointing to top node of the stack
 * @line_num: interger representing the line number of of the opcode
 */
void rotate_l(stack_t **stack, unsigned int line_num)
{
	stack_t *current;
	(void) line_num;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	current = *stack;
	while (current->next != NULL)
		current = current->next;

	current->next = *stack;
	(*stack)->prev = current;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotate_r - rotates the last node of the stack to the top
 * @stack: Pointer to a pointer pointing to top node of the stack
 * @line_num: interger representing the line number of of the opcode
 */

void rotate_r(stack_t **stack, unsigned int line_num)
{
	stack_t *current;
	(void) line_num;

	if (*stack == NULL || stack == NULL || (*stack)->next == NULL)
		return;

	current = *stack;

	while (current->next != NULL)
		current = current->next;

	current->next = *stack;
	current->prev->next = NULL;
	current->prev = NULL;
	(*stack)->prev = current;
	(*stack) = current;
}
