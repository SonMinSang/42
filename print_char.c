#include "ft_printf.h"

int print_char(int data, t_info *info)
{
    int ret;

    ret = 0;
    if (info->type == '%' && info->minus == 1)
        info->zero = 0;
    if (info->minus == 1)
        ret += ft_putchar(data);
    ret += put_width(info->width, 1, info->zero);
    if (info->minus == 0)
        ret += ft_putchar(data);
    return (ret);
}

int print_string(char *s, t_info *info)
{
}

int 
int print_num(unsigned long long num, t_info *info)
{
    char *buf;
    int buf_len;
    int ret;

    if (info->type == 'x' || info->type == 'X')
        print(info, 16);
    if ((info->type == 'd' || info->type == 'i')
        print_int(num, info);
    if (info->type == 'p')
        buf_len = put_pointer_prefix(&buf);
    ret = put_width_str(&buf, info);
    ret += put_minus2(buf_len, info, &buf);
    ft_putstr(buf);
    free(buf);
    return (ret);
}