/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:36:21 by cdai              #+#    #+#             */
/*   Updated: 2020/03/02 17:19:48 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_set_column_height(t_game_data *data, t_calcul *calcul,
	int win_height)
{
	if (calcul->side > 1)
		calcul->perp_wall_dist = fabs((calcul->map_x - data->camera.pos_x
			+ (1 - calcul->step_x) / 2) / calcul->ray_dir_x);
	else
		calcul->perp_wall_dist = fabs((calcul->map_y - data->camera.pos_y
			+ (1 - calcul->step_y) / 2) / calcul->ray_dir_y);
	calcul->lign_height = fabs(win_height
			/ calcul->perp_wall_dist);
	calcul->draw_start = (-calcul->lign_height + win_height) / 2;
	calcul->draw_end = (calcul->lign_height + win_height) / 2;
	if (calcul->draw_start < 0)
		calcul->draw_start = 0;
	if (calcul->draw_end > win_height)
		calcul->draw_end = win_height;
	if (calcul->side < 2)
		calcul->wall_x = data->camera.pos_x
			+ ((calcul->map_y - data->camera.pos_y
			+ (1 - calcul->step_y) / 2)
			/ calcul->ray_dir_y) * calcul->ray_dir_x;
	else
		calcul->wall_x = data->camera.pos_y
			+ ((calcul->map_x - data->camera.pos_x
			+ (1 - calcul->step_x) / 2)
			/ calcul->ray_dir_x) * calcul->ray_dir_y;
	calcul->wall_x -= floor(calcul->wall_x);
}

static void	ft_start_calcul(t_calcul *calcul, t_camera *camera)
{
	calcul->ray_dir_x = camera->dir_x + camera->plane_x * calcul->camera_x;
	calcul->ray_dir_y = camera->dir_y + camera->plane_y * calcul->camera_x;
	calcul->map_x = camera->pos_x;
	calcul->map_y = camera->pos_y;
	calcul->delta_dist_x = sqrt(1
			+ (calcul->ray_dir_y * calcul->ray_dir_y)
			/ (calcul->ray_dir_x * calcul->ray_dir_x));
	calcul->delta_dist_y = sqrt(1
			+ (calcul->ray_dir_x * calcul->ray_dir_x)
			/ (calcul->ray_dir_y * calcul->ray_dir_y));
	calcul->hit = 0;
}

static void	ft_set_direction_distance(t_camera *camera, t_calcul *calcul)
{
	if (calcul->ray_dir_x < 0)
	{
		calcul->step_x = -1;
		calcul->side_dist_x = (camera->pos_x - calcul->map_x)
			* calcul->delta_dist_x;
	}
	else
	{
		calcul->step_x = 1;
		calcul->side_dist_x = calcul->delta_dist_x
			* (calcul->map_x + 1.0 - camera->pos_x);
	}
	if (calcul->ray_dir_y < 0)
	{
		calcul->step_y = -1;
		calcul->side_dist_y = calcul->delta_dist_y
			* (camera->pos_y - calcul->map_y);
	}
	else
	{
		calcul->step_y = 1;
		calcul->side_dist_y = calcul->delta_dist_y
			* (calcul->map_y + 1.0 - camera->pos_y);
	}
}

void		ft_handle_image(t_game_data *data)
{
	double		x;
	t_sprite	sprite_list[data->scene.map.nb_sprite];

	x = 0;
	ft_handle_mouvement(data);
	while (x < data->scene.width)
	{
		data->calcul.camera_x = (2 * x / data->scene.width) - 1;
		ft_start_calcul(&data->calcul, &data->camera);
		ft_set_direction_distance(&data->camera, &data->calcul);
		ft_raycasting(data, sprite_list);
		ft_set_column_height(data, &data->calcul, data->scene.height);
		data->calcul.tex_x = data->calcul.wall_x
			* data->textures[data->calcul.side].width;
		data->calcul.tex_x = data->textures[data->calcul.side].width
			- data->calcul.tex_x - 1;
		ft_put_pixel_on_column(data, x);
		data->calcul.tex_x = data->calcul.wall_x * data->sprite.width;
		data->calcul.tex_x = data->sprite.width - data->calcul.tex_x - 1;
		ft_handle_sprite(data, data->calcul.perp_wall_dist, x, sprite_list);
		x++;
	}
}
