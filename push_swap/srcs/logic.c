#include "push_swap.h"

int		find_pivot(t_stack **stack, int count)
{
	int max;
	int min;
	t_stack *curr;

	curr = *stack;
	max = curr->data;
	min = curr->data;
	while (count--)
	{
		if (max < curr->data)
			max = curr->data;
		else if (min > curr->data)
			min = curr->data;
		curr = curr->next;
	}
	return ((max + min) / 2);
}


void	a_to_b(t_carrier *carrier, t_stack **a, t_stack **b)
{
	int pivot;
	t_stack *head;

    debug(carrier, a, b);
    
	if (carrier->arem_cnt < 3)
	{
		handle_one_two_a(carrier, a, b);
		return ;
	}
	//a_to_b째징 ?���?���? 쩍횄?��?��쨉횋 째챈쩔챙
    if (carrier->a_cnt == carrier->ac_cnt)
	    pivot = (carrier->max + carrier->min) / 2;
    else 
        pivot = find_pivot(a, carrier->arem_cnt);
	pivoting_a(carrier, a, b, pivot);
    printf("debug after pivoting_a\n>>>\n");
    
    attach_unsorted(carrier, a, b, 'a');
    
    head = *a;
    while (carrier->rra_num > 0 &&
        (carrier->a_remnant->next || head->data == carrier->min))
    {
        rra(a);
        carrier->rra_num--;
    }
    carrier->rra_num = 0;
}

void    b_to_a(t_carrier *carrier, t_stack **a, t_stack **b)
{
    int pivot;

    debug(carrier, a, b);
    print_stack(carrier, *b);
    if (carrier->b_cnt < 3)
    {
        handle_one_two_b(carrier, a, b);
        return ;
    }
    pivot = find_pivot(b, carrier->brem_cnt);
    pivoting_b(carrier, a, b, pivot);
    attach_unsorted(carrier, a, b, 'b');
    printf("a\n");
    while (carrier->b_remnant->next && carrier->rrb_num > 0)
    {
        rrb(b);
        carrier->rrb_num--;
    }
    carrier->rrb_num = 0;
}