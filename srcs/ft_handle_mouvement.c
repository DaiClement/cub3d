/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_mouvement.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:22:10 by cdai              #+#    #+#             */
/*   Updated: 2020/02/03 18:15:13 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_mouv_forward(t_game_data *data)
{
	t_camera	*camera;

	camera = data->camera;
	if (data->scene->map
			[(int)(camera->pos_y)]
			[(int)(camera->pos_x + camera->dir_x * data->mov_flags->walk_speed)]
			== '0')
		camera->pos_x += camera->dir_x * data->mov_flags->walk_speed;
	if (data->scene->map
			[(int)(camera->pos_y + camera->dir_y * data->mov_flags->walk_speed)]
			[(int)(camera->pos_x)]
			== '0')
		camera->pos_y += camera->dir_y * data->mov_flags->walk_speed;
}

static void	ft_mouv_backward(t_game_data *data)
{
	t_camera	*camera;

	camera = data->camera;
	if (data->scene->map
			[(int)(camera->pos_y)]
			[(int)(camera->pos_x - camera->dir_x * data->mov_flags->walk_speed)]
			== '0')
		camera->pos_x -= camera->dir_x * data->mov_flags->walk_speed;
	if (data->scene->map
			[(int)(camera->pos_y - camera->dir_y * data->mov_flags->walk_speed)]
			[(int)(camera->pos_x)]
			== '0')
		camera->pos_y -= camera->dir_y * data->mov_flags->walk_speed;
}

static void	ft_mouv_left(t_game_data *data)
{
	t_camera	*camera;

	camera = data->camera;
	if (data->scene->map
			[(int)(camera->pos_y)]
			[(int)(camera->pos_x + camera->plane_x * data->mov_flags->walk_speed)]
			== '0')
		camera->pos_x += camera->plane_x * data->mov_flags->walk_speed;
	if (data->scene->map
			[(int)(camera->pos_y + camera->plane_y * data->mov_flags->walk_speed)]
			[(int)(camera->pos_x)]
			== '0')
		camera->pos_y += camera->plane_y * data->mov_flags->walk_speed;
}

static void	ft_mouv_right(t_game_data *data)
{
	t_camera	*camera;

	camera = data->camera;
	if (data->scene->map
			[(int)(camera->pos_y)]
			[(int)(camera->pos_x - camera->plane_x * data->mov_flags->walk_speed)]
			== '0')
		camera->pos_x -= camera->plane_x * data->mov_flags->walk_speed;
	if (data->scene->map
			[(int)(camera->pos_y - camera->plane_y * data->mov_flags->walk_speed)]
			[(int)(camera->pos_x)]
			== '0')
		camera->pos_y -= camera->plane_y * data->mov_flags->walk_speed;
}

void		ft_handle_mouvement(t_game_data *data)
{
	if (data->mov_flags->forward)
		ft_mouv_forward(data);
	if (data->mov_flags->backward)
		ft_mouv_backward(data);
	if (data->mov_flags->turn_left)
		ft_rotate_left(data);
	if (data->mov_flags->turn_right)
		ft_rotate_right(data);
	if (data->mov_flags->mov_left)
		ft_mouv_left(data);
	if (data->mov_flags->mov_right)
		ft_mouv_right(data);
}
