/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_scene_element.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 12:23:05 by cdai              #+#    #+#             */
/*   Updated: 2020/01/17 11:57:21 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_check_ready_to_fullfill_map(t_scene **status)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (!(*status)->sprite[i])
			return (0);
		i++;
	}
	if (!(*status)->resolution[0] || !(*status)->resolution[1])
		return (0);
	else if ((!(*status)->floor[0]) || !(*status)->ceilling[0])
		return (0);
	return (1);
}

int			ft_check_scene_element(t_scene **scene, char **splited_data,
	t_scene **status)
{
	const	char *map[8] = {"NO", "SO", "WE", "EA", "S", "R", "F", "C"};
	int		i;

	i = 0;
	if (splited_data[0] == NULL)
		return (0);
	while (i < 8)
	{
		if (ft_check_ready_to_fullfill_map(status))
		{
			ft_fullfill_map(scene, splited_data, status);
			i = 8;
		}
		else if (ft_strncmp(splited_data[0], map[i], ft_strlen(map[i])) == 0)
		{
			if (i == 5)
				return (ft_fullfill_resolution(scene, splited_data, status));
			else if (i >= 0 && i <= 4)
				return (ft_fullfill_path(scene, splited_data, status, i));
			else if (i == 6)
				return (ft_fullfill_floor(scene, splited_data, status));
			else if (i == 7)
				return (ft_fullfill_ceilling(scene, splited_data, status));
		}
		i++;
	}
	return (0);
}
