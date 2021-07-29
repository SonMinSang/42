/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mson <mson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:26:21 by mson              #+#    #+#             */
/*   Updated: 2021/05/29 22:33:33 by mson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	find;
	unsigned char	*ptr;
	int				size;

	find = (unsigned char)c;
	ptr = (unsigned char *)s;
	size = 0;
	while (*ptr)
	{
		size++;
		ptr++;
	}
	while (size > 0)
	{
		if (*ptr == find)
			return ((char *)ptr);
		ptr--;
		size--;
	}
	if (*ptr == find)
		return ((char *)ptr);
	return (NULL);
}
