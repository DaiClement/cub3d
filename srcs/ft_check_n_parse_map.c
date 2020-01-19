/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_n_parse_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:07:55 by cdai              #+#    #+#             */
/*   Updated: 2020/01/19 21:16:15 by cdai             ###   ########.fr       */
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
	t_mapstatus *mapstatus)
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
			mapstatus->orientation = other_line[i];
		}
		else if (!ft_charchr("012", other_line[i]))
			return (-1);
	}
	if (i != line_length || !first || !last)
		return (-1);
	return (0);
}

int			ft_check_n_parse_map(t_scene **scene, t_scene **status)
{
	t_mapstatus	mapstatus;
	int			i;
	char		**temp;

	ft_bzero(&mapstatus, sizeof(mapstatus));
	temp = (*scene)->map;
	(*scene)->map = ft_split(*temp, '\n');
	free(*temp);
	free(temp);
	i = -1;
	while (((*scene)->map)[++i])
	{
		if (i == 0)
			mapstatus.line_length = ft_check_map_first_line(((*scene)->map)[i]);
		else if (ft_check_map(
			((*scene)->map)[i], mapstatus.line_length, &mapstatus) == -1)
			return (-1);
	}
	if ((i - 1) < 2 || ft_check_map_first_line(((*scene)->map)[i - 1]) == -1)
		return (-1);
	(*scene)->orientation = mapstatus.orientation;
	(*status)->orientation = mapstatus.orientation;
	*(*status)->map = ft_calloc(2, sizeof(**((*status)->map)));
	**(*status)->map = '1';
	return (0);
}
