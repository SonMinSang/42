#include "push_swap.h"

void ra(t_stack *a)
{
	t_stack *head;
	t_stack *headNext;
	t_stack *tail;

	if (!a)
		exit(1);
	if (!a->next)
		exit(0);

	head = a;

	headNext = head->next;
	tail = head->prev;
	head = tail->next;

	tail->next = head;
	head->next = headNext;
	headNext->prev = head;
	head->prev = 0;

	return;
}

void rb(t_stack *b)
{
	t_stack *head;
	t_stack *headNext;
	t_stack *tail;

	if (!b)
		exit(1);
	if (!b->next)
		exit(0);

	head = b;

	headNext = head->next;
	tail = head->prev;
	head = tail->next;

	tail->next = head;
	head->next = headNext;
	headNext->prev = head;
	head->prev = 0;

	b = headNext;

	return;
}

void rra(t_stack *a)
{
	t_stack *head;
	t_stack *prevTail;
	t_stack *tail;

	if (!a)
		exit(1);
	if (!a->next)
		exit(0);

	head = a;

	tail = head->prev;
	prevTail = tail->prev;
	head = tail->next;

	a = tail;

	tail->next = head;
	head->prev = 0;
	prevTail->next = tail;
	tail->prev = prevTail;

	return;
}

void rrb(t_stack *b)
{
	t_stack *head;
	t_stack *prevTail;
	t_stack *tail;

	if (!b)
		exit(1);
	if (!b->next)
		exit(0);

	head = b;

	tail = head->prev;
	prevTail = tail->prev;
	head = tail->next;

	b = tail;

	tail->next = head;
	head->prev = 0;
	prevTail->next = tail;
	tail->prev = prevTail;

	return;
}

void sa(t_stack *a)
{
	t_stack *head;
	t_stack *headNext;
	t_stack *tail;

	if (!a)
		exit(1);
	if (!a->next)
		exit(0);

	head = a;

	head->next = headNext;
	head->prev = tail;
	tail->next = head;

	head->next = headNext->next;
	tail->next = headNext;
	headNext->
}