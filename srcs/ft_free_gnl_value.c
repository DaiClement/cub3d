/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_gnl_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:50:46 by cdai              #+#    #+#             */
/*   Updated: 2020/02/18 11:52:08 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_gnl_value(char **line, char **splited_data)
{
	int	i;

	i = 0;
	if (line)
	{
		free(*line);
		*line = NULL;
	}
	if (splited_data)
	{
		while (splited_data[i])
		{
			free(splited_data[i]);
			i++;
		}
		free(splited_data);
		splited_data = NULL;
	}
}
