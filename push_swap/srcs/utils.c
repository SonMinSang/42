#include "push_swap.h"

//??¬ μΆλ ₯ ?¨?. ??¬ ? carrier->error λ©€λ² κ°? == 1
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

// A?€? ?΄λΆ?? μ€λ³΅ ?«? ?¬λΆ?λ₯? ??Έ?? ?¨?
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

// ??? ?€?? ?Έ???? ? λ³΄λ?? λ°κΏμ£Όλ ?¨? ?
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
    //μ΅λ??κ°? μ΅μκ°? ?€? ? ?Ή
    if (data > carrier->max)
        carrier->max = data;
    if (data < carrier->min)
        carrier->min = data;
    // string??λ‘? ?€?΄?¬? ac_cnt == 1 ?΄κΈ? ?λ¬Έμ ac_cnt++;
    carrier->ac_cnt++;
    carrier->a_cnt++;
    carrier->arem_cnt++;
    //λΉ? ?€??΄ ?€?΄?€? κ²½μ°
    if (*stack == 0)
    {
        *stack = temp;
        (*stack)->prev = *stack;
        return ;
    }
    tail = (*stack)->prev;
    temp->next = 0;
    tail->next = temp;
    //?λ‘? ?€?΄?¨ ?Έ?λ₯? κΈ°μ‘΄ ?Έ?? ?€? ?Έ?λ‘? ?°κ²?
    temp->prev = tail;
    (*stack)->prev = temp;
}


//?€??? head?Έ?λ₯? κΊΌλ΄κ³? λ°ν?? ?¨?
int     pop(t_stack **stack)
{
    t_stack *pop;
    int     data;
    
    if (!stack)
        exit(1);
    pop = *stack;
    //headNextλ₯? headλ‘? λ°κΏμ£Όλ κ³Όμ 
    if ((*stack)->next)
    {
        (*stack)->next->prev = (*stack)->prev;
        *stack = (*stack)->next;
    }
    data = pop->data;
    free(pop);
    return (data);
}

//λ§€κ°λ³?? node : ?€?? ?λ‘? μ§μ΄?£? ?Έ?
void    push(t_stack **stack, int data)
{
    t_stack *newNode;
    
    newNode = (t_stack *)malloc(sizeof(t_stack));
    newNode->data = data;
    // ??? ?€??΄ λΉμ΄?? κ²½μ°
    if (*stack == 0)
    {
        newNode->prev = newNode;
        *stack = newNode;
    }
    // ?€?? headλ₯? ?Έ?λ‘? ?€?΄?¨ nodeλ‘? κ΅μ²΄
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