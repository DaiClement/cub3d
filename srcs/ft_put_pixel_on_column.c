/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel_on_column.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:52:30 by cdai              #+#    #+#             */
/*   Updated: 2020/02/26 18:01:54 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_put_texture_pixel(t_game_data *data, double y)
{
	data->calcul.tex_y =
		(y * 2 - data->scene.height + data->calcul.lign_height)
		* (data->textures[data->calcul.side].height / 2)
		/ data->calcul.lign_height;
	data->calcul.temp =
		data->textures[data->calcul.side].img_size - 4
		- (floor(data->calcul.tex_y)
		* data->textures[data->calcul.side].size_line
		+ floor(data->calcul.tex_x) * 4 + 4);
	data->calcul.pos = data->calcul.init_pos
		- y * data->working_img.size_line;
	ft_put_pixel(data->working_img.img_data,
		&data->textures[data->calcul.side].img_data[data->calcul.temp],
		data->calcul.pos);
}

static void	ft_put_floor_ceilling_pixel(t_game_data *data, double y)
{
	data->calcul.pos = data->calcul.init_pos
		- y * data->working_img.size_line;
	ft_put_pixel(data->working_img.img_data, data->scene.floor,
		data->calcul.pos);
	data->calcul.pos = data->calcul.init_pos
		- (data->scene.height - y - 1) * data->working_img.size_line;
	ft_put_pixel(data->working_img.img_data, data->scene.ceilling,
		data->calcul.pos);
}

void		ft_put_pixel_on_column(t_game_data *data, double x)
{
	int y;

	y = data->calcul.draw_start;
	while (y < data->scene.height)
	{
		data->calcul.init_pos = data->scene.width
			* data->scene.height * 4
			- 1 - x * data->working_img.bits_per_pixel / 8;
		if (y < data->calcul.draw_end)
			ft_put_texture_pixel(data, y);
		else
			ft_put_floor_ceilling_pixel(data, y);
		y++;
	}
}
