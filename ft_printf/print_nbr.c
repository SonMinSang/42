/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mson <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:39:11 by mson              #+#    #+#             */
/*   Updated: 2022/01/16 23:05:26 by mson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_space_nbr(long long data, t_info *info)
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
	if (info->zero && !info->dot && !info->precision)
		info->space_len -= info->width - info->length;
	space = 0;
	while (space++ < info->space_len)
		ft_putchar(' ', info);
}

void	print_zero_nbr(long long data, t_info *info)
{
	int		zero;

	if (info->zero && !info->dot && !info->precision)
		info->zero_len = info->width - info->length;
	else
	{
		info->zero_len = info->precision - info->length;
		if (data < 0)
			info->zero_len++;
	}
	zero = 0;
	while (zero++ < info->zero_len)
		ft_putchar('0', info);
}

int	nbr_len(long long data, int base, t_info *info)
{
	int		len;

	len = 1;
	if (data < 0)
	{
		data = -data;
		len++;
	}
	if (data == 0 && info->dot && !info->precision)
		return (0);
	while (data >= base)
	{
		data /= base;
		len++;
	}
	return (len);
}

void	print_nbr(va_list ap, t_info *info)
{
	long long	data;

	if (info->type == 'u')
		data = va_arg(ap, unsigned int);
	else
		data = va_arg(ap, int);
	info->length = nbr_len(data, 10, info);
	if (!info->minus)
		print_space_nbr(data, info);
	if (data < 0)
		ft_putchar('-', info);
	print_zero_nbr(data, info);
	ft_putnbr(data, 10, info);
	if (info->minus)
		print_space_nbr(data, info);
}

void	print_Hex_nbr(va_list ap, t_info *info)
{
	long long	data;

	data = va_arg(ap, unsigned int);
	info->length = nbr_len(data, 16, info);
	if (!info->minus)
		print_space_nbr(data, info);
	if (data < 0)
		ft_putchar('-', info);
	print_zero_nbr(data, info);
	ft_putnbr(data, 16, info);
	if (info->minus)
		print_space_nbr(data, info);
}
