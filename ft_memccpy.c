/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mson <mson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:41:38 by mson              #+#    #+#             */
/*   Updated: 2021/05/29 21:34:28 by mson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int c, size_t num)
{
	unsigned char			*dst;
	const unsigned char		*src;
	size_t					index;

	dst = (unsigned char*)dest;
	src = (const unsigned char*)source;
	index = 0;
	while (index < num)
	{
		dst[index] = src[index];
		if (((unsigned char)c) == src[index])
			break ;
		index++;
	}
	if (index == num)
		return (0);
	else
		return (dest + index + 1);
}
