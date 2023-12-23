#include "monty.h"

/**
 * _pop - print element at the top of stack
 * @head: head of stack
 * @counter: line number
 * return: void
 */

void _pop(stack_t **head, unsigned int counter)
{
	stack_t *temp, *holder;

	temp = *head;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", counter);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (temp->next == NULL)
	{
		free(temp);
		*head = NULL;
	}
	else
	{
		holder = temp->next;
		holder->prev = NULL;
		*head = holder;
	}
}
