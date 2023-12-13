#include "monty.h"

/**
 * create_node - Creates a node
 * @n: number to go inside the node
 * Return: upon sucess a pointer to the node. Otherwise NULL
 */

stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		error_func1(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_node - frees node in the stack
 */

void free_node(void)
{
	stack_t *current;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
}

/**
 * push_in_stack - adds a node to the stack
 * @new_node: Pointer to the new node
 * @line_num: interger representing the line number of the opcode
 */

void push_in_stack(stack_t **new_node, unsigned int line_num)
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
	head = *new_node;
	head->next = current;
	current->prev = head;
}



/**
 * print_stack - adds a node to the stack
 * @stack: Pointer to a pointer pointing to top node of the stack
 * @line_num: line number of  the opcode
 */

void print_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *current;

	(void) line_num;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * push_in_queue - adds a node to the queue
 * @new_node: pointer to the new node
 * @line_num: line number of the opcode
 */

void push_in_queue(stack_t **new_node, unsigned int line_num)
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
