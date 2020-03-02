/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_screenshot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:03:04 by cdai              #+#    #+#             */
/*   Updated: 2020/03/02 17:30:39 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_take_screenshot(char *filename)
{
	t_game_data data;

	ft_bzero(&data, sizeof(data));
	if (!(ft_parse_cub(&data.scene, filename)))
		return (ft_free_data(&data));
	data.camera.pos_x += data.scene.map.start_pos_x + 0.5;
	data.camera.pos_y += data.scene.map.start_pos_y + 0.5;
	ft_init_orientation(&data);
	if (!ft_prepare_mlx(&data) || !ft_prepare_textures_n_sprite(&data))
		return (ft_free_data(&data));
	ft_handle_image(&data);
	if (!(ft_create_bmp_file(&data)))
		return (ft_free_data(&data));
	return (ft_free_data(&data));
}
