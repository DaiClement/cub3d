/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 22:11:56 by cdai              #+#    #+#             */
/*   Updated: 2020/01/19 22:54:49 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_free_splited(char **splited_data)
{
	int	i;

	i = 0;
	if (splited_data)
	{
		while (splited_data[i])
		{
			free(splited_data[i]);
			i++;
		}
		free(splited_data);
	}
	splited_data = NULL;
}

static void	ft_free_t_scene(t_scene **scene)
{
	int	i;

	i = 0;
	if (*scene)
	{
		while (i < 5)
		{
			if ((*scene)->sprite[i])
				free((*scene)->sprite[i]);
			i++;
		}
		i = 0;
		if ((*scene)->map)
		{
			while (((*scene)->map)[i])
			{
				free(((*scene)->map)[i]);
				i++;
			}
			free((*scene)->map);
		}
		free(*scene);
		*scene = NULL;
	}
}

void		*ft_free_all(t_scene **scene, t_scene **status, char **line,
	char **splited_data)
{
	if (scene)
		ft_free_t_scene(scene);
	if (status)
		ft_free_t_scene(status);
	if (line)
	{
		free(*line);
		*line = NULL;
	}
	if (splited_data)
		ft_free_splited(splited_data);
	return (NULL);
}
