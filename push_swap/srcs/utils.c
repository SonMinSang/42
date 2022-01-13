#include "push_swap.h"

void error(t_carrier *carrier)
{
    if (!carrier->error)
    {
        ft_putstr("Error\n");
        carrier->error = 1;
    }
}

void isOverlap(t_stack **a, t_carrier *carrier)
{
    t_stack *temp;
    t_stack *comp;

    temp = *a;
    while (temp)
    {
        comp = temp->next;
        while (comp)
        {
            if (temp->data == comp->data)
            {
                error(carrier);
                return;
            }
            comp = comp->next;
        }
        temp = temp->next;
    }
}

void init_push_a(t_stack **stack, int data, t_carrier *carrier)
{
    t_stack *temp;

    temp = (t_stack *)malloc(sizeof(t_stack));
    if (!temp)
        error(carrier);
    temp->data = data;
    if (data > carrier->max)
        carrier->max = data;
    if (data < carrier->min)
        carrier->min = data;
    carrier->ac_cnt++;
    carrier->a_cnt++;
    if (*stack == 0)
    {
        *stack = temp;
        (*stack)->next = *stack;
        (*stack)->prev = *stack;
        return;
    }

    (*stack)->prev->next = temp;
    (*stack)->prev = temp;
    temp->next = *stack;
}

t_stack *pop(t_stack **stack)
{
    t_stack *pop;

    if (!stack)
        return (0);
    pop = *stack;
    if ((*stack)->next)
    {
        (*stack)->prev->next = (*stack)->next;
        (*stack)->next->prev = (*stack)->next;
        *stack = (*stack)->next;
    }
    pop->next = 0;
    pop->prev = 0;
    return (pop);
}

void push(t_stack **stack, t_stack *node)
{
    if (*stack == 0)
    {
        node->prev = node;
        node->next = node;
        *stack = node;
    }
    else
    {
        node->prev = (*stack)->prev;
        (*stack)->prev = 0;
        node->next = *stack;
        *stack = node;
    }
}