#include "monty.h"

/**
 *opcode_err- msg to an ivalid instructions
 *@stack: pointer to the head node
 *@line_number: where error ocured
 */
void opcode_err(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: unknown instruction %s\n",
		line_number, variable_s.opcode);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 *pint_err- op_pint error handling function
 *@stack: pointer to the head node
 *@line_number: where error ocured
 */

void pint_err(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	free_stack(stack);
}

/**
 *pop_err-handles error for op_pop function
 *@stack: pointer to the head node
 *@line_number: where error ocured
 */

void pop_err(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 *swap_err-handles error for op_swap function
 *@stack: pointer to the head node
 *@line_number: where error ocured
 */
void swap_err(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't swap, stack to short\n", line_number);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
/**
 *add_err- handles error for op_add function
 *@stack: pointer to the head node
 *@line_number: where error ocured
 */
void add_err(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't add, stack too short \n", line_number);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
