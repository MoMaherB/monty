#include "stacks.h"
/**
 * pint - Prints the value at the top of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty file where the operation is called.
 * Description: The pint opcode prints the value at the top of the stack,
 * when the stack is empty exits with EXIT_FAILURE.
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}

/**
 * pop - Removes the top element of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty file where the operation is called.
 * Description: The pop opcode removes the top element of the stack.
 * prints an error message and exits with EXIT_FAILURE.
 */
void pop(stack_t **stack, unsigned int line_number)
{
        stack_t *top;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    top = *stack;

    *stack = (*stack)->next;

    if (*stack != NULL)
    {
        (*stack)->prev = NULL;
    }

    free(top);
}
