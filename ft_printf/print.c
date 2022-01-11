#include "ft_printf.h"

int print(va_list ap, t_info *info)
{
    int len;

    len = 0;
    if (info->type == 'c' || info->type == '%')
        len = print_char(ap, info);
    else if (info->type == 's')
        len = print_string(ap, info);
    else if (info->type == 'X' || info->type == 'x' || info->type == 'p')
        len = print_Hex_nbr(ap, info);
    else
        len = print_nbr(ap, info);
    return (len);
}