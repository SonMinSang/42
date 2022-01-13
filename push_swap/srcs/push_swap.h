#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_stack
{
    int data;
    struct s_stack *next;
    struct s_stack *prev;
} t_stack;

typedef struct s_carrier
{
    int ac_cnt;
    int min;
    int max;
    int pivot;
    int a_cnt;
    int b_cnt;
    int error;
} t_carrier;

#endif