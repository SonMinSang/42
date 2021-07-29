/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mson <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:19:34 by mson              #+#    #+#             */
/*   Updated: 2021/05/26 21:36:50 by mson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t index;

	index = 0;
	while (index < num)
	{
		((unsigned char *)ptr)[index] = (unsigned char)value;
		index++;
	}
	return (ptr);
}
