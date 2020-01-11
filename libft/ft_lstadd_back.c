/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:52:11 by cdai              #+#    #+#             */
/*   Updated: 2019/11/15 16:05:04 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	**temp;

	if (!alst || !new)
		return ;
	else if (!(*alst))
	{
		*alst = new;
		return ;
	}
	temp = alst;
	while ((*temp)->next)
		*temp = (*temp)->next;
	(*temp)->next = new;
}
