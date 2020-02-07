/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_mouvement_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:37:34 by cdai              #+#    #+#             */
/*   Updated: 2020/02/05 16:52:28 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_rotate_right(t_game_data *data)
{
	double		oldDir_x;
	double		oldPlane_x;
	t_camera	*camera;

	camera = data->camera;
	oldDir_x = camera->dir_x;
	camera->dir_x = camera->dir_x *
		cos(data->mov_flags->rotation_speed) -
		camera->dir_y *
		sin(data->mov_flags->rotation_speed);
	camera->dir_y = oldDir_x *
		sin(data->mov_flags->rotation_speed) +
		camera->dir_y *
		cos(data->mov_flags->rotation_speed);
	oldPlane_x = camera->plane_x;
	camera->plane_x = camera->plane_x *
		cos(data->mov_flags->rotation_speed) -
		camera->plane_y *
		sin(data->mov_flags->rotation_speed);
	camera->plane_y = oldPlane_x *
		sin(data->mov_flags->rotation_speed) +
		camera->plane_y *
		cos(data->mov_flags->rotation_speed);
	printf("planeX :%f, planeY :%f\n", data->camera->plane_x, data->camera->plane_y);
	printf("dirX :%f, dirY :%f\n", data->camera->dir_x, data->camera->dir_y);
}

void	ft_rotate_left(t_game_data *data)
{
	double		oldDir_x;
	double		oldPlane_x;
	t_camera	*camera;

	camera = data->camera;
	oldDir_x = camera->dir_x;
	camera->dir_x = camera->dir_x *
		cos(-data->mov_flags->rotation_speed) -
		camera->dir_y *
		sin(-data->mov_flags->rotation_speed);
	camera->dir_y = oldDir_x *
		sin(-data->mov_flags->rotation_speed) +
		camera->dir_y *
		cos(-data->mov_flags->rotation_speed);
	oldPlane_x = camera->plane_x;
	camera->plane_x = camera->plane_x *
		cos(-data->mov_flags->rotation_speed) -
		camera->plane_y *
		sin(-data->mov_flags->rotation_speed);
	camera->plane_y = oldPlane_x *
		sin(-data->mov_flags->rotation_speed) +
		camera->plane_y *
		cos(-data->mov_flags->rotation_speed);
	printf("planeX :%f, planeY :%f\n", data->camera->plane_x, data->camera->plane_y);
	printf("dirX :%f, dirY :%f\n", data->camera->dir_x, data->camera->dir_y);
}
