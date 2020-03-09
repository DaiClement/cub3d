/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_mouvement.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:44:39 by cdai              #+#    #+#             */
/*   Updated: 2020/03/05 12:04:07 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_mouv_forward_backward(t_game_data *data, int direction)
{
	t_camera	*camera;

	camera = &data->camera;
	if (data->scene.map.data
			[(int)(camera->pos_y)]
			[(int)(camera->pos_x + direction * camera->dir_x
				* data->mov_flags.walk_speed)]
			== '0')
		camera->pos_x += direction * camera->dir_x
			* data->mov_flags.walk_speed;
	if (data->scene.map.data
			[(int)(camera->pos_y + direction * camera->dir_y
				* data->mov_flags.walk_speed)]
			[(int)(camera->pos_x)]
			== '0')
		camera->pos_y += direction * camera->dir_y
			* data->mov_flags.walk_speed;
}

static void	ft_mouv_left_right(t_game_data *data, int direction)
{
	t_camera	*camera;

	camera = &data->camera;
	if (data->scene.map.data
			[(int)(camera->pos_y)]
			[(int)(camera->pos_x + direction * camera->plane_x
			* data->mov_flags.walk_speed)]
			== '0')
		camera->pos_x += direction * camera->plane_x
			* data->mov_flags.walk_speed;
	if (data->scene.map.data
			[(int)(camera->pos_y + direction * camera->plane_y
			* data->mov_flags.walk_speed)]
			[(int)(camera->pos_x)]
			== '0')
		camera->pos_y += direction * camera->plane_y
			* data->mov_flags.walk_speed;
}

static void	ft_rotate_left_right(t_game_data *data, int direction)
{
	double		old_dir_x;
	double		old_plane_x;
	t_camera	*camera;

	camera = &data->camera;
	old_dir_x = camera->dir_x;
	camera->dir_x = camera->dir_x *
		cos(direction * data->mov_flags.rotation_speed) -
		camera->dir_y *
		sin(direction * data->mov_flags.rotation_speed);
	camera->dir_y = old_dir_x *
		sin(direction * data->mov_flags.rotation_speed) +
		camera->dir_y *
		cos(direction * data->mov_flags.rotation_speed);
	old_plane_x = camera->plane_x;
	camera->plane_x = camera->plane_x *
		cos(direction * data->mov_flags.rotation_speed) -
		camera->plane_y *
		sin(direction * data->mov_flags.rotation_speed);
	camera->plane_y = old_plane_x *
		sin(direction * data->mov_flags.rotation_speed) +
		camera->plane_y *
		cos(direction * data->mov_flags.rotation_speed);
}

void		ft_handle_mouvement(t_game_data *data)
{
	if (data->mov_flags.forward)
		ft_mouv_forward_backward(data, 1);
	if (data->mov_flags.backward)
		ft_mouv_forward_backward(data, -1);
	if (data->mov_flags.turn_left)
		ft_rotate_left_right(data, -1);
	if (data->mov_flags.turn_right)
		ft_rotate_left_right(data, 1);
	if (data->mov_flags.mov_left)
		ft_mouv_left_right(data, 1);
	if (data->mov_flags.mov_right)
		ft_mouv_left_right(data, -1);
}
