/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:23:03 by cdai              #+#    #+#             */
/*   Updated: 2019/11/08 09:01:53 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst_temp;
	unsigned char	*src_temp;

	i = 0;
	dst_temp = (unsigned char *)dst;
	src_temp = (unsigned char *)src;
	while (i < n && src_temp[i] != (unsigned char)c)
	{
		dst_temp[i] = src_temp[i];
		i++;
	}
	if (i == n)
		return (0);
	dst_temp[i] = src_temp[i];
	return (dst + i + 1);
}
