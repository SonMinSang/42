/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mson <mson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:52:12 by mson              #+#    #+#             */
/*   Updated: 2021/06/07 20:51:42 by mson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ft_space(char c)
{
	int			index;
	char		*space;

	space = "\n\t\v\f\r ";
	index = 0;
	while (space[index] != '\0')
	{
		if (c == space[index])
			return (1);
		index++;
	}
	return (0);
}

static int		ft_number(unsigned long long number, int minus)
{
	int	ret;

	if (number)
	{
		ret = (int)number;
		if (minus == 1)
			ret = (-1) * ret;
		return (ret);
	}
	return (0);
}

static int		ouflow(unsigned long long number, int minus)
{
	if (number > 9223372036854775807 && minus == 0)
		return (-1);
	if (number > 9223372036854775807 && minus == 1)
		return (0);
	return (1);
}

int				ft_atoi(const char *str)
{
	int						minus;
	unsigned long long		number;
	char					*ptr;

	minus = 0;
	number = 0;
	ptr = (char*)str;
	while (ft_space(*ptr))
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			minus++;
		ptr++;
	}
	while (*ptr >= '0' && *ptr <= '9')
	{
		number *= 10;
		number += *ptr - '0';
		ptr++;
		if (ouflow(number, minus) != 1)
			return (ouflow(number, minus));
	}
	return (ft_number(number, minus));
}
