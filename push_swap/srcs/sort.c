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

void sort_three(t_carrier *carrier, t_stack **a)
{
    if (!carrier || !a)
        exit(1);
    // 1 2 3
    if ((*a)->data < (*a)->next->data && (*a)->next->data < (*a)->next->next->data)
        return;
    // 1 3 2
    else if ((*a)->next->next->data > (*a)->data && (*a)->next->data > (*a)->next->next->data)
    {
        sa(a);
        ra(a);
    }
    // 2 1 3
    else if ((*a)->data > (*a)->next->data && (*a)->next->next->data > (*a)->data)
        sa(a);
    // 2 3 1
    else if ((*a)->next->data > (*a)->data && (*a)->data > (*a)->next->next->data)
        rra(a);
    // 3 1 2
    else if ((*a)->data > (*a)->next->next->data && (*a)->data > (*a)->next->next->data)
        ra(a);
    // 3 2 1
    else if ((*a)->data > (*a)->next->data && (*a)->next->next->data > (*a)->data)
    {
        ra(a);
        sa(a);
    }
    return;
}

void descending(t_carrier *carrier, t_stack *a, t_stack *b)
{
}

// 스택 a에서 5개 숫자 오름차순 정렬
void sort_five(t_carrier *carrier, t_stack **a, t_stack **b)
{
    int max;
    int min;
    t_stack *curr;
    int i;

    if (!carrier || !a)
        return;
    printf("sort five in\n");
    curr = *a;
    max = find_max(carrier, a);
    min = find_min(carrier, a);
    printf("min : %d\n", min);
    printf("max : %d\n", max);

    //스택 순회하며 min,mix 타 스택으로 보내기
    i = 0;
    while (i < 5)
    {
        if ((*a)->data == min || (*a)->data == max)
        {
            pb(carrier, a, b);
            printf("pb\n");
        }
        else
            ra(a);
        i++;
    }
    sort_three(carrier, a);
    printf("sort three in sort five\n");
    //타 스택의 위가 max가 되도록 swap
    printf("b count : %d\n", carrier->b_cnt);
    if ((*b)->data != max)
        sb(b);
    printf("after sa\n");
    // push 후 reverse 후 push
    pa(carrier, a, b);
    ra(a);
    pa(carrier, a, b);
    return;
}