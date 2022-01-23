#include "push_swap.h"


// ?? node ì¶”ê?? -> push ?•¨?ˆ˜?˜ ?¸? ???
void     fill_stack(t_carrier *carrier, t_stack **a, int size, char **argv)
{
    int data;
    char **array;
    int arr_index;
    int argv_index;

    argv_index = 0;
    if (!argv)
        return ;
    while (argv[argv_index])
    {
        arr_index = 0;
        array = ft_split(argv[argv_index], ' ');
        if (!array)
        {
            printf("array is null");
            error(carrier);
        }
        while (array[arr_index])
        {
            data = ft_atoi(array[arr_index], carrier);
            init_pushed_stack(carrier, a, data); 
            arr_index++;
        }
        argv_index++;
        free_arr(array);
    }
    is_overlapped(carrier, a);
    return ;
}

void    init_carrier(t_carrier *carrier)
{
    carrier->ac_cnt = 0;
    carrier->max = -2147483648;
    carrier->min = 2147483647;
    carrier->pivot = 0;
    carrier->a_cnt = 0;
    carrier->b_cnt = 0;    
    carrier->error = 0;
    carrier->arem_cnt = 0;
    carrier->brem_cnt = 0;
    carrier->pa_num = 0;
    carrier->pb_num = 0;
    carrier->a_remnant = 0;
    carrier->b_remnant = 0;
    carrier->rra_num = 0;
    carrier->rrb_num = 0;
    return ;
}

//ì±„ì›Œì§? a?Š¤?ƒ?„ ? •? ¬?•˜?Š” ë¡œì§?„ ?‹´??? ?•¨?ˆ˜
//void    push_swap(t_carrier *carrier, t_stack *a, t_stack *b)
//{
//}
// int		main(int argc, char **argv)
// {
//     t_carrier carrier;
//     t_stack *a;
//     t_stack *b;
//     a = 0;
//     b = 0;
//     if (argc < 2)
//         exit(0);
//     init_carrier(&carrier);
//     fill_stack(&a, argc - 1, &argv[1], &carrier);
//     push_swap(carrier, a, b);
// }