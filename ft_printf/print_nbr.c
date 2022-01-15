#include "ft_printf.h"

int print_space_nbr(long long data, t_info *info)
{
	int		space;

	if (data < 0)
		info->space_len--;
	if (info->type == 'p')
		info->space_len -= 2;
	if (info->precision > info->length)
		info->space_len = info->width - info->precision;
	else
		info->space_len = info->width - info->length;
	space = 0;
	while (space < info->space_len)
	{	
		ft_putchar(' ');
		space++;
	}
	return (space);
}

int	print_zero_nbr(long long data, t_info *info)
{
	int		zero;

	if (info->zero && !info->dot && !info->precision)
	{
		info->zero_len = info->width - info->length;
		if (data < 0)
			info->zero_len--;
	}
	else
		info->zero_len = info->precision - info->length;
	zero = 0;
	while (zero < info->zero_len)
	{
		ft_putchar('0');
		zero++;
	}
	return (zero);
}

int nbr_len(long long data, int base, t_info *info)
{
	int len;

	len = 1;
	if (data < 0)
		data = -data;
	if (data == 0 && info->dot && !info->precision)
		return (0);
	while (data >= base)
	{
		data /= base;
		len++;
	}
	info->length = len;
	return (len);
}

int	print_nbr(va_list ap, t_info *info)
{
	long long	data;
    int			len;

	if (info->type == 'u')
		data = va_arg(ap, unsigned int);
	else
		data = va_arg(ap, int);
	len = nbr_len(data, 10, info);
	if (!info->minus)
		len += print_space_nbr(data, info);
	if (data < 0)
    {
		ft_putchar('-');
		len++;
	}
	len += print_zero_nbr(data, info);
	ft_putnbr(data, 10, info);
	if (info->minus)
		len += print_space_nbr(data, info);
	return (len);
}

int	print_Hex_nbr(va_list ap, t_info *info)
{
	long long	data;
    int			len;

	if (info->type == 'p')
		data = va_arg(ap, long long);
	else
		data = va_arg(ap, unsigned int);
	len = nbr_len(data, 16, info);
	if (!info->minus)
		len += print_space_nbr(data, info);
	if (data < 0)
	{
		ft_putchar('-');
		len++;
	}
	if (info->type == 'p')
	{
		ft_putstr("0x", info);
		len += 2;
	}
	len += print_zero_nbr(data, info);
	ft_putnbr(data, 16, info);
	if (info->minus)
		len += print_space_nbr(data, info);
	return (len);
}
