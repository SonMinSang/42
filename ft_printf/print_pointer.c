/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mson <mson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:59:48 by mson              #+#    #+#             */
/*   Updated: 2022/01/18 16:59:51 by mson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(unsigned long long data,
		unsigned long long base, t_info *info)
{
	char	*base_num;

	base_num = "0123456789abcdef";
	if (data == 0 && info->dot && !info->precision)
		return ;
	if (data >= base)
		ft_putnbr((data / base), base, info);
	ft_putchar(base_num[data % base], info);
}

int	ptr_len(unsigned long long data, unsigned long long base, t_info *info)
{
	int		len;

	len = 3;
	if (data == 0 && info->dot && !info->precision)
		return (0);
	while (data >= base)
	{
		data /= base;
		len++;
	}
	return (len);
}

void	print_Hex_ptr(va_list ap, t_info *info)
{
	unsigned long long	data;

	data = va_arg(ap, unsigned long long);
	info->length = ptr_len(data, 16, info);
	if (!info->minus)
		print_space_nbr(data, info);
	ft_putstr("0x", info);
	print_zero_nbr(data, info);
	ft_putptr(data, 16, info);
	if (info->minus)
		print_space_nbr(data, info);
}
