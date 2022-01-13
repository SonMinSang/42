#include "push_swap.h"

int is_sorted(t_stack *a)
{
    if (!a)
        exit(1);
    while (a->next)
    {
        if (a->data > a->next->data)
            return (0);
        a = a->next;
    }
    return (1);
}

void sort_three(t_carrier *carrier, t_stack *a)
{
    if (!carrier || !a)
        exit(1);
    // 1 2 3
    if (a->data < a->next->data && a->next->data < a->next->next->data)
        return;
    // 1 3 2
    else if (a->next->next->data > a->data && a->next->data > a->next->next->data)
    {
        sa();
        ra();
    }
    // 2 1 3
    else if (a->data > a->next->data && a->next->next->data > a->data)
        sa();
    // 2 3 1
    else if (a->next->data > a->data && a->data > a->next->next->data)
        rra();
    // 3 1 2
    else if (a->data > a->next->next->data && a->data > a->next->next->data)
        ra();
    // 3 2 1
    else if (a->data > a->next->data && a->next->next->data > a->data)
    {
        ra();
        sa();
    }
    return;
}

int fill_stack(t_stack **a, int size, char **argv, t_carrier *carrier)
{
    int data;
    char **array;

    if (!argv)
        return (0);
    while (*argv)
    {
        array = ft_split(*argv, " ");
        if (!array)
            error(carrier);
        while (*array)
        {
            data = ft_atoi(*array, carrier);
            push(a, data, carrier);
            *array++;
        }
        *argv++;
        free_arr(array);
    }
    isOverlap(a, carrier);
}

void init_carrier(t_carrier *carrier)
{
    carrier->ac_cnt = 0;
    carrier->min = -2147483648;
    carrier->max = 2147483637;
    carrier->pivot = 0;
    carrier->a_cnt = 0;
    carrier->b_cnt = 0;
    carrier->error = 0;
}

int main(int argc, char **argv)
{
    t_carrier carrier;
    t_stack *a;
    t_stack *b;

    a = 0;
    b = 0;
    if (argc < 2)
        exit(0);
    init_carrier(&carrier);
    fill_stack(&a, argc - 1, &argv[1], &carrier);
    push_swap(a, b);
}