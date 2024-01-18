#include "stacks.h"
/**
 * free_stack - Frees the memory allocated for a stack.
 * @stack: Pointer to the head of the stack.
 *
 * Description: Frees the memory for each node in the stack.
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
