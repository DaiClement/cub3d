/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:40:05 by cdai              #+#    #+#             */
/*   Updated: 2020/02/25 15:12:40 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_is_black(char *color)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (color[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

static void	ft_put_sprite_pixel(t_game_data *data, t_sprite *sprite, double x)
{
	int	y;
	int	init_pos;
	int	temp;
	int	pos;

	sprite->tex_x =
		(x - (-sprite->width / 2 + sprite->screen_x)) *
		data->sprite.width / sprite->width;
	init_pos = -(x * data->working_img.bits_per_pixel / 8 + 1);
	y = sprite->draw_start_y - 1;
	while (++y < sprite->draw_end_y)
	{
		sprite->tex_y = ((y + (sprite->height - data->scene.height)
			/ 2) * data->sprite.height) / sprite->height;
		temp = sprite->tex_y * data->sprite.size_line
		+ data->sprite.size_line - 4 - sprite->tex_x * 4;
		if (!ft_is_black(&data->sprite.img_data[temp]))
		{
			pos = init_pos + y * data->working_img.size_line;
			ft_put_pixel(data->working_img.img_data,
				&data->sprite.img_data[temp], pos);
		}
	}
}

static void	ft_init_sprite_calcul(t_game_data *data, t_sprite *sprite)
{
	sprite->sprite_x = sprite->x - data->camera.pos_x;
	sprite->sprite_y = sprite->y - data->camera.pos_y;
	sprite->inv_det = 1.0
		/ (data->camera.plane_x * data->camera.dir_y
		- data->camera.dir_x * data->camera.plane_y);
	sprite->transform_x = sprite->inv_det
		* (data->camera.dir_y * sprite->sprite_x
		- data->camera.dir_x * sprite->sprite_y);
	sprite->transform_y = sprite->inv_det
		* (-data->camera.plane_y * sprite->sprite_x
		+ data->camera.plane_x * sprite->sprite_y);
}

static void	ft_column_calcul(t_game_data *data, t_sprite *sprite, double x)
{
	sprite->screen_x = ((data->scene.width / 2)
		* (1 + sprite->transform_x / sprite->transform_y));
	sprite->width = fabs(data->scene.height
		/ (sprite->transform_y));
	sprite->draw_start_x = -sprite->width / 2
		+ sprite->screen_x;
	if (sprite->draw_start_x < 0)
		sprite->draw_start_x = 0;
	sprite->draw_end_x = sprite->width / 2 + sprite->screen_x;
	if (sprite->draw_end_x >= data->scene.width)
		sprite->draw_end_x = data->scene.width - 1;
	if (x >= sprite->draw_start_x && x < sprite->draw_end_x)
	{
		sprite->height =
			fabs((data->scene.height / (sprite->transform_y)));
		sprite->draw_start_y =
			-sprite->height / 2 + data->scene.height / 2;
		if (sprite->draw_start_y < 0)
			sprite->draw_start_y = 0;
		sprite->draw_end_y =
			sprite->height / 2 + data->scene.height / 2;
		if (sprite->draw_end_y >= data->scene.height)
			sprite->draw_end_y = data->scene.height - 1;
		ft_put_sprite_pixel(data, sprite, x);
	}
}

int			ft_handle_sprite(t_game_data *data, double perp_wall_dist, double x,
	t_sprite *sprite_list)
{
	t_sprite	*sprite;
	int			i;

	i = data->scene.map.nb_sprite - 1;
	while (i >= 0)
	{
		if (sprite_list[i].x)
		{
			sprite = sprite_list + i;
			ft_init_sprite_calcul(data, sprite);
			if (sprite->transform_y > 0 && sprite->transform_y < perp_wall_dist)
				ft_column_calcul(data, sprite, x);
		}
		i--;
	}
	return (1);
}
