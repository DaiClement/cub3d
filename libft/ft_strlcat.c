/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:36:19 by cdai              #+#    #+#             */
/*   Updated: 2019/11/11 10:55:27 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	dstlen = dst ? ft_strlen(dst) : 0;
	srclen = ft_strlen(src);
	i = 0;
	if (dstsize < dstlen)
		return (dstsize + srclen);
	if (dstsize)
	{
		while (dstlen + i < (dstsize - 1) && src[i])
		{
			dst[dstlen + i] = src[i];
			i++;
		}
		dst[dstlen + i] = '\0';
	}
	return (dstlen + srclen);
}
