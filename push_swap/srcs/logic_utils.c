#include "push_swap.h"

void	pivoting_a(t_carrier *carrier, t_stack **a, t_stack **b, int pivot)
{
	t_stack *head;
	int		count;
	t_stack *curr;


	count = carrier->arem_cnt;
	carrier->rra_num = 0;
	printf("[pivition_a] in\n");

	//{ �뵾?��?��?���떎 �옉嫄곕�? 媛숈�� 媛�?�쓣 pb & arem_cnt-- & pb_num++}
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
		//{ �뵾?��?��?���떎 �겕�떎硫� ra & rra_num++ (誘몄?���젹�맂 �닽�옄�쓽 �떎�떆 rra濡� �삱�젮以섏빞��?�땲源�)}
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

		//{ �뵾?��?��?���떎 �옉嫄곕�? 媛숈�� 媛�?�쓣 pa & brem_cnt-- & pa_num++}
		if (head->data <= pivot)
		{
			pa(carrier, a, b);
			carrier->pa_num--;
			carrier->a_cnt++;
		}
		//{ �뵾?��?��?���떎 �겕�떎硫� rb & rrb_num++ (誘몄?���젹�맂 �닽�옄 �떎�떆 rrb濡� �삱�젮以섏빞��?�땲源�)}
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

	//�씠�젣 b_remnant �뿰寃곕?���뒪�듃 留� �쐞�뿉 �엳�뒗 �냸�쓣 free�빐以꾧굅�?��
	//�깉 �룷�씤�꽣 洹몃�?�뿉 湲곗??? b_head?���? �떞�븘以�
	b_head = carrier->b_remnant;
	if (b_head)
	{
		//brem_cnt�뿉 �쁽�옱 1 �샊���? 2�쓽 �옍?��?��컻�?��媛� �븷�떦 
		carrier->brem_cnt = carrier->b_remnant->data;
		//b_remnant媛� 媛�?��?�궎�뒗 headNode?���? �몢踰덉?��濡� 諛붽?��二쇰?�� 
		carrier->b_remnant = carrier->b_remnant->next;
	}
	//�벐�엫�쓣 �떎�븳 (�븳�몢媛쒖쭨由�?)b_head�뒗 free
	free(b_head);
	
	head = *a;
	//媛쒖?�� 1�쓽 寃쎌?��
	if (carrier->arem_cnt == 1)
	{
		ra(a);
		carrier->arem_cnt = 0;
		return ;
	}
	//媛쒖?�� 2�쓽 寃쎌?��
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
	//b�쓽 unsorted �깙 媛쒖?��媛� 1�씪�븣
	if (carrier->brem_cnt == 1)
	{
		pa(carrier, a, b);
		ra(a);
		carrier->brem_cnt = 0;
		return ;
	}
	//b�쓽 unsorted �깙 媛쒖?��媛� 2�씪�븣
	if (head->data < head->next->data)
		sb(b);
	pa(carrier, a, b);
	pa(carrier, a, b);
	ra(a);
	ra(a);
	carrier->brem_cnt = 0;
}