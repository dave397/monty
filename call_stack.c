#include "monty.h"

/**
 * call_stack - handle stack action
 * @buffer: content of line
 * @stack: stack
 * @counter: line length
 * Return: 0 success, 1 error
 */

int call_stack(char *buffer, stack_t **stack, unsigned int counter)
{

	instruction_t oprList[] = {
	    {"push", _push}, {"pall", _pall}, {"pint", _pint},
	    {"pop", _pop},   {"swap", _swap}, {"add", _add},
	    {"nop", _nop},   {"sub", _sub},   {NULL, NULL}};

	unsigned int j = 0;

	char *cmd = strtok(buffer, " \n\t");

	original = strtok(NULL, " \n\t");

	while (oprList[j].opcode && cmd)
	{
		if (strcmp(cmd, oprList[j].opcode) == 0)
		{
			oprList[j].f(stack, counter);
			return (0);
		}
		j += 1;
	}
	if (cmd && oprList[j].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instructions %s\n", counter, cmd);
	}

	return (1);
}
