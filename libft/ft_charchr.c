/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 17:24:28 by cdai              #+#    #+#             */
/*   Updated: 2020/01/19 17:27:05 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_charchr(char *haystack, char needle)
{
	int	i;

	i = 0;
	while (haystack[i])
	{
		if (haystack[i]  == needle)
			return (1);
		i++;
	}
	return (0);
}
