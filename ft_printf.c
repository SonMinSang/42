/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mson <mson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:01:42 by mson              #+#    #+#             */
/*   Updated: 2021/06/21 19:04:55 by mson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int find_type(char *format,int index, t_list *option)
{
	while (format[index])
	{
		if (format[index] )
	}	
}

void	init_option(t_list *option)
{
	option->flags = 0;
	option->precision = 0;
	option->type = 0;
	option->width = 0;
}

int		ft_printf(const char *format, ...)
{
    va_list 	ap;
    int     	index;
	t_list		option;

    index = 0;
	while(format[index])
	{
		va_start(ap, format);
		if (format[index] == '%')
		{
			parse(format, ++index, &option))
			if (find_type(format[index], &option))
                print();0
		}
		else
            write(1, &format[index], 1)
		index++;
	}
    va_end(ap);
    return ();
}