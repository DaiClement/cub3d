/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:56:21 by cdai              #+#    #+#             */
/*   Updated: 2020/02/25 17:32:28 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_cast_ray(t_calcul *calcul, t_camera *camera)
{
	if (calcul->side_dist_x < calcul->side_dist_y)
	{
		calcul->side_dist_x += calcul->delta_dist_x;
		calcul->map_x += calcul->step_x;
		if (calcul->map_x < camera->pos_x)
			calcul->side = 2;
		else
			calcul->side = 3;
	}
	else
	{
		calcul->side_dist_y += calcul->delta_dist_y;
		calcul->map_y += calcul->step_y;
		if (calcul->map_y < camera->pos_y)
			calcul->side = 0;
		else
			calcul->side = 1;
	}
}

void		ft_raycasting(t_game_data *data, t_sprite *sprite_list)
{
	int			i;
	t_calcul	*calcul;

	i = 0;
	calcul = &data->calcul;
	while (!calcul->hit)
	{
		ft_cast_ray(calcul, &data->camera);
		if (data->scene.map.data[calcul->map_y][calcul->map_x] == '1')
			calcul->hit = 1;
		else if (data->scene.map.data[calcul->map_y][calcul->map_x] == '2')
		{
			if (i < data->scene.map.nb_sprite)
			{
				sprite_list[i].x = calcul->map_x + 0.5;
				sprite_list[i].y = calcul->map_y + 0.5;
			}
			i++;
		}
	}
}
