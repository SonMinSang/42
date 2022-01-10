#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

typedef struct s_info
{
    int minus;
    int dot;
    int zero;
    int width;
    int precision;
    char type;
    int sign;
    int length;
    int space_len;
    int zero_len;
} t_info;

int print_char(va_list ap, t_info *info);
int print_space_char(t_info *info);
int print_zero_char(t_info *info);
int print_string(va_list ap, t_info *info);
int print_nbr(va_list ap, t_info *info);
int print_space_nbr(long long data, t_info *info);
int print_zero_nbr(long long data, t_info *info);
#endif