/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mson <mson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:10:32 by mson              #+#    #+#             */
/*   Updated: 2021/05/29 21:47:20 by mson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t num)
{
	unsigned char	*dst;
	unsigned char	*src;
	size_t			index;

	dst = (unsigned char*)dest;
	src = (unsigned char*)source;
	index = 0;
	if (dest == src || num == 0)
		return (dest);
	if (dst < src)
	{
		while (index < num)
		{
			dst[index] = src[index];
			index++;
		}
	}
	else
	{
		while (num-- > 0)
			dst[num] = src[num];
	}
	return (dest);
}
