#include "monty.h"
/**
 * sub_opcode - subtracts the top element of the stack
 * from the second top element of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack
 * @line_number: Interger representing the line number of of the opcode
 */

void sub_opcode(stack_t **stack, unsigned int line_number)
{

        if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
                error_func2(8, line_number, "sub");

        (*stack)->next->n -= (*stack)->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * div_opcode - divides the second top element of the stack
 * by the top element of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack
 * @line_number: Interger representing the line number of of the opcode
 */

void div_opcode(stack_t **stack, unsigned int line_number)
{

        if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
                error_func2(8, line_number, "div");
	if ((*stack)->n == 0)
                error_func2(9, line_number, "div");

        (*stack)->next->n /= (*stack)->n;
        *stack = (*stack)->next;
        free((*stack)->prev);
        (*stack)->prev = NULL;
}
