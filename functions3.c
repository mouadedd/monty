#include "monty.h"
/**
 * opc_pint - prints stacj's head value
 * @head: double pointer to head node
 * @line_number: line number
 * Return: nothing, or EXIT_FAILURE
 */
void opc_pint(stack_t **head, unsigned int line_number)
{
	if (!head || !*head)
		pint_err(head, line_number);
	printf("%d\n", (*head)->n);
}

/**
 * opc_pop - pop element of the stack
 * @head: double pointer to head node
 * @line_number: line number
 * Return: nothing, or EXIT_FAILURE
 */
void opc_pop(stack_t **head, unsigned int line_number)
{
	stack_t *node;

	if (!head || !*head)
		pop_err(head, line_number);
	node = *head;

	if (!node->next)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		(*head) = (*head)->next;
		(*head)->prev = NULL;
		free(node);
	}
}

/**
 * opc_sub - subtracts the top two elements of stack
 * @head: double pointer to head node
 * @line_number: line number
 */
void opc_sub(stack_t **head, unsigned int line_number)
{
	int top1, top2;

	if (!head || !*head || !(*head)->next)
		sub_err(head, line_number);
	top1 = (*head)->n;
	top2 = (*head)->next->n;
	*head = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
	(*head)->n = top2 - top1;
}

/**
 * opc_swap - swaps the two top elements
 * @head: double pointer to head node
 * @line_number: line number
 * Return: nothing, or code EXIT_FAILURE
 */
void opc_swap(stack_t **head, unsigned int line_number)
{
	int temp_val;

	if (!head || !*head || (*head)->next == NULL)
		swap_err(head, line_number);
	temp_val = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = temp_val;
}
