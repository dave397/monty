#include "monty.h"

/**
 * _pall - print element to the stack
 * @head: head of stack
 * @counter: line number
 * return: void
 */

void _pall(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *temp;

	temp = *head;

	if (*head == NULL)
		return;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
