#include "monty.h"

/**
 *use_err-mark inputs wrong syntax
 */

void use_err(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * div_err - handles error for the opcod div
 *@stack: pointer to the head node
 *@line_number: where error ocured
 * Return: nothing
 */
void div_err(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 *sub_err- handles error of the opcode sub
 *@stack: pointer to the head node
 *@line_number: where error ocured
 */
void sub_err(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * opchar_err - handles the opc char error
 *@stack: pointer to the head node
 *@line_number: where error ocured
 */
void opchar_err(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * zero_err -  handles the zero error
 *@stack: pointer to the head node
 *@line_number: where error ocured
 */
void zero_err(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: division by zero\n", line_number);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
