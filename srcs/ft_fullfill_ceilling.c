/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fullfill_ceilling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 22:04:37 by cdai              #+#    #+#             */
/*   Updated: 2020/02/08 18:02:57 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_fullfill_ceilling(t_scene **scene, char **splited_data, t_scene **status)
{
	int		j;
	int		nb_comma;

	j = 0;
	nb_comma = 0;
	if (((*status)->ceilling[0]) || (!splited_data[1]))
		return (-1);
	while (splited_data[1][j])
	{
		if (ft_isdigit(splited_data[1][j]) && nb_comma < 3 &&
			ft_check_atoi_max_min(splited_data[1] + j))
			(*scene)->ceilling[nb_comma + 1] = ft_atoi(splited_data[1] + j);
		else
			return (-1);
		if (!(ft_isinrange((*scene)->ceilling[nb_comma], 0, 255)))
			return (-1);
		while (ft_isdigit(splited_data[1][j]))
			j++;
		if (splited_data[1][j] == ',')
			j++;
		nb_comma++;
	}
	(*status)->ceilling[0] = 1;
	return (1);
}
