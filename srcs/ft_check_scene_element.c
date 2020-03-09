/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_scene_element.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:17:17 by cdai              #+#    #+#             */
/*   Updated: 2020/03/09 16:47:19 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_check_ready_to_fullfill_map(t_scene *scene)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!scene->path[i])
			return (0);
		i++;
	}
	if (!scene->sprite)
		return (0);
	else if (!scene->width || !scene->height)
		return (0);
	else if ((!scene->floor_is_set) || !scene->ceilling_is_set)
		return (0);
	return (1);
}

static int	ft_check_type(char **splited_data)
{
	const char	*elem_type[8] = {"NO", "SO", "WE", "EA", "S", "R", "F", "C"};
	int			i;
	int			type_len;
	int			elem_type_len;

	i = 0;
	type_len = ft_strlen(splited_data[0]);
	while (i < 8)
	{
		elem_type_len = ft_strlen(elem_type[i]);
		if (type_len != elem_type_len
		|| ft_strncmp(splited_data[0], elem_type[i], elem_type_len))
			i++;
		else
			return (i);
	}
	return (-1);
}

int			ft_check_scene_element(t_scene *scene, char **splited_data,
	char *line)
{
	int	elem_type;

	if (!splited_data)
		return (ft_print_error("Malloc error"));
	if (ft_check_ready_to_fullfill_map(scene))
		return (ft_handle_map(&scene->map, line));
	else if (*splited_data == NULL)
		return (1);
	elem_type = ft_check_type(splited_data);
	if (elem_type == 5)
		return (ft_set_resolution(scene, splited_data));
	else if (elem_type >= 0 && elem_type <= 4)
		return (ft_handle_path(scene, splited_data, elem_type));
	else if (elem_type == 6 || elem_type == 7)
		return (ft_handle_color(scene, splited_data, elem_type));
	else
		return (ft_print_error("Missing element or wrong element"));
}
