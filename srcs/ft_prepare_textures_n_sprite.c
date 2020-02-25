/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_textures_n_sprite.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:25:32 by cdai              #+#    #+#             */
/*   Updated: 2020/02/24 16:00:37 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_prepare_sprite(t_game_data *data)
{
	if (!(data->sprite.image = mlx_xpm_file_to_image(data->mlx.ptr,
		data->scene.sprite, &data->sprite.width,
		&data->sprite.height)))
		return (ft_print_error("MLX error (ft_prepare_textures_n_sprite)"));
	else if (!(data->sprite.img_data =
		mlx_get_data_addr(data->sprite.image,
		&data->sprite.bits_per_pixel, &data->sprite.size_line,
		&data->sprite.endian)))
		return (ft_print_error("MLX error (ft_prepare_textures_n_sprite)"));
	data->sprite.img_size = data->sprite.width
		* data->sprite.height * 4;
	return (1);
}

int			ft_prepare_textures_n_sprite(t_game_data *data)
{
	int	i;

	i = 0;
	ft_bzero(data->textures, 4 * sizeof(*data->textures));
	while (i < 4)
	{
		if (!(data->textures[i].image = mlx_xpm_file_to_image(data->mlx.ptr,
			data->scene.path[i], &data->textures[i].width,
			&data->textures[i].height)))
			return (ft_print_error("MLX error (ft_prepare_textures_n_sprite)"));
		else if (!(data->textures[i].img_data =
			mlx_get_data_addr(data->textures[i].image,
			&data->textures[i].bits_per_pixel, &data->textures[i].size_line,
			&data->textures[i].endian)))
			return (ft_print_error("MLX error (ft_prepare_textures_n_sprite)"));
		data->textures[i].img_size = data->textures[i].width
			* data->textures[i].height * 4;
		i++;
	}
	if (!ft_prepare_sprite(data))
		return (0);
	return (1);
}
