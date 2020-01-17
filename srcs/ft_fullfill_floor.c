/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fullfill_floor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 22:04:55 by cdai              #+#    #+#             */
/*   Updated: 2020/01/17 11:29:26 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_fullfill_floor(t_scene **scene, char **splited_data, t_scene **status)
{
	int		j;
	int		nb_comma;

	j = 0;
	nb_comma = 0;
	if (((*status)->floor[0]) || (!splited_data[1]))
		return (-1);
	while (splited_data[1][j])
	{
		if (ft_isdigit(splited_data[1][j]) && nb_comma < 3 &&
			ft_check_atoi_max_min(splited_data[1] + j))
			(*scene)->floor[nb_comma] = ft_atoi(splited_data[1] + j);
		else
			return (-1);
		if (!(ft_isinrange((*scene)->floor[nb_comma], 0, 255)))
			return (-1);
		while (ft_isdigit(splited_data[1][j]))
			j++;
		if (splited_data[1][j] == ',')
			j++;
		nb_comma++;
	}
	(*status)->floor[0] = 1;
	return (0);
}
