#include "monty.h"

/**
 *char_err- error in characters
 *@stack: pointer to the head node
 *@line_number: where error ocured
 */

void char_err(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 *file_err- display broken files
 */
void file_err(void)
{
	fprintf(stderr, "Error: Can't open file %s \n", variable_s.file);
	exit(EXIT_FAILURE);
}

/**
 *push_error- handle syntax errors for opcode push
 *@stack: pointer to the head node
 *@line_number: where error ocured
 */
void push_error(stack_t **stack, unsigned int line_number)
{
	 fprintf(stderr, "L%d: usage: push integer\n", line_number);
	 free_stack(stack);
	 exit(EXIT_FAILURE);
}

/**
 *malloc_err- malloc errors
 *@stack: pointer to the head node
 */
void malloc_err(stack_t **stack)
{
	fprintf(stderr, "Error: malloc failed \n");
	free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * mul_err - handle errors of opcode mul
 *@stack: pointer to the head node
 *@line_number: where error ocured
 * Return: nothing
 */
void mul_err(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
