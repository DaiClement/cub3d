/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_n_parse_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:42:58 by cdai              #+#    #+#             */
/*   Updated: 2020/03/09 10:08:19 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_get_map_dimensions(char **data, t_map *map)
{
	int	height;
	int	width;

	height = 0;
	while (data[height])
	{
		width = 0;
		while (data[height][width])
			width++;
		if (width > map->width)
			map->width = width;
		height++;
	}
	map->height = height;
	if (map->height < 3 || map->width < 3)
		return (0);
	return (1);
}

static int	ft_replace_space_by_char(char **map_data, int width, char c)
{
	int		i;
	int		j;
	char	*temp;

	i = -1;
	while (map_data[++i])
	{
		if (!(temp = ft_calloc(width + 1, sizeof(*temp))))
			return (0);
		j = -1;
		while (map_data[i][++j])
		{
			if (map_data[i][j] == ' ')
				temp[j] = c;
			else
				temp[j] = map_data[i][j];
		}
		j--;
		while (++j < width)
			temp[j] = c;
		free(map_data[i]);
		map_data[i] = temp;
	}
	return (1);
}

static int	ft_check_start_pos_n_nb_sprite(char **temp, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (temp[++i])
	{
		j = -1;
		while (temp[i][++j])
		{
			if (temp[i][j] == '2')
				map->nb_sprite++;
			else if (ft_charchr("NSEW", temp[i][j]))
			{
				if (map->start_angle)
					return (0);
				map->start_angle = temp[i][j];
				map->start_pos_x = j;
				map->start_pos_y = i;
				temp[i][j] = '0';
			}
		}
	}
	return (1);
}

int			ft_check_n_parse_map(t_map *map)
{
	char	**temp;

	if (!(temp = ft_split(*map->data, '\n')))
		return (ft_print_error("Malloc error (ft_check_n_parse_map)"));
	free(*map->data);
	free(map->data);
	map->data = temp;
	if (!(ft_get_map_dimensions(temp, map)))
		return (ft_print_error("Map dimension error"));
	else if (!(ft_replace_space_by_char(temp, map->width, ' ')))
		return (ft_print_error("Malloc error (ft_check_n_parse_map)"));
	else if (ft_find_map_exit(temp, map))
		return (ft_print_error("Map not closed or character not valid"));
	else if (!(ft_replace_space_by_char(temp, map->width, '1')))
		return (ft_print_error("Malloc error (ft_check_n_parse_map)"));
	else if (!(ft_check_start_pos_n_nb_sprite(temp, map)))
		return (ft_print_error("Map has 2 start points"));
	else if (!map->start_angle)
		return (ft_print_error("Map has not start points"));
	return (1);
}
