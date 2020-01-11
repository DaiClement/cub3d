/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:01:16 by cdai              #+#    #+#             */
/*   Updated: 2019/11/08 08:33:50 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	size_t	i;
	char	*result;

	i = 0;
	if (!s1 || !s2)
		return (0);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (!(result = malloc(sizeof(*result) * (s1len + s2len + 1))))
		return (0);
	while (i < s1len)
	{
		result[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2len)
	{
		result[s1len + i] = s2[i];
		i++;
	}
	result[s1len + s2len] = '\0';
	return (result);
}
