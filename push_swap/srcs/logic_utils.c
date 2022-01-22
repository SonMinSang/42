#include "push_swap.h"

void	pivoting_a(t_carrier *carrier, t_stack **a, t_stack **b, int pivot)
{
	t_stack *head;
	int		count;
	t_stack *curr;


	count = carrier->arem_cnt;
	carrier->rra_num = 0;
	printf("[pivition_a] in\n");

	//{ ï¿½ëµ¾?Š?‰–?‚«ï¿½ë– ï¿½ì˜‰å«„ê³•êµ? åª›ìˆˆï¿½ï¿½ åª›ë?ªì“£ pb & arem_cnt-- & pb_num++}
	while (count--)
	{   
        head = *a;
	    curr = head;
		printf("curr->data : %d <= pivot : %d\n", curr->data, pivot);
		if (curr->data <= pivot)
		{
			pb(carrier, a, b);
			carrier->brem_cnt++;
			carrier->pa_num++;
		}
		//{ ï¿½ëµ¾?Š?‰–?‚«ï¿½ë– ï¿½ê²•ï¿½ë–ï§ï¿½ ra & rra_num++ (èª˜ëª„? ™ï¿½ì ¹ï¿½ë§‚ ï¿½ë‹½ï¿½ì˜„ï¿½ì“½ ï¿½ë–ï¿½ë–† rraæ¿¡ï¿½ ï¿½ì‚±ï¿½ì ®ä»¥ì„ë¹ï¿½ë¸?ï¿½ë•²æºï¿½)}
		else
		{
			ra(a);   
			carrier->rra_num++;
		}
	}
}

void	pivoting_b(t_carrier *carrier, t_stack **a, t_stack **b, int pivot)
{
	t_stack *head;

	printf("[pivition_b] in\n");

	while (carrier->b_cnt > 0)
	{
		head = *b;
		//printf("curr->data : %d <= pivot : %d\n", head->data, pivot);

		//{ ï¿½ëµ¾?Š?‰–?‚«ï¿½ë– ï¿½ì˜‰å«„ê³•êµ? åª›ìˆˆï¿½ï¿½ åª›ë?ªì“£ pa & brem_cnt-- & pa_num++}
		if (head->data <= pivot)
		{
			pa(carrier, a, b);
			carrier->pa_num--;
			carrier->a_cnt++;
		}
		//{ ï¿½ëµ¾?Š?‰–?‚«ï¿½ë– ï¿½ê²•ï¿½ë–ï§ï¿½ rb & rrb_num++ (èª˜ëª„? ™ï¿½ì ¹ï¿½ë§‚ ï¿½ë‹½ï¿½ì˜„ ï¿½ë–ï¿½ë–† rrbæ¿¡ï¿½ ï¿½ì‚±ï¿½ì ®ä»¥ì„ë¹ï¿½ë¸?ï¿½ë•²æºï¿½)}
		else
		{
			rb(b);
			carrier->rrb_num++;
		}
		carrier->b_cnt--;
	}	
}

void	attach_unsorted(t_carrier *carrier, t_stack **a, t_stack **b, char c)
{
    t_stack *unsorted;

	printf("[attach_unsorted] in\n");

    unsorted = (t_stack *)malloc(sizeof(t_stack));
	if (!unsorted)
    {
        free_stack(&(carrier->a_remnant));
        free_stack(&(carrier->b_remnant));
    }    
    if (c == 'a')
    {
        unsorted->data = carrier->rra_num;
        unsorted->next = carrier->a_remnant;
        carrier->a_remnant = unsorted;
        return ;
    }
    unsorted->data = carrier->rrb_num;
    unsorted->next = carrier->b_remnant;
    carrier->b_remnant = unsorted;
    
}

void	handle_one_two_a(t_carrier *carrier, t_stack **a, t_stack **b)
{
	t_stack *b_head;
	t_stack *head;

	//ï¿½ì” ï¿½ì £ b_remnant ï¿½ë¿°å¯ƒê³•?”ï¿½ë’ªï¿½ë“ƒ ï§ï¿½ ï¿½ìï¿½ë¿‰ ï¿½ì—³ï¿½ë’— ï¿½ëƒ¸ï¿½ì“£ freeï¿½ë¹ä»¥ê¾§êµ…ï¿½?—«
	//ï¿½ê¹‰ ï¿½ë£·ï¿½ì”¤ï¿½ê½£ æ´¹ëªƒì«?ï¿½ë¿‰ æ¹²ê³—??? b_head?‘œï¿? ï¿½ë–ï¿½ë¸˜ä»¥ï¿½
	b_head = carrier->b_remnant;
	if (b_head)
	{
		//brem_cntï¿½ë¿‰ ï¿½ì½ï¿½ì˜± 1 ï¿½ìƒŠï¿½ï¿½ï¿? 2ï¿½ì“½ ï¿½ì˜?‘œ?„ì»»ï¿½?‹”åª›ï¿½ ï¿½ë¸·ï¿½ë–¦ 
		carrier->brem_cnt = carrier->b_remnant->data;
		//b_remnantåª›ï¿½ åª›ï¿½?”±?‹ê¶ï¿½ë’— headNode?‘œï¿? ï¿½ëª¢è¸°ë‰?æ¿¡ï¿½ è«›ë¶½?“­äºŒì‡°?’— 
		carrier->b_remnant = carrier->b_remnant->next;
	}
	//ï¿½ë²ï¿½ì—«ï¿½ì“£ ï¿½ë–ï¿½ë¸³ (ï¿½ë¸³ï¿½ëª¢åª›ì’–ì­¨ç”±ï¿?)b_headï¿½ë’— free
	free(b_head);
	
	head = *a;
	//åª›ì’–?‹” 1ï¿½ì“½ å¯ƒìŒ?Š¦
	if (carrier->arem_cnt == 1)
	{
		ra(a);
		carrier->arem_cnt = 0;
		return ;
	}
	//åª›ì’–?‹” 2ï¿½ì“½ å¯ƒìŒ?Š¦
	if (head->data > head->next->data)
		sa(a);
	ra(a);
	ra(a);
	carrier->arem_cnt = 0;
}

void	handle_one_two_b(t_carrier *carrier, t_stack **a, t_stack **b)
{
	t_stack *a_head;
	t_stack *head;


	carrier->pa_num -= carrier->brem_cnt;
	carrier->arem_cnt = carrier->a_remnant->data;

	a_head = carrier->a_remnant;
	carrier->a_remnant = carrier->a_remnant->next;
	free(a_head); 

	head = *b;
	//bï¿½ì“½ unsorted ï¿½ê¹™ åª›ì’–?‹”åª›ï¿½ 1ï¿½ì”ªï¿½ë¸£
	if (carrier->brem_cnt == 1)
	{
		pa(carrier, a, b);
		ra(a);
		carrier->brem_cnt = 0;
		return ;
	}
	//bï¿½ì“½ unsorted ï¿½ê¹™ åª›ì’–?‹”åª›ï¿½ 2ï¿½ì”ªï¿½ë¸£
	if (head->data < head->next->data)
		sb(b);
	pa(carrier, a, b);
	pa(carrier, a, b);
	ra(a);
	ra(a);
	carrier->brem_cnt = 0;
}