/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mson <mson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:01:39 by mson              #+#    #+#             */
/*   Updated: 2021/06/08 20:12:34 by mson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_index;
	int		s2_index;
	int		s1_size;
	int		s2_size;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	s1_index = -1;
	s2_index = -1;
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	if (!(str = (char*)malloc(sizeof(char) * (s1_size + s2_size + 1))))
		return (NULL);
	while (++s1_index < s1_size)
		str[s1_index] = s1[s1_index];
	while (++s2_index < s2_size)
		str[s2_index + s1_size] = s2[s2_index];
	str[s2_index + s1_size] = '\0';
	return (str);
}
