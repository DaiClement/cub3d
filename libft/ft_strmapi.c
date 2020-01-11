/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:50:31 by cdai              #+#    #+#             */
/*   Updated: 2019/11/07 17:06:32 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*result;
	size_t	len;

	if (!s || !f)
		return (0);
	i = 0;
	len = ft_strlen(s);
	if (!(result = ft_calloc(len + 1, sizeof(*result))))
		return (0);
	while (i < len)
	{
		result[i] = (*f)(i, s[i]);
		i++;
	}
	return (result);
}
