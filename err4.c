#include "monty.h"

/**
 * mod_err - handle errors of opcode mod
 *@stack: pointer to the head node
 *@line_number: where error ocured
 */
void mod_err(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
