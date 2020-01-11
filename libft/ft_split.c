/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:37:13 by cdai              #+#    #+#             */
/*   Updated: 2019/11/08 08:31:42 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_word(char const *s, char c)
{
	size_t	i;
	size_t	len;
	size_t	is_word;

	i = 0;
	len = 0;
	is_word = 0;
	while (s[i])
	{
		if (!is_word && s[i] != c)
		{
			is_word = 1;
			len++;
		}
		else if (is_word && s[i] == c)
			is_word = 0;
		i++;
	}
	return (len + 1);
}

static char		*ft_strdup_mix(char const *s, char c)
{
	size_t	i;
	char	*result;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (!(result = ft_calloc(sizeof(*result), i + 1)))
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
	{
		result[i] = s[i];
		i++;
	}
	return (result);
}

static char		**ft_free_split(char **s, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (0);
}

char			**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	is_word;
	char	**result;

	i = -1;
	j = -1;
	is_word = 0;
	if (!s)
		return (0);
	if (!(result = ft_calloc(ft_count_word(s, c), sizeof(*result))))
		return (0);
	while (s[++i])
	{
		if (!is_word && s[i] != c)
		{
			is_word = 1;
			if (!(result[++j] = ft_strdup_mix(s + i, c)))
				return (ft_free_split(result, j));
		}
		else if (is_word && s[i] == c)
			is_word = 0;
	}
	return (result);
}
