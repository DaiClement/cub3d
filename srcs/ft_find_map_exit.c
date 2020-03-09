/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_map_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:59:41 by cdai              #+#    #+#             */
/*   Updated: 2020/03/05 16:30:19 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_fullfill_arround(int arround[8][2])
{
	arround[0][0] = 0;
	arround[0][1] = -1;
	arround[1][0] = -1;
	arround[1][1] = -1;
	arround[2][0] = -1;
	arround[2][1] = 0;
	arround[3][0] = -1;
	arround[3][1] = 1;
	arround[4][0] = 0;
	arround[4][1] = 1;
	arround[5][0] = 1;
	arround[5][1] = 1;
	arround[6][0] = 1;
	arround[6][1] = 0;
	arround[7][0] = 1;
	arround[7][1] = -1;
}

static int	ft_check_arround(char **temp, t_map *map, int line, int column)
{
	int	arround[8][2];
	int	i;
	int	temp_line;
	int	temp_column;

	i = -1;
	ft_fullfill_arround(arround);
	while (++i < 8)
	{
		temp_line = line + arround[i][0];
		temp_column = column + arround[i][1];
		if ((temp_line < 0 || temp_line >= map->height)
			|| (temp_column < 0 || temp_column >= map->width))
			return (0);
		else if (temp[temp_line][temp_column] == ' ')
			return (0);
		else if (temp[temp_line][temp_column] == '\0')
			return (0);
	}
	return (1);
}

int			ft_find_map_exit(char **temp, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (temp[++i])
	{
		j = -1;
		while (temp[i][++j])
		{
			if (!ft_charchr("012 NSEW", temp[i][j]))
				return (1);
			else if (ft_charchr("02NSEW", temp[i][j]))
				if (!ft_check_arround(temp, map, i, j))
					return (1);
		}
	}
	return (0);
}
