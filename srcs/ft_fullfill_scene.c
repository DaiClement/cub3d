/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fullfill_scene.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 11:19:21 by cdai              #+#    #+#             */
/*   Updated: 2020/01/17 11:36:49 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_init_scene_status(t_scene **scene, t_scene **status)
{
	if (!(*scene = malloc(sizeof(**scene))))
		return (0);
	else if (!(*status = malloc(sizeof(**status))))
	{
		free(*scene);
		return (0);
	}
	ft_bzero(*scene, sizeof(**scene));
	ft_bzero(*status, sizeof(**status));
	return (1);
}

t_scene		*ft_fullfill_scene(const char *filename)
{
	t_scene	*scene;
	int		fd;
	char	*line;
	char	**splited_data;
	t_scene	*status;

	if (!(ft_init_scene_status(&scene, &status)))
		return (NULL);
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		splited_data = ft_split(line, ' ');
		ft_check_scene_element(&scene, splited_data, &status);
		ft_free_splited(splited_data, line);
	}
	//ft_free_splited(splited_data, line);
	free(line);
	close(fd);
	printf("Resolution x: %d\n",status->resolution[0]);
    printf("Resolution y: %d\n",status->resolution[1]);
    printf("North textures path: %s\n", status->sprite[0]);
    printf("South textures path: %s\n", status->sprite[1]);
    printf("West textures path: %s\n", status->sprite[2]);
    printf("East textures path: %s\n", status->sprite[3]);
    printf("Sprite textures path: %s\n", status->sprite[4]);
    printf("Floor color RGBA: %d,%d,%d,%d\n", status->floor[0], status->floor[1], status->floor[2], status->floor[3]);
    printf("Ceilling color RGBA: %d,%d,%d,%d\n", status->ceilling[0], status->ceilling[1], status->ceilling[2], status->ceilling[3]);
	ft_free_scene(&status);
	return (scene);
}
