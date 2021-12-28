/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mson <mson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:54:46 by mson              #+#    #+#             */
/*   Updated: 2021/06/02 20:23:13 by mson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	index;
	size_t	size;

	if (!s)
		return (NULL);
	index = 0;
	size = ft_strlen(s);
	if (start >= (unsigned int)size)
		return (ft_strdup(""));
	if ((size_t)start + len > size)
		len = size - start;
	if (!(result = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (start + index < size && index < len)
	{
		result[index] = s[start + index];
		index++;
	}
	result[len] = '\0';
	return (result);
}
