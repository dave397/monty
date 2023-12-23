#include "monty.h"

/**
 * _push - add element to the stack
 * @head: head of stack
 * @counter: line number
 * return: void
 */

void _push(stack_t **head, unsigned int counter)
{
	int n, track = 0, error = 0;

	if (original)
	{
		/* check if value is negative */
		if (original[0] == '-')
			track++;

		for (; original[track] != '\0'; track++)
		{
			if (original[track] > 57 || original[track] < 47)
				error = 1;
		}
		if (error == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		exit(EXIT_FAILURE);
	}
	n = atoi(original);
	addstack(head, n);
}
