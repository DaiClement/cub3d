/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:20:23 by cdai              #+#    #+#             */
/*   Updated: 2019/11/11 12:54:05 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dst_temp;
	char	*src_temp;

	if (!dst && !src)
		return (dst);
	dst_temp = (char *)dst;
	src_temp = (char *)src;
	i = len;
	if (dst > src && len)
	{
		while (--i > 0)
			dst_temp[i] = src_temp[i];
		dst_temp[i] = src_temp[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dst_temp[i] = src_temp[i];
			i++;
		}
	}
	return (dst);
}
