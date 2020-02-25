/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_orientation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:13:48 by cdai              #+#    #+#             */
/*   Updated: 2020/02/19 17:06:06 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_orientation(t_game_data *data)
{
	if (data->scene.map.start_angle == 'N')
	{
		data->camera.dir_y = -1.0;
		data->camera.plane_x = -1.0;
	}
	else if (data->scene.map.start_angle == 'S')
	{
		data->camera.dir_y = 1.0;
		data->camera.plane_x = 1.0;
	}
	else if (data->scene.map.start_angle == 'W')
	{
		data->camera.dir_x = -1.0;
		data->camera.plane_y = 1.0;
	}
	else if (data->scene.map.start_angle == 'E')
	{
		data->camera.dir_x = 1.0;
		data->camera.plane_y = -1.0;
	}
}
