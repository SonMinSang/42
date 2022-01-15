#include "ft_printf.h"

int	print_space_char(t_info *info)
{
	int		space;

	if (info->zero && !info->minus && !info->dot && !info->precision)
		return (0);
	if (info->type == '%' && info->zero && !info->minus && info->width && info->dot)
		return (0);
	if (info->precision && info->precision < info->length)
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

int	print_zero_char(t_info *info)
{
	int		zero;

	if (info->zero && !info->minus)
		info->zero_len = info->width - info->length;
	zero = 0;
	while (zero < info->zero_len)
	{	
		ft_putchar('0');
		zero++;
	}
	return (zero);
}

int	print_char(va_list ap, t_info *info)
{
	int		data;
	int		len;

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
