#include "stacks.h"
/**
 * push - Pushes an element onto the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty file.
 *
 * Description: The push opcode pushes an element onto the stack.
 * If the argument is not an integer or if there is no argument,
 * it prints an error message and exits with EXIT_FAILURE.
 */
void push(stack_t **stack, unsigned int line_number)
{
        char *value;
        stack_t *newnode;

    value = strtok(NULL, " \n");
    if (value[0] == '\0' || (!isdigit(value[0]) && value[0] != '-'))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    newnode = malloc(sizeof(stack_t));
    if (newnode == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    newnode->n = atoi(value);
    newnode->prev = NULL;
    newnode->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = newnode;

    *stack = newnode;
}
/**
 * pall - Prints all values on the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty file.
 * Description: The pall opcode prints all the values on the stack,
 * starting from the top of the stack.
 */

void pall(stack_t **stack, unsigned int line_number)
{
        stack_t *temp;

    (void)line_number;

   temp = *stack;
    while (temp != NULL)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}
