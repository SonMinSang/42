#include "ft_printf.h"

int print_string(va_list ap, t_info *info)
{
    char *data;
    int len;

    data = va_arg(ap, char *);
    if (!data)
        data = "(null)";
    info->length = ft_strlen(data, info);
    len = info->length;
    if (!info->minus)
        len += print_space_char(info);
    len += print_zero_char(info);
    ft_putstr(data, info);
    if (info->minus)
        len += print_space_char(info);
    return (len);
}