/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mson <mson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 19:24:51 by mson              #+#    #+#             */
/*   Updated: 2021/05/30 19:51:59 by mson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char		*result;
	size_t		index;
	size_t		find_index;

	result = (char *)big;
	index = 0;
	if (little[0] == 0 || big == little)
		return (result);
	while (result[index] && index < len)
	{
		find_index = 0;
		while (result[index + find_index] == little[find_index]
				&& index + find_index < len)
		{
			find_index++;
			if (!little[find_index])
				return (&(result[index]));
		}
		index++;
	}
	return (0);
}
