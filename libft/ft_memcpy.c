/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mson <mson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:37:23 by mson              #+#    #+#             */
/*   Updated: 2021/05/29 21:28:44 by mson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t num)
{
	unsigned char			*dst;
	const unsigned char		*src;
	size_t					index;

	dst = (unsigned char*)dest;
	src = (const unsigned char*)source;
	index = 0;
	if (!dest && !source)
		return (NULL);
	while (index < num)
	{
		dst[index] = src[index];
		index++;
	}
	return (dest);
}
