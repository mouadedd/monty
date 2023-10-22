#include "monty.h"

/**
 * opc_mul - product of the stack's two top elements
 * @head: double pointer to the head
 * @line_number: line number the values of the top two elements of the stack
 */
void opc_mul(stack_t **head, unsigned int line_number)
{
	int top1, top2;

	if (!head || !*head || !(*head)->next)
		mul_err(head, line_number);
	top1 = (*head)->n;
	top2 = (*head)->next->n;
	*head = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
	(*head)->n = top1 * top2;
}

/**
 * opc_pall - prints the stack elements
 * @stack: double pointer to head node
 * @line_number: line numbe
 * Return: nothing, or EXIT_FAILURE
 */
void opc_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node = NULL;

	if (!line_number)
		return;
	node = *stack;
	while (node)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}

/**
 * opc_nop - unused opcode
 * @stack: double pointer to head node
 * @line_number: line number
 * Return: nothing
 */
void opc_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * opc_pchar - prints the value at the top of the stack as a character
 * @head: pointer to the head node
 * @line_number: line number
 *
 */
void opc_pchar(stack_t **head, unsigned int line_number)
{
	if (!head || !*head)
		opchar_err(head, line_number);
	if ((*head)->n > 127 || (*head)->n < 0)
		char_err(head, line_number);
	printf("%c\n", (*head)->n);
}
