/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fullfill_scene.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 11:19:21 by cdai              #+#    #+#             */
/*   Updated: 2020/01/19 22:30:38 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_check_status(t_scene **status)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (((*status)->sprite)[i])
			return (-1);
		i++;
	}
	if (!(((*status)->resolution)[0]) || !(((*status)->resolution)[1]))
		return (-1);
	else if (!(((*status)->floor)[0]) || !(((*status)->ceilling)[0]))
		return (-1);
	else if (!((((*status)->map)[0])) || !((*status)->orientation))
		return (-1);
	return (0);
}

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

	if (!(ft_init_scene_status(&scene, &status)) ||
		(fd = open(filename, O_RDONLY)) == -1)
		return (ft_free_all(&scene, &status, NULL, NULL));
	while (get_next_line(fd, &line) == 1)
	{
		splited_data = ft_split(line, ' ');
		if (!ft_check_scene_element(&scene, splited_data, &status))
			return (ft_free_all(&scene, &status, &line, splited_data));
		ft_free_all(NULL, NULL, &line, splited_data);
	}
	ft_check_n_parse_map(&scene, &status);
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
printf("Map : %s\n", *status->map);
printf("Orientation : %c\n", status->orientation);
	//if (ft_check_status(&status) == -1)
	//	return (ft_free_all(&scene, &status, &line, splited_data));
	printf("pouet\n");
	return (scene);
}
