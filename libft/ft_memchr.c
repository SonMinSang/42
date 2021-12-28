/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mson <mson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:03:00 by mson              #+#    #+#             */
/*   Updated: 2021/05/29 21:51:46 by mson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*dst;
	unsigned char		find;
	size_t				index;

	dst = (unsigned char*)s;
	find = (unsigned char)c;
	index = 0;
	while (index++ < n)
	{
		if (*dst == find)
			return (dst);
		dst++;
	}
	return (NULL);
}
