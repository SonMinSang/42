#include "ft_printf.h"

void init_info(t_info *info)
{
    info->minus = 0;
    info->zero = 0;
    info->width = 0;
    info->precision = 0;
    info->type = 0;
    info->sign = 0;
    info->length = 0;
    info->space_len = 0;
    info->zero_len = 0;
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

int parse_flag(char *str, int i, t_info *info)
{
    while (str[i] == '-' || str[i] == '0')
    {
        if (str[i] == '-')
            info->minus = 1;
        if (str[i] == '0')
            info->zero = 1;
        i++;
    }
    if (info->minus && info->zero)
        info->zero = 0;
    return (i);
}

int parse_width(char *str, int i, t_info *info)
{
    while (ft_isdigit(str[i]))
    {
        info->width = (info->width * 10) + (str[i] - '0');
        i++;
    }
    return (i);
}

int parse_prec(char *str, int i, t_info *info)
{
    if (str[i] == '.')
    {
        info->dot = 1;
        i++;
    }
    while (ft_isdigit(str[i]))
    {
        info->precision = (info->precision * 10) + str[i] - '0';
        i++;
    }
}

int parse_spec(char *str, int i, t_info *info)
{
    char *type;

    type = "cspdiuxX%";
    while (*type)
    {
        if (*type == str[i])
        {
            info->type = str[i];
            return (++i);
        }
        *type++;
    }
    return (-1);
}

void parsing(char *str, t_info *info, va_list ap)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '%')
        {
            init_info(info);
            i++;
            i = parse_flag(str, i, info);
            i = parse_width(str, i, info);
            i = parse_prec(str, i, info);
            i = parse_spec(str, i, info);
            print(ap, info);
        }
        else
        {
            ft_putchar(str[i], info);
            i++;
        }
    }
}