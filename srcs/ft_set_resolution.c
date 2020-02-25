/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:28:36 by cdai              #+#    #+#             */
/*   Updated: 2020/02/24 11:47:16 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_pre_atoi(char **splited_data)
{
	int i;

	i = 0;
	while (splited_data[i])
		i++;
	if (i != 3)
		return (ft_print_error("Resolution must have 2 arguments"));
	else if (!ft_check_atoi_max_min(splited_data[1]) ||
	!ft_check_atoi_max_min(splited_data[2]))
		return (ft_print_error("Resolution over INT_MAX or INT_MIN"));
	else if (!ft_str_isdigit(splited_data[1]) ||
	!ft_str_isdigit(splited_data[2]))
		return (ft_print_error("Resolution has not digit character"));
	return (1);
}

int			ft_set_resolution(t_scene *scene, char **splited_data)
{
	if (scene->width || scene->height)
		return (ft_print_error("Twice resolution"));
	if (!ft_pre_atoi(splited_data))
		return (0);
	scene->width = ft_atoi(splited_data[1]);
	scene->height = ft_atoi(splited_data[2]);
	if (!scene->width || !scene->height)
		return (0);
	if (scene->width > 2560)
		scene->width = 2560;
	if (scene->height > 1440)
		scene->height = 1440;
	return (1);
}
