#ifndef MONTY_H
#define MONTY_H
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#define BUFFER_SIZE 1024
extern char *original;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int call_stack(char *buffer, stack_t **stack, unsigned int counter);
void _push(stack_t **head, unsigned int counter);
void _pall(stack_t **head, unsigned int counter);
void _pint(stack_t **head, unsigned int counter);
void addstack(stack_t **head, int n);
void free_stack(stack_t *head);
void _pop(stack_t **head, unsigned int counter);
void _swap(stack_t **head, unsigned int counter);
void _add(stack_t **head, unsigned int counter);
void _nop(__attribute__((unused)) stack_t **head,
	  __attribute__((unused)) unsigned int counter);
void _sub(stack_t **head, unsigned int counter);

#endif