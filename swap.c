#include "monty.h"

/**
 * _swap - interchange top two element
 * @head: head of stack
 * @counter: line number
 * return: void
 */

void _swap(stack_t **head, unsigned int counter)
{
	stack_t *holder;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", counter);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	holder = (*head)->next;
	(*head)->next = holder->next;
	if (holder->next != NULL)
		(holder->next)->prev = *head;
	holder->prev = NULL;
	holder->next = *head;
	(*head)->prev = holder;

	*head = holder;
}
