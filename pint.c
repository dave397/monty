#include "monty.h"

/**
 * _pint - print element at the top of stack
 * @head: head of stack
 * @counter: line number
 * return: void
 */

void _pint(stack_t **head, unsigned int counter)
{
	stack_t *temp;

	temp = *head;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", temp->n);
}
