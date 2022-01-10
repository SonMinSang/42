#include "ft_printf.h"

int print_space_nbr(long long data, t_info *info)
{
    int space;
    if (data < 0)
        info->space_len--;
    if (info->type == 'p')
        info->space_len -= 2;
    if (info->precision > info->length)
        info->space_len = info->width - info->precision;
    else
        info->space_len = info->width - info->length;
    if (info->zero && !info->dot && !info->precision)
        info->space_len -= info->width - info->length;
    space = info->space_len;
    while (space-- > 0)
        ft_putchar(' ');
    return (info->space_len);
}

int print_zero_nbr(long long data, t_info *info)
{
    int zero;

    if (info->zero && !info->dot && !info->precision)
    {
        info->zero_len = info->width - info->length;
        if (data < 0)
            info->zero_len--;
    }
    else
        info->zero_len = info->precision - info->length;
    zero = info->zero_len;
    while (zero-- > 0)
        ft_putchar('0');
    return (info->zero_len);
}

int print_nbr(va_list ap, t_info *info)
{
    int data;
    int len;

    if (info->type == '%')
        data = '%';
    else
        data = va_arg(ap, int);
    info->length = 1;
    len = 1;
    if (!info->minus)
        len += print_space_char(info);
    len += print_zero_char(info);
    ft_putchar(data);
    if (info->minus)
        len += print_space_char(info);
    return (len);
}