#include "ft_printf.h"

void	print_space_char(t_info *info)
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
	while (space++ < info->space_len)
		ft_putchar(' ', info);
}

void	print_zero_char(t_info *info)
{
	int zero;

	zero = 0;
	if (info->zero && !info->minus)
		info->zero_len = info->width - info->length;
	while (zero++ < info->zero_len)
		ft_putchar('0', info);
}

void	print_char(va_list ap, t_info *info)
{
	int		data;

	if (info->type == '%')
		data = '%';
	else
		data = va_arg(ap, int);
	info->length = 1;
	if (!info->minus)
		print_space_char(info);
	print_zero_char(info);
	ft_putchar(data, info);
	if (info->minus)
		print_space_char(info);
}
