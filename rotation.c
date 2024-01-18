#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty file.
 *
 * Description: put the first at the last and start from the second.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *f_temp, *l_temp;

	(void)line_number;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		f_temp = l_temp = *stack;
		while (l_temp->next != NULL)
			l_temp = l_temp->next;
		*stack = f_temp->next;
		(*stack)->prev = NULL;
		f_temp->next = NULL;
		f_temp->prev = l_temp;
		l_temp->next = f_temp;
	}
}
/**
 * rotr - Rotates the stack to the bottom.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty file.
 *
 * Description: The rotr opcode rotates the stack to the bottom.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *f_temp, *l_temp;

	(void)line_number;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		f_temp = l_temp = *stack;

		while (l_temp->next != NULL)
		{
			f_temp = l_temp;
			l_temp = l_temp->next;
		}

		f_temp->next = NULL;
		l_temp->prev = NULL;
		l_temp->next = *stack;
		(*stack)->prev = l_temp;
		*stack = l_temp;
	}
}
