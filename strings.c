#include "monty.h"

/**
 * pchar_op - Prints the character at the top of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty file.
 *
 * Description: The pchar opcode prints the character at the top .
 */
void pchar_op(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar((*stack)->n);
	putchar('\n');
}
/**
 * pstr_op - Prints the string starting at the top of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty file where the operation is called.
 *
 * Description: The pstr opcode prints the string starting at the top of stack
 */
void pstr_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	while (temp != NULL && temp->n > 0  && temp->n <= 127)
	{
		putchar(temp->n);
		temp = temp->next;
	}

	putchar('\n');
}
