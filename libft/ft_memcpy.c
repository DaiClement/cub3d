/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:28:43 by cdai              #+#    #+#             */
/*   Updated: 2019/11/08 08:54:17 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst_temp;
	unsigned char	*src_temp;

	if (!dst && !src)
		return (0);
	i = 0;
	dst_temp = (unsigned char *)dst;
	src_temp = (unsigned char *)src;
	while (i < n)
	{
		dst_temp[i] = src_temp[i];
		i++;
	}
	return (dst);
}
