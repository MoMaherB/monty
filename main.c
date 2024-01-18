#include "monty.h"
/**
 * main - Entry point monty program.
 * @argc: Number arguments.
 * @argv: Array of argument strings.
 *
 * Return: Return 0 on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	handle_file(file);
	fclose(file);
	return (0);
}
