#include "monty.h"

/**
 * addstack - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
 */

void addstack(stack_t **head, int n)
{

	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		perror("Error:\n");
		exit(EXIT_FAILURE);
	}
	if (temp)
		temp->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
