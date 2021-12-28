/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mson <mson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 20:23:22 by mson              #+#    #+#             */
/*   Updated: 2021/05/31 19:56:28 by mson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

static int		ft_size(int n, int *sign)
{
	int		size;

	size = 0;
	if (n == 0)
		size++;
	if (n < 0)
	{
		(*sign)++;
		size++;
		n = ft_abs(n);
	}
	while (n)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	int		sign;
	int		size;
	char	*result;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	sign = 0;
	size = ft_size(n, &sign);
	if (!(result = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (sign == 1)
		result[0] = '-';
	result[size] = '\0';
	while (ft_abs(n) && --size >= sign)
	{
		result[size] = ft_abs(n) % 10 + '0';
		n = ft_abs(n) / 10;
	}
	return (result);
}
