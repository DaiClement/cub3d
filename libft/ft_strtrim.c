/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:01:06 by cdai              #+#    #+#             */
/*   Updated: 2019/11/11 12:41:08 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_charset(char c, char const *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*result;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = (int)ft_strlen(s1);
	while (s1[start] && ft_is_charset(s1[start], set))
		start++;
	if (start == end)
		return (result = ft_substr(s1, 0, 0));
	if (end > 0)
		end--;
	if (end == -1)
		end = 0;
	while (end > 0 && ft_is_charset(s1[end], set))
		end--;
	if (start >= end)
		result = ft_substr(s1, end, start - end + 1);
	else
		result = ft_substr(s1, start, -start + end + 1);
	return (result);
}
