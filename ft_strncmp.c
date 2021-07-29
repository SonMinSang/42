/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mson <mson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:45:26 by mson              #+#    #+#             */
/*   Updated: 2021/06/08 19:48:54 by mson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t count)
{
	size_t		index;

	index = 0;
	if (count == 0)
		return (0);
	while (s1[index] && s2[index] && s1[index] == s2[index] && index < count)
		index++;
	if (index == count)
		index--;
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}
