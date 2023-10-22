#include "monty.h"

/**
 * opc_add - adds value of the stack's two top elements
 * @head: double pointer to the head
 * @line_number: line number
 * Return: nothing or EXIT_FAILURE
 */
void opc_add(stack_t **head, unsigned int line_number)
{
	int top1, top2;

	if (!head || !*head || !(*head)->next)
		add_err(head, line_number);
	top1 = (*head)->n;
	top2 = (*head)->next->n;
	*head = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
	(*head)->n = top1 + top2;
}

/**
 * opc_div - divides value of the stack's two top elements
 * @head: double pointer to the head
 * @line_number: line number the values from the top two elements of the stack
 */
void opc_div(stack_t **head, unsigned int line_number)
{
	int top1, top2;

	if (!head || !*head || !(*head)->next)
		div_err(head, line_number);
	if ((*head)->n == 0)
		zero_err(head, line_number);

	top1 = (*head)->n;
	top2 = (*head)->next->n;
	*head = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
	(*head)->n = top1 / top2;
}

/**
 * opc_mod - modulos of the stack's two top elements
 * @head: double pointer to the head
 * @line_number: line number
 */
void opc_mod(stack_t **head, unsigned int line_number)
{
	int top1, top2;

	if (!head || !*head || !(*head)->next)
		mod_err(head, line_number);
	if ((*head)->n == 0)
		zero_err(head, line_number);
	top1 = (*head)->n;
	top2 = (*head)->next->n;
	*head = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
	(*head)->n = top2 % top1;
}
