#include <stdio.h>
#include "push_swap.h"

void error(t_carrier *carrier)
{
    if (!carrier->error)
    {
        printf("Error\n");
        carrier->error = 1;
    }
}

static int ft_check(char s, char c)
{
    if (s == c)
        return (1);
    return (0);
}

static int ft_size(const char *str, char c)
{
    int size;
    int index;

    size = 0;
    index = 0;
    while (str[index])
    {
        while (str[index] && ft_check(str[index], c))
            index++;
        if (str[index] && !ft_check(str[index], c))
        {
            while (str[index] && !ft_check(str[index], c))
                index++;
            size++;
        }
    }
    return (size);
}

static char *ft_input(const char *str, char c)
{
    int index;
    int count;
    char *input;

    index = 0;
    count = 0;
    while (str[count] && !ft_check(str[count], c))
        count++;
    if (!(input = (char *)malloc(sizeof(char) * (count + 1))))
        return (NULL);
    while (str[index] && !ft_check(str[index], c))
    {
        input[index] = str[index];
        index++;
    }
    input[index] = 0;
    return (input);
}

static char **free_all(char **result, int index)
{
    while (index-- >= 0)
        free((void *)result[index]);
    free(result);
    return (NULL);
}

char **ft_split(char const *s, char c)
{
    char **result;
    int index;

    if (!s)
        return (NULL);
    if (!(result = (char **)malloc(sizeof(char *) * (ft_size(s, c) + 1))))
        return (NULL);
    index = 0;
    while (*s)
    {
        while (*s && ft_check(*s, c))
            s++;
        if (*s && !ft_check(*s, c))
        {
            result[index] = ft_input(s, c);
            if (!result[index])
                return (free_all(result, index));
            while (*s && !ft_check(*s, c))
                s++;
            index++;
        }
    }
    result[index] = 0;
    return (result);
}

static int ouflow(unsigned long long number, int minus)
{
    if (number > 2147483637 && minus == -1)
        return (-1);
    if (number > 2147483648 && minus == 1)
        return (0);
    return (1);
}

int ft_atoi(char *str, t_carrier *carrier)
{
    int minus;
    long number;

    minus = 1;
    number = 0;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            minus = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        number *= 10;
        number += *str - '0';
        str++;
        if (ouflow(number, minus) != 1)
            error(carrier);
    }
    if (*str && (*str < '0' || *str > '9'))
        error(carrier);
    return (minus * number);
}

void isOverlap(t_stack **a, t_carrier *carrier)
{
    // t_stack *temp;
    // int     data;
    // temp = *a;
    // while (temp->next)
    // {
    //     data = temp->data;
    //     while

    //     temp = temp->next;
    // }
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
        {
            free(array[index]);
            index++;
        }
        free(array);
    }
}

int fill_stack(t_stack **a, int size, char **argv, t_carrier *carrier)
{
    int data;
    char **array;

    if (!argv)
        return (0);
    while (*argv)
    {
        array = ft_split(*argv, ' ');
        if (!array)
            error(carrier);
        while (*array)
        {
            data = ft_atoi(*array, carrier);
            init_push_a(a, data, carrier);
            *array++;
        }
        *argv++;
        free_arr(array);
    }
    isOverlap(a, carrier);

    if (carrier->error)
        free_stack(a);
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
        node->next = *stack;
        *stack = node;
    }
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
    t_stack *t;

    a = 0;
    b = 0;
    if (argc < 2)
        exit(0);
    init_carrier(&carrier);
    fill_stack(&a, argc - 1, &argv[1], &carrier);

    printf("%d\n", a->data);
    printf("%d\n", a->next->data);
    t = pop(&a);
    push(&b, t);
    t = pop(&a);
    push(&b, t);
    printf("%d\n", a->data);
    printf("b->data: %d\n", b->data);
    printf("b->next->data: %d\n", b->next->data);
    system("leaks a.exe");
}