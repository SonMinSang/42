#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

typedef struct s_info
{
    int minus;
    int zero;
    int width;
    int precision;
    char type;
    int sign;
} t_info;

int print_char(int c, t_info *info);
int print_string(char *s, t_info *info);
int print_nbr(long long int num, t_info *info);

#endif