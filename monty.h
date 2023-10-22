#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct variable_s - shared variables
 * @n: value of the added node
 * @file: readed monty file
 * @opcode: parsed command token
 * @queue: (fifo), queue mode
 * Description: used to help handle errors
 */
struct variable_s
{
	char *n, *opcode;
	char *file;
	int queue;
} variable_s;

/*manipulation functions*/
void (*get_opc(char *str))(stack_t **stack, unsigned int line_number);
void free_stack(stack_t **stack);

/*errors*/
void opcode_err(stack_t **stack, unsigned int line_number);
void pint_err(stack_t **stack, unsigned int line_number);
void pop_err(stack_t **stack, unsigned int line_number);
void swap_err(stack_t **stack, unsigned int line_number);
void add_err(stack_t **stack, unsigned int line_number);
void use_err(void);
void div_err(stack_t **stack, unsigned int line_number);
void sub_err(stack_t **stack, unsigned int line_number);
void opchar_err(stack_t **stack, unsigned int line_number);
void zero_err(stack_t **stack, unsigned int line_number);
void char_err(stack_t **stack, unsigned int line_number);
void file_err(void);
void push_error(stack_t **stack, unsigned int line_number);
void malloc_err(stack_t **stack);
void mul_err(stack_t **stack, unsigned int line_number);
void mod_err(stack_t **stack, unsigned int line_number);

/*opcde functions*/
void opc_add(stack_t **stack, unsigned int line_number);
void opc_div(stack_t **stack, unsigned int line_number);
void opc_mod(stack_t **stack, unsigned int line_number);
void opc_mul(stack_t **stack, unsigned int line_number);
void opc_pall(stack_t **stack, unsigned int line_number);
void opc_nop(stack_t **stack, unsigned int line_number);
void opc_pchar(stack_t **stack, unsigned int line_number);
void opc_pint(stack_t **stack, unsigned int line_number);
void opc_pop(stack_t **stack, unsigned int line_number);
void opc_sub(stack_t **stack, unsigned int line_number);
void opc_swap(stack_t **stack, unsigned int line_number);
void opc_push(stack_t **stack, unsigned int line_number);

#endif
