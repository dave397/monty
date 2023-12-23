#include "monty.h"

/**
 * main - entry point
 * @argc: argument counts
 * @av: pinter to arguments
 * Return: 0 on success
 */
char *original = NULL;

int main(int argc, char **av)
{
	FILE *file;
	char buffer[BUFFER_SIZE];
	unsigned int counter = 0;
	stack_t *stack = NULL;
	int trace = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		counter += 1;
		trace = call_stack(buffer, &stack, counter);
		if (trace == 1)
		{
			fclose(file);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
	}

	fclose(file);
	free_stack(stack);
	return (0);
}
