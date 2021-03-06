/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mson <mson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:01:42 by mson              #+#    #+#             */
/*   Updated: 2022/01/19 00:32:00 by mson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	init_info(t_info *info)
{
	info->dot = 0;
	info->minus = 0;
	info->zero = 0;
	info->width = 0;
	info->precision = 0;
	info->type = 0;
	info->length = 0;
	info->space_len = 0;
	info->zero_len = 0;
	info->space = 0;
	info->plus = 0;
	info->sharp = 0;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_info	*info;
	int		length;
	char	*str;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (-1);
	str = (char *)format;
	va_start(ap, format);
	init_info(info);
	info->size = 0;
	length = parsing(str, info, ap);
	free(info);
	va_end(ap);
	return (length);
}
