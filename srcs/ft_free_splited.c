/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_splited.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 11:54:31 by cdai              #+#    #+#             */
/*   Updated: 2020/01/13 09:36:56 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_splited(char **splited_data, char *line)
{
	int	i;

	i = 0;
	if (splited_data)
	{
		while (splited_data[i])
		{
			free(splited_data[i]);
			splited_data[i] = 0;
			i++;
		}
		free(splited_data);
	}
	if (line)
		free(line);
	splited_data = 0;
	line = 0;
}
