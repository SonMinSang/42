/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mson <mson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:06:37 by mson              #+#    #+#             */
/*   Updated: 2021/06/07 20:46:58 by mson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char	find;

	find = (unsigned char)c;
	while (*str)
	{
		if (*str == find)
			return ((char *)str);
		str++;
	}
	if (*str == find)
		return ((char *)str);
	return (NULL);
}
