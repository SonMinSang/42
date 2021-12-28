#include "ft_printf.h"

void init_info(t_info *info)
{
    info->minus = 0;
    info->zero = 0;
    info->width = 0;
    info->precision = -1;
    info->type = 0;
}

int check_print(va_list ap, t_info *info, char type)
{
    int length;

    length = 0;
    if (type == 'c')
        length = print_char(va_arg(ap, int), info);
    else if (type == '%')
        length = print_char('%', info);
    else if (type == 's')
        length = print_string(va_arg(ap, char *), info);
    else if (type == 'd' || type == 'i')
        length = print_nbr(va_arg(ap, int), info);
    else if (type == 'x' || type == 'X' || type == 'u')
        length = print_nbr(va_arg(ap, unsigned int), info);
    else if (type == 'p')
        length = print_nbr(va_arg(ap, unsigned long long), info);
    return (length);
}

int check_type(char c)
{
    char *type;

    type = "cspdiuxX%";
    while (*type)
    {
        if (*type == c)
            return (1);
        *type++;
    }
    return (0);
}

int set_info(va_list ap, const char *format, int index, t_info *info)
{
    init_info(info);
    while (format[index] != '\0' && !check_type(format[index]))
    {
        if (format[index] == '0' && info->width == 0 && info->precision == -1)
            info->zero = 1;
        else if (format[index] == '-')
            info->minus = 1;
        else if (format[index] == '.')
            info->precision = 0;
        else if (ft_isdigit(format[index]))
        {
            if (info->precision == -1)
                info->width = info->width * 10 + format[index] - '0';
            else
                info->precision = info->precision * 10 + format[index] - '0';
        }
        index++;
    }
    index++;
    info->type = format[index];
    if ((info->minus == 1 || info->precision > -1) && info->type != '%')
        info->zero = 0;
    return (index);
}

int parsing(va_list ap, const char *format, int *length)
{
    int index;
    int length;
    t_info *info;

    index = 0;
    length = 0;
    info = malloc(sizeof(t_info) * 1);
    if (!info)
        return (-1);
    while (format[index])
    {
        while (format[index] != '%' && format[index] != '\0')
            length += ft_putchar(format[index++]);
        if (format[index] == '%')
        {
            index += set_info(ap, format, ++index, info);
            length += check_print(ap, info, info->type);
        }
    }
    free(info);
    return (length);
}