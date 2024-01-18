#include "stacks.h"
/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty file.
 * Description: The swap opcode swaps the top two elements of the stack.
 * If the stack contains less than two elements, exits with EXIT_FAILURE.
 */
void swap(stack_t **stack, unsigned int line_number)
{
         stack_t *num1, *num2;
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }


    num1 = *stack;
    num2 = num1->next;

    num1->prev = num2;
    num1->next = num2->next;

    if (num2->next != NULL)
    {
        num2->next->prev = num1;
    }

    num2->prev = NULL;
    num2->next = num1;

    *stack = num2;
}

/**
 * add - Adds the top two elements of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty fiLE.
 *
 * Description: The add opcode adds the top two elements of the stack.
 * when the stack contain less than 2 elements exits with EXIT_FAILURE.
 */
void add(stack_t **stack, unsigned int line_number)
{
        int sum;
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    sum = (*stack)->next->n + (*stack)->n;
    (*stack)->next->n = sum;
    pop(stack, line_number);
}

/**
 * nop - Does nothing.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty file.
 * Description: The nop opcode does nothing.
 */
void nop(stack_t **stack, unsigned int line_number)
{
        (void)stack;
        (void)line_number;
}
