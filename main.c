#include "monty.h"
/**
 *free_stack- frees the elements of the stack
 *@stack: pointer to the head node
 */
void free_stack(stack_t **stack)
{
	stack_t *node = NULL;

	if (!stack || !*stack)
		return;
	while (*stack)
	{
		node = *stack;
		*stack = (*stack)->next;
		free(node);
	}
}

/**
 * main - execution of  Monty
 * @argc: arg count
 * @argv: arg vectors
 * Return: 0
 */
int main(int argc, char **argv)
{
	FILE *file_p;
	char *line_buffer = NULL;
	char op_buffer[20], val_buffer[20];
	ssize_t bytes_read = 0, tokens = 0;
	size_t buffer_size = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2 || !argv[1])
		use_err();
	variable_s.queue = 0;
	variable_s.file = argv[1];
	file_p = fopen(variable_s.file, "r");
	if (!file_p)
		file_err();
	while ((bytes_read = getline(&line_buffer, &buffer_size, file_p)) != -1)
	{
		line_number++;
		tokens = sscanf(line_buffer, "%s %s", op_buffer, val_buffer);

		if (tokens > 2)
		{
			free(line_buffer);
			use_err();
		}
		free(line_buffer);
		line_buffer = NULL;
		variable_s.opcode = op_buffer;
		variable_s.n = val_buffer;
		if (tokens > 0 && variable_s.opcode[0] != '#')
			get_opc(variable_s.opcode)(&stack, line_number);
		memset(op_buffer, '\0', sizeof(op_buffer));
		memset(val_buffer, '\0', sizeof(val_buffer));
	}
	free(line_buffer);
	free_stack(&stack);
	fclose(file_p);
	return (0);
}
