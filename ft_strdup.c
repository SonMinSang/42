/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mson <mson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 19:53:51 by mson              #+#    #+#             */
/*   Updated: 2021/05/29 20:05:32 by mson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	index;
	size_t	size;

	index = 0;
	size = ft_strlen(s);
	if (!(result = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (index < size)
	{
		result[index] = s[index];
		index++;
	}
	result[size] = '\0';
	return (result);
}
