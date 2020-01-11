/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:13:56 by cdai              #+#    #+#             */
/*   Updated: 2019/11/05 08:21:10 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	size_t			i;
	const size_t	len = ft_strlen(s1);
	char			*result;

	i = 0;
	result = malloc(sizeof(*result) * (len + 1));
	if (!result)
		return (0);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
