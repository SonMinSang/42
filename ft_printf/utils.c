#include "ft_printf.h"

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *str, t_info *info)
{
    int index;

    index = 0;
    if (!str)
        return;
    if (info->type == 's')
    {
        if (info->dot && !info->precision)
            return;
        if (info->precision)
        {
            while (str[index] && index < info->precision)
            {
                ft_putchar(str[index]);
                index++;
            }
        }
    }
    else
    {
        while (str[index])
        {
            ft_putchar(str[index]);
            index++;
        }
    }
}

int ft_strlen(char *str, t_info *info)
{
    int size;

    size = 0;
    if (!str)
        return (0);
    if (info->dot && !info->precision)
        return (0);
    while (str[size])
        size++;
    return (size);
}

int isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}