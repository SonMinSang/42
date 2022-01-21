#include "push_swap.h"

//?—?Ÿ¬ ì¶œë ¥ ?•¨?ˆ˜. ?—?Ÿ¬ ?‹œ carrier->error ë©¤ë²„ ê°? == 1
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

// A?Š¤?ƒ ?‚´ë¶??— ì¤‘ë³µ ?ˆ«?ž ?—¬ë¶?ë¥? ?™•?¸?•˜?Š” ?•¨?ˆ˜
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

// ??? ?Š¤?ƒ?— ?‘¸?‹œ?–ˆ?„?•Œ ? •ë³´ë?? ë°”ê¿”ì£¼ëŠ” ?•¨?ˆ˜ ?
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
    //ìµœë??ê°? ìµœì†Œê°? ?‹¤?‹œ ?• ?‹¹
    if (data > carrier->max)
        carrier->max = data;
    if (data < carrier->min)
        carrier->min = data;
    // string?˜•?ƒœë¡? ?“¤?–´?˜¬?•Œ ac_cnt == 1 ?´ê¸? ?•Œë¬¸ì— ac_cnt++;
    carrier->ac_cnt++;
    carrier->a_cnt++;
    carrier->arem_cnt++;
    //ë¹? ?Š¤?ƒ?´ ?“¤?–´?˜¤?Š” ê²½ìš°
    if (*stack == 0)
    {
        *stack = temp;
        (*stack)->prev = *stack;
        return ;
    }
    tail = (*stack)->prev;
    temp->next = 0;
    tail->next = temp;
    //?ƒˆë¡? ?“¤?–´?˜¨ ?…¸?“œë¥? ê¸°ì¡´ ?…¸?“œ?˜ ?‹¤?Œ ?…¸?“œë¡? ?—°ê²?
    temp->prev = tail;
    (*stack)->prev = temp;
}


//?Š¤?ƒ?—?„œ head?…¸?“œë¥? êº¼ë‚´ê³? ë°˜í™˜?•˜?Š” ?•¨?ˆ˜
int     pop(t_stack **stack)
{
    t_stack *pop;
    int     data;
    
    if (!stack)
        exit(1);
    pop = *stack;
    //headNextë¥? headë¡? ë°”ê¿”ì£¼ëŠ” ê³¼ì •
    if ((*stack)->next)
    {
        (*stack)->next->prev = (*stack)->prev;
        *stack = (*stack)->next;
    }
    data = pop->data;
    free(pop);
    return (data);
}

//ë§¤ê°œë³??ˆ˜ node : ?Š¤?ƒ?— ?ƒˆë¡? ì§‘ì–´?„£?„ ?…¸?“œ
void    push(t_stack **stack, int data)
{
    t_stack *newNode;
    
    newNode = (t_stack *)malloc(sizeof(t_stack));
    newNode->data = data;
    // ??? ?Š¤?ƒ?´ ë¹„ì–´?žˆ?„ ê²½ìš°
    if (*stack == 0)
    {
        newNode->prev = newNode;
        *stack = newNode;
    }
    // ?Š¤?ƒ?˜ headë¥? ?¸?žë¡? ?“¤?–´?˜¨ nodeë¡? êµì²´
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