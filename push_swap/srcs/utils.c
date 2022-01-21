#include "push_swap.h"

//?��?�� 출력 ?��?��. ?��?�� ?�� carrier->error 멤버 �? == 1
void        error(t_carrier *carrier)
{
    if (!carrier)
        exit(1);
    if (!carrier->error)
    {
        printf("Error\n");
        carrier->error = 1;
    }
}

// A?��?�� ?���??�� 중복 ?��?�� ?���?�? ?��?��?��?�� ?��?��
void        is_overlapped(t_carrier *carrier, t_stack **a)
{
    t_stack *temp;
    t_stack *comp;

    temp = *a;
    while (temp != 0)
    {
        comp = temp->next;
        while (comp != 0)
        {
            if (temp->data == comp->data)
            {
                error(carrier);
                printf("is overlapped!\n");
                return ;
            }
            comp = comp->next;
        }
        temp = temp->next;
    }
}

// ??? ?��?��?�� ?��?��?��?��?�� ?��보�?? 바꿔주는 ?��?�� ?
void        init_pushed_stack(t_carrier *carrier, t_stack **stack, int data)
{
    t_stack *temp;
    t_stack *tail;

    temp = (t_stack *)malloc(sizeof(t_stack));
    if (!temp)
    {
        printf("mallocation of temp failed\n");     
        error(carrier);
    }
    temp->data = data;
    //최�??�? 최소�? ?��?�� ?��?��
    if (data > carrier->max)
        carrier->max = data;
    if (data < carrier->min)
        carrier->min = data;
    // string?��?���? ?��?��?��?�� ac_cnt == 1 ?���? ?��문에 ac_cnt++;
    carrier->ac_cnt++;
    carrier->a_cnt++;
    carrier->arem_cnt++;
    //�? ?��?��?�� ?��?��?��?�� 경우
    if (*stack == 0)
    {
        *stack = temp;
        (*stack)->prev = *stack;
        return ;
    }
    tail = (*stack)->prev;
    temp->next = 0;
    tail->next = temp;
    //?���? ?��?��?�� ?��?���? 기존 ?��?��?�� ?��?�� ?��?���? ?���?
    temp->prev = tail;
    (*stack)->prev = temp;
}


//?��?��?��?�� head?��?���? 꺼내�? 반환?��?�� ?��?��
int     pop(t_stack **stack)
{
    t_stack *pop;
    int     data;
    
    if (!stack)
        exit(1);
    pop = *stack;
    //headNext�? head�? 바꿔주는 과정
    if ((*stack)->next)
    {
        (*stack)->next->prev = (*stack)->prev;
        *stack = (*stack)->next;
    }
    data = pop->data;
    free(pop);
    return (data);
}

//매개�??�� node : ?��?��?�� ?���? 집어?��?�� ?��?��
void    push(t_stack **stack, int data)
{
    t_stack *newNode;
    
    newNode = (t_stack *)malloc(sizeof(t_stack));
    newNode->data = data;
    // ??? ?��?��?�� 비어?��?�� 경우
    if (*stack == 0)
    {
        newNode->prev = newNode;
        *stack = newNode;
    }
    // ?��?��?�� head�? ?��?���? ?��?��?�� node�? 교체
    else
    {
        newNode->prev = (*stack)->prev;
        newNode->next = *stack;
        *stack = newNode;
    }
}

int    find_max(t_carrier *carrier, t_stack **stack, char c)
{
    t_stack     *curr;
    int         max;
    int         i;

    if (!stack)
        exit(1);
    curr = *stack;
    printf("ac_cnt in find_max: %d\n", carrier->ac_cnt);
    if (!carrier->a_remnant && !carrier->b_remnant)
        i =  carrier->ac_cnt;
    else
    {
        if (c == 'a')
            i = carrier->a_remnant->data;
        else
            i = carrier->b_remnant->data;
    }

    max = curr->data;
    while (i--)
    {
        if (max < curr->data)
            max = curr->data;
        curr = curr->next;
    }
    return (max); 
}

int    find_min(t_carrier *carrier, t_stack **stack, char c)
{
    t_stack     *curr;
    int         min;
    int         i;

    if (!stack)
        exit(1);
    curr = *stack;
    if (!carrier->a_remnant && !carrier->b_remnant)
        i =  carrier->ac_cnt;
    else 
    {
        if (c == 'a')
            i = carrier->a_remnant->data;
        else
            i = carrier->b_remnant->data;
    }
    min = curr->data;
    while (i--)
    {
        if (min > curr->data)
            min = curr->data;
        curr = curr->next;
    }
    return (min); 
}