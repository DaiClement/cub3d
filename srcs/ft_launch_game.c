/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:39:28 by cdai              #+#    #+#             */
/*   Updated: 2020/03/07 10:46:44 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_launch_game(char *filename)
{
	t_game_data	data;

	ft_bzero(&data, sizeof(data));
	if (!ft_parse_cub(&data.scene, filename))
		return (ft_free_data(&data));
	data.camera.pos_x += data.scene.map.start_pos_x + 0.5;
	data.camera.pos_y += data.scene.map.start_pos_y + 0.5;
	data.mov_flags.walk_speed = 0.2;
	data.mov_flags.rotation_speed = 0.2;
	ft_init_orientation(&data);
	if (!ft_prepare_mlx(&data) || !ft_prepare_textures_n_sprite(&data))
		return (ft_free_data(&data));
	else if (!(data.mlx.win = mlx_new_window(data.mlx.ptr, data.scene.width,
		data.scene.height, "Cub3D")))
	{
		ft_free_data(&data);
		return (ft_print_error("MLX error (ft_launch_game)"));
	}
	ft_handle_keyboard(&data);
	mlx_loop_hook(data.mlx.ptr, ft_play_game, &data);
	mlx_loop(data.mlx.ptr);
	ft_free_data(&data);
	return (0);
}
