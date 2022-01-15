#include "push_swap.h"

//��� ��带 ��ȸ�ϸ� ��� free
void free_stack(t_stack **stack)
{
    t_stack *temp;
    t_stack *next;

    if (*stack == 0)
        return;
    temp = *stack;
    while (temp)
    {
        next = temp->next;
        free(temp);
        temp = next;
    }
}

// array freea �Լ�
void free_arr(char **arr)
{
    int i;

    i = 0;
    if (arr)
    {
        while (arr[i])
        {
            free(arr[i]);
            i++;
        }
        free(arr);
    }
}