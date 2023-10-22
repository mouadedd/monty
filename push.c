#include "monty.h"
/**
 * opc_push - pushe a value
 * @head: pointer to the head node
 * @line_number: line number
 */
void opc_push(stack_t **head, unsigned int line_number)
{
	stack_t *pushed_node = NULL, *tail = NULL;
	size_t i = 0;

	if (!head || !line_number)
		exit(EXIT_FAILURE);
	if (variable_s.n[i] == '\0')
		push_error(head, line_number);
	pushed_node = malloc(sizeof(stack_t));
	if (!pushed_node)
		malloc_err(head);
	for (; variable_s.n[i] != '\0'; i++)
		if (isdigit(variable_s.n[i]) == 0 && variable_s.n[i] != '-')
			push_error(head, line_number);
	pushed_node->n = atoi(variable_s.n);
	if (variable_s.queue == 1)
	{
		pushed_node->next = NULL;
		if (!*head)
		{
			pushed_node->prev = NULL;
			*head = pushed_node;
		}
		else
		{
			tail = *head;
			while ((*tail).next)
				tail = tail->next;
			pushed_node->prev = tail;
			tail->next = pushed_node;
		}
	}
	else
	{
		pushed_node->prev = NULL;
		pushed_node->next = *head;
		if (*head)
			(*head)->prev = pushed_node;
		*head = pushed_node;
	}
}
