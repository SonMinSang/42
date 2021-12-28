/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mson <mson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 21:34:06 by mson              #+#    #+#             */
/*   Updated: 2021/05/31 21:34:08 by mson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*temp;

	if (!lst || !f)
		return (NULL);
	if (!(result = ft_lstnew((*f)(lst->content))))
		return (NULL);
	temp = result;
	lst = lst->next;
	while (lst)
	{
		temp->next = ft_lstnew((*f)(lst->content));
		if (!temp->next)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		temp = temp->next;
		lst = lst->next;
	}
	return (result);
}
