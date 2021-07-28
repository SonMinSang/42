/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mson <mson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 21:58:55 by mson              #+#    #+#             */
/*   Updated: 2021/07/28 23:22:46 by mson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	index;
	size_t	size;

	index = 0;
	size = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	while (index < size)
	{
		result[index] = s[index];
		index++;
	}
	result[size] = '\0';
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_index;
	int		s2_index;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_index = -1;
	s2_index = -1;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[++s1_index] != '\0')
		str[s1_index] = s1[s1_index];
	while (s2[++s2_index] != '\0')
		str[s2_index + s1_index] = s2[s2_index];
	str[s2_index + s1_index] = '\0';
	return (str);
}

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
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (start + index < size && index < len)
	{
		result[index] = s[start + index];
		index++;
	}
	result[len] = '\0';
	return (result);
}
