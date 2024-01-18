#include "stacks.h"
/**
 * handle_file - Handles Monty commands from an open file.
 * @file: Pointer to the open Monty file.
 *
 * Description: Reads commands from the provided file.
 */
void handle_file(FILE *file)
{
	char *line = NULL, *opcode;
	size_t len = 0;
	int line_number = 0, i;
	stack_t *stack = NULL;

	instruction_t monty_funcs[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add}, {"nop", nop}, {NULL, NULL}
	};
	while ((getline(&line, &len, file)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \n");
		if (opcode != NULL)
		{
			for (i = 0; monty_funcs[i].opcode != NULL; i++)
			{
				if (strcmp(opcode, monty_funcs[i].opcode) == 0)
				{
					monty_funcs[i].f(&stack, line_number);
					break;
				}
			}
			if (monty_funcs[i].opcode == NULL)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
				fclose(file);
				free(line);
				exit(EXIT_FAILURE);
			}
		}
	}
	free(line);
	free_stack(stack);
}
