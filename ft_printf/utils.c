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
    if (info->type == 's' && info->dot && !info->precision)
        return;
    if (info->type == 's' && info->precision)
    {
        while (str[index] && index < info->precision)
        {
            ft_putchar(str[index]);
            index++;
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

void ft_putnbr(long long data, int base, t_info *info)
{
    char *base_num;

    if (data < 0)
        data = -data;
    if (base == 10)
        base_num = "0123456789";
    else if (base == 16 && info->type == 'X')
        base_num = "0123456789ABCDEF";
    else
        base_num = "0123456789abcdef";
    if (data == 0 && info->dot && !info->precision) // printf("%5.0d",0);
        return;
    if (data >= base)
        ft_putnbr((data / base), base, info);
    ft_putchar(base_num[data % base]);
}

int ft_strlen(char *str, t_info *info)
{
    int size;

    size = 0;
    if (!str)
        return (0);
    if (info->dot && !info->precision) // printf("%.0s","Hello World");
        return (0);
    while (str[size])
        size++;
    return (size);
}

int ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}