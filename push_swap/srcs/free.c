#include "push_swap.h"

void free_stack(t_stack **stack)
{
    t_stack *temp;
    t_stack *next;

    if (*stack == 0)
        return;
    temp = *stack;
    while (temp != 0)
    {
        next = temp->next;
        free(temp);
        temp = next;
    }
}

void free_arr(char **array)
{
    int index;

    index = 0;
    if (array != 0)
    {
        while (array[index])
            free(array[index]);
        free(array[index]);
        free(array);
    }
}
