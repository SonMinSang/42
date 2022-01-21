/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mson <mson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:11:29 by mson              #+#    #+#             */
/*   Updated: 2022/01/20 11:11:32 by mson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

void	print(va_list ap, t_info *info)
{
	if (info->type == 'c' || info->type == '%')
		print_char(ap, info);
	else if (info->type == 's')
		print_string(ap, info);
	else if (info->type == 'X' || info->type == 'x')
		print_Hex_nbr(ap, info);
	else if (info->type == 'p')
		print_Hex_ptr(ap, info);
	else
		print_nbr(ap, info);
}
