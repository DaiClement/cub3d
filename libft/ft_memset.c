/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:58:43 by cdai              #+#    #+#             */
/*   Updated: 2019/11/11 09:43:47 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*tab;

	i = 0;
	tab = (unsigned char *)b;
	while (i < len)
	{
		tab[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
