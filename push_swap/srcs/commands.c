#include "push_swap.h"

void pa(t_carrier *carrier, t_stack **a, t_stack **b)
{

	t_stack *b_top;
	t_stack *a_second;

	if (*b != 0)
	{
		b_top = *b;
		*b = b_top->next != 0 ? b_top->next : 0;
		a_second = *a;
		*a = b_top;
		b_top->next = a_second;
	}

	// int	new_to_a;

	// if(!carrier || !b)
	// 	exit(1);

	// new_to_a = pop(b);
	// push(a, new_to_a);
	// //init_push_a(carrier, b, new_to_b->data);
	// carrier->a_cnt++;
	// carrier->b_cnt--;
	// return ;
}

void pb(t_carrier *carrier, t_stack **a, t_stack **b)
{

	t_stack *a_top;
	t_stack *b_second;

	a_top = *a;
	*a = a_top->next != 0 ? a_top->next : 0;
	b_second = *b;
	*b = a_top;
	a_top->next = b_second;

	// int new_to_b;

	// if(!carrier || !a)
	// 	exit(1);

	// new_to_b = pop(a);
	// push(b, new_to_b);
	// //init_push_a(carrier, b, new_to_b->data);
	// carrier->b_cnt++;
	// carrier->a_cnt--;
	// return ;
}

void ra(t_stack **a)
{
	t_stack *head;
	t_stack *headNext;

	if (!a)
		exit(1);
	head = *a;
	if (head->next)
	{
		head->prev->next = head;
		headNext = head->next;
		*a = headNext;
		head->next = 0;
	}
	return;
}

void rb(t_stack **b)
{
	t_stack *head;
	t_stack *headNext;

	if (!b)
		exit(1);
	head = *b;
	if (head->next)
	{
		head->prev->next = head;
		headNext = head->next;
		*b = headNext;
		head->next = 0;
	}
	return;
}

void rra(t_stack **a)
{
	t_stack *head;
	t_stack *tail;

	if (!a)
		exit(1);
	head = *a;
	if (head->next)
	{
		tail = head->prev;
		tail->prev->next = 0;
		*a = tail;
		tail->next = head;
	}
	return;
}

void rrb(t_stack **b)
{
	t_stack *head;
	t_stack *tail;

	if (!b)
		exit(1);
	head = *b;
	if (head->next)
	{
		tail = head->prev;
		tail->prev->next = 0;
		*b = tail;
		tail->next = head;
	}
	return;
}

void sa(t_stack **a)
{
	t_stack *head;
	t_stack *headNextNext;
	t_stack *headNext;

	head = *a;
	if (head->next != 0)
	{
		headNext = head->next;
		headNextNext = headNext->next;
		*a = headNext;
		headNext->next = head;
		head->next = headNextNext;
	}
	return;
}

void sb(t_stack **b)
{
	t_stack *head;
	t_stack *headNextNext;
	t_stack *headNext;

	head = *b;
	if (head->next != 0)
	{
		headNext = head->next;
		headNextNext = headNext->next;
		*b = headNext;
		headNext->next = head;
		head->next = headNextNext;
	}
	return;
}