/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mson <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:40:06 by mson              #+#    #+#             */
/*   Updated: 2022/01/16 20:40:08 by mson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print(va_list ap, t_info *info)
{
	if (info->type == 'c' || info->type == '%')
		print_char(ap, info);
	else if (info->type == 's')
		print_string(ap, info);
	else if (info->type == 'X' || info->type == 'x' || info->type == 'p')
		print_Hex_nbr(ap, info);
	else
		print_nbr(ap, info);
}
