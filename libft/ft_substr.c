/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:29:03 by cdai              #+#    #+#             */
/*   Updated: 2019/11/11 10:01:53 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	i;
	char	*result;

	i = 0;
	result = NULL;
	if (!s)
		return (0);
	slen = ft_strlen(s);
	result = malloc(sizeof(*result) * (len + 1));
	if (!result)
		return (0);
	while (s[start + i] && i < len && (start + i) < slen)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
