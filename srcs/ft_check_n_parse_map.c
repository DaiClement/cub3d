/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_n_parse_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:07:55 by cdai              #+#    #+#             */
/*   Updated: 2020/01/27 14:45:39 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_check_map_first_line(char *first_line)
{
	int	i;

	i = 0;
	while (first_line[i])
	{
		if (first_line[i] != '1')
			return (-1);
		i++;
	}
	if (i < 3)
		return (-1);
	return (i);
}

static int	ft_check_map(char *other_line, int line_length,
	t_mapstatus *mapstatus, t_game_data *data, int j)
{
	int	i;
	int	first;
	int	last;

	i = -1;
	first = 0;
	last = 0;
	while (other_line[++i])
	{
		if (i == 0 && other_line[i] == '1')
			first = 1;
		else if (i == (line_length - 1) && other_line[i] == '1')
			last = 1;
		else if (ft_charchr("NSEW", other_line[i]))
		{
			if (mapstatus->orientation)
				return (-1);
			//other_line[i] = '0';
			mapstatus->orientation = other_line[i];
			data->camera = ft_calloc(1, sizeof(*(data->camera)));
			data->camera->posX = i;
			data->camera->posY = j;
			data->camera->start_angle = other_line[i];
			data->camera->dirX = -1;
			data->camera->dirY = 0;
			data->camera->planeX = 0;
			data->camera->planeY = 1;
			other_line[i] = '0';
		}
		else if (!ft_charchr("012", other_line[i]))
			return (-1);
	}
	if (i != line_length || !first || !last)
		return (-1);
	return (0);
}

int			ft_check_n_parse_map(t_game_data *data, t_scene **status)
{
	t_mapstatus	*mapstatus;
	int			i;
	char		**temp;

	mapstatus = ft_calloc(1, sizeof(*mapstatus));
	temp = data->scene->map;
	data->scene->map = ft_split(*temp, '\n');
	free(*temp);
	free(temp);
	i = -1;
	while ((data->scene->map)[++i])
	{
		if (i == 0)
			mapstatus->width = ft_check_map_first_line((data->scene->map)[i]);
		else if (ft_check_map(
			(data->scene->map)[i], mapstatus->width, mapstatus, data, i) == -1)
			return (-1);
	}
	if ((i - 1) < 2 || ft_check_map_first_line((data->scene->map)[i - 1]) == -1)
		return (-1);
	data->scene->orientation = mapstatus->orientation;
	(*status)->orientation = mapstatus->orientation;
	*(*status)->map = ft_calloc(2, sizeof(**((*status)->map)));
	**(*status)->map = '1';
	data->mapstatus = mapstatus;
	return (0);
}
