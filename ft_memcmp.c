/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mson <mson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:35:30 by mson              #+#    #+#             */
/*   Updated: 2021/06/08 19:50:20 by mson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const unsigned char		*str;
	const unsigned char		*cmp;
	size_t					index;

	str = (const unsigned char*)ptr1;
	cmp = (const unsigned char*)ptr2;
	index = 0;
	while (index < num)
	{
		if (str[index] != cmp[index])
			return (str[index] - cmp[index]);
		index++;
	}
	return (0);
}
