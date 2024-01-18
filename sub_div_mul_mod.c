#include "monty.h"
/**
 * sub - Subtracts top element from the second top element.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty file.
 * Description: If stack has less than two elements, prints an error.
 */
void sub(stack_t **stack, unsigned int line_number)
{
        int sub;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    sub = (*stack)->next->n - (*stack)->n;
     (*stack)->next->n = sub;
    pop(stack, line_number);
}

/**
 * div_op - Divides the second top element by the top element of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty file.
 *
 * Description: store the divide od second element of top elemnt in second
 * element and remove the first one. if div/zero or less than 2 print error.
 */
void div(stack_t **stack, unsigned int line_number)
{
        int div;
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    div = (*stack)->next->n / (*stack)->n;
    (*stack)->next->n = div;
    pop(stack, line_number);
}

/**
 * mul_op - Multiplies the first 2 elements of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty file.
 *
 * Description: store the result in one element and remove the other one.
 */
void mul(stack_t **stack, unsigned int line_number)
{
        int mul;
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    mul = (*stack)->next->n * (*stack)->n;
    (*stack)->next->n = mul;
    pop(stack, line_number);
}

/**
 * mod_op - Computes the rest of the division of the second top by the top element.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty file where the operation is called.
 *
 * Description: The mod opcode computes the rest of the division of the second top
 * element of the stack by the top element. If the stack contains less than two
 * elements, it prints an error message and exits with EXIT_FAILURE. If the top
 * element is 0, it prints a division by zero error and exits with EXIT_FAILURE.
 * The result is stored in the second top element, and the top element is removed.
 */
void mod(stack_t **stack, unsigned int line_number)
{
        int mod;
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    mod = (*stack)->next->n % (*stack)->n;
    (*stack)->next->n = mod;
    pop(stack, line_number);

}
