/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:39:28 by cdai              #+#    #+#             */
/*   Updated: 2020/02/25 15:14:55 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_init_game(t_game_data *data)
{
	data->camera.pos_x += data->scene.map.start_pos_x + 0.5;
	data->camera.pos_y += data->scene.map.start_pos_y + 0.5;
	data->mov_flags.walk_speed = 0.31;
	data->mov_flags.rotation_speed = 0.2;
	ft_init_orientation(data);
}

int			ft_launch_game(char *filename)
{
	t_game_data	data;

	ft_bzero(&data, sizeof(data));
	if (!ft_parse_cub(&data.scene, filename))
		return (ft_free_data(&data));
	ft_init_game(&data);
	if (!ft_prepare_mlx(&data) || !ft_prepare_textures_n_sprite(&data))
		return (0);
	else if (!(data.mlx.win = mlx_new_window(data.mlx.ptr, data.scene.width,
		data.scene.height, "cub3D")))
		return (ft_print_error("MLX error (ft_launch_game)"));
	ft_handle_keyboard(&data);
	mlx_loop_hook(data.mlx.ptr, ft_play_game, &data);
	mlx_loop(data.mlx.ptr);
	ft_free_data(&data);
	return (0);
}
