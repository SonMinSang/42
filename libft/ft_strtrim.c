/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mson <mson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:53:38 by mson              #+#    #+#             */
/*   Updated: 2021/06/02 20:19:19 by mson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check(const char *str, char c)
{
	int			index;

	index = 0;
	while (str[index])
	{
		if (str[index] == c)
			return (1);
		index++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	size_t		size;
	size_t		index;
	size_t		input;

	if (!s1 || !set)
		return (NULL);
	size = ft_strlen(s1);
	index = 0;
	input = 0;
	while (check(set, s1[index]))
		index++;
	if (index == ft_strlen(s1))
		return (ft_strdup(""));
	while (check(set, s1[size - 1]))
		size--;
	if (!(str = (char*)malloc(sizeof(char) * (size - index + 1))))
		return (NULL);
	while (index < size)
		str[input++] = s1[index++];
	str[input] = '\0';
	return (str);
}
