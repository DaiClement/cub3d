/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_n_parse_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:42:58 by cdai              #+#    #+#             */
/*   Updated: 2020/02/25 12:24:55 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_check_full_line(t_map *map, int line_index)
{
	int	i;

	i = 0;
	while (map->data[line_index][i])
	{
		if (map->data[line_index][i] != '1')
			return (ft_print_error("Map not closed"));
		i++;
	}
	if (i < 3)
		return (ft_print_error("Map too small"));
	map->width = i;
	return (1);
}

static int	ft_parse_map(char *line, t_map *map, int line_index)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (ft_charchr("NSEW", line[i]))
		{
			if (map->start_angle)
				return (ft_print_error("Map has 2 start points"));
			map->start_angle = line[i];
			map->start_pos_x = i;
			map->start_pos_y = line_index;
			line[i] = '0';
		}
		else if (line[i] == '2')
			(map->nb_sprite)++;
		else if (!ft_charchr("012", line[i]))
			return (ft_print_error("Map has wrong character"));
	}
	if (i != map->width || line[i - 1] != '1' || line[0] != '1')
		return (ft_print_error("Map not closed or too small"));
	return (1);
}

static int	ft_map_last_check(t_map *map)
{
	if (map->height < 3)
		return (ft_print_error("Map too small"));
	else if (!ft_check_full_line(map, map->height - 1))
		return (ft_print_error("Map not closed"));
	else if (!map->start_angle)
		return (ft_print_error("Map has not start point"));
	return (1);
}

int			ft_check_n_parse_map(t_map *map)
{
	int			i;
	char		**temp;

	temp = map->data;
	if (!(map->data = ft_split(*temp, '\n')))
	{
		ft_free_gnl_value(NULL, temp);
		return (ft_print_error("Malloc error (ft_check_n_parse_map)"));
	}
	ft_free_gnl_value(NULL, temp);
	i = 0;
	if (!ft_check_full_line(map, 0))
		return (0);
	while (map->data[i])
	{
		if (!ft_parse_map((map->data)[i], map, i))
			return (0);
		i++;
	}
	map->height = i;
	return (ft_map_last_check(map));
}
