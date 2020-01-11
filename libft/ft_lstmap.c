/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:45:11 by cdai              #+#    #+#             */
/*   Updated: 2019/11/08 17:07:31 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_cancel_map(t_list *result, void (*del)(void *))
{
	if (!result || !del)
		return (0);
	ft_lstclear(&result, del);
	return (0);
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*i;

	if (!lst)
		return (0);
	if (!(result = ft_lstnew((*f)(lst->content))))
		return (ft_cancel_map(result, del));
	i = result;
	lst = lst->next;
	while (lst)
	{
		if (!(i->next = ft_lstnew((*f)(lst->content))))
			return (ft_cancel_map(result, del));
		i = i->next;
		lst = lst->next;
	}
	return (result);
}
