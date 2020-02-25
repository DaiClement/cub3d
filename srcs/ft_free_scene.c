/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 11:48:59 by cdai              #+#    #+#             */
/*   Updated: 2020/02/20 11:54:02 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_scene(t_scene *scene)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (scene->path[i])
			free(scene->path[i]);
		i++;
	}
	if (scene->sprite)
		free(scene->sprite);
	i = 0;
	if (scene->map.data)
	{
		while (scene->map.data[i])
		{
			free(scene->map.data[i]);
			i++;
		}
		free(scene->map.data);
	}
}
