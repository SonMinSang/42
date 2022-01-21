/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mson <mson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:12:50 by mson              #+#    #+#             */
/*   Updated: 2022/01/20 11:12:53 by mson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

void	print_string(va_list ap, t_info *info)
{
	char	*data;

	data = va_arg(ap, char *);
	if (!data)
		data = "(null)";
	info->length = ft_strlen(data, info);
	if (!info->minus)
		print_space_char(info);
	print_zero_char(info);
	ft_putstr(data, info);
	if (info->minus)
		print_space_char(info);
}
