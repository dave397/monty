#include "monty.h"

/**
 * _add - add top element of stack
 * @head: head of stack
 * @counter: line number
 * return: void
 */

void _add(stack_t **head, unsigned int counter)
{
	int n = 0;
	stack_t *temp, *holder;

	temp = (*head)->next->next;
	holder = malloc(sizeof(stack_t));

	if (holder == NULL)
	{
		perror("Error:");
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", counter);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	n = (*head)->n + (*head)->next->n;
	holder->prev = NULL;
	holder->n = n;

	if (temp != NULL)
		temp->prev = holder;
	holder->next = temp;
	holder->prev = NULL;

	*head = holder;
}
