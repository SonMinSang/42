/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mson <mson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:21:15 by mson              #+#    #+#             */
/*   Updated: 2021/05/31 19:19:55 by mson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_i;
	size_t	dest_i;

	src_i = 0;
	dest_i = 0;
	while (dst[dest_i] && dest_i < size)
		dest_i++;
	while (src[src_i] && src_i + dest_i + 1 < size)
	{
		dst[dest_i + src_i] = src[src_i];
		src_i++;
	}
	if (dest_i < size)
		dst[dest_i + src_i] = '\0';
	return (ft_strlen(src) + dest_i);
}
