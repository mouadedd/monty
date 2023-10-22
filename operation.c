#include "monty.h"
/**
 * get_opc- look for instructions for the opcode functions
 * @str: opcode to find
 * Return: ptr to the wanted function or, opcode_err
 */
void (*get_opc(char *str))(stack_t **, unsigned int)
{
	int i = 0;
	instruction_t instr[] = {
		{"push", opc_push}, {"pall", opc_pall},
		{"pint", opc_pint}, {"pop", opc_pop},
		{"swap", opc_swap}, {"add", opc_add},
		{"nop", opc_nop}, {"sub", opc_sub},
		{"div", opc_div}, {"mul", opc_mul},
		{"mod", opc_mod}, {"pchar", opc_pchar},
		{"#", opc_nop}, {NULL, NULL}
	};

	while (instr[i].opcode)
	{
		if (strcmp(instr[i].opcode, str) == 0)
			return (instr[i].f);
		i++;
	}

	return (opcode_err);
}
