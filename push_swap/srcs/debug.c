#include "push_swap.h"

void print_stack(t_carrier *carrier, t_stack *stack)
{
    t_stack *curr;

    if (!carrier)
    {
        printf("no carrier");
        return;
    }
    if (!stack)
    {
        printf("no stack");
        return;
    }
    curr = stack;
    printf(">>> stack <<<  \n");
    while (curr)
    {
        printf("%d\n", curr->data);
        curr = curr->next;
    }
    printf(">>>>>> <<<<<<\n");
    return;
}