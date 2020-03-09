/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel_on_column.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:52:30 by cdai              #+#    #+#             */
/*   Updated: 2020/03/09 14:40:00 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_put_texture_pixel(t_game_data *data, double y)
{
	int		temp;
	t_image	textures;

	textures = data->textures[data->calcul.side];
	data->calcul.tex_y =
		(y * 2 - data->scene.height + data->calcul.lign_height)
		* (textures.height / 2)
		/ data->calcul.lign_height;
	temp =
		data->textures[data->calcul.side].img_size
		- (floor(data->calcul.tex_y)
		* textures.size_line
		+ floor(data->calcul.tex_x) * 4);
	ft_put_pixel(data->working_img.img_data,
		&textures.img_data[temp],
		data->calcul.pos);
}

static void	ft_put_floor_ceilling_pixel(t_game_data *data, double y)
{
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
		data->calcul.pos = data->calcul.init_pos
			- y * data->working_img.size_line;
		if (y < data->calcul.draw_end)
			ft_put_texture_pixel(data, y);
		else
			ft_put_floor_ceilling_pixel(data, y);
		y++;
	}
}
