/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mson <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:40:32 by mson              #+#    #+#             */
/*   Updated: 2022/01/16 20:40:34 by mson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
