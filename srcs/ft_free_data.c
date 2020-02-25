/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:58:19 by cdai              #+#    #+#             */
/*   Updated: 2020/02/25 15:39:31 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_free_mlx(t_game_data *data)
{
	int	i;

	i = -1;
	if (data->mlx.ptr)
	{
		if (data->working_img.image)
			mlx_destroy_image(data->mlx.ptr, data->working_img.image);
		while (++i < 4)
			if (data->textures[i].image)
				mlx_destroy_image(data->mlx.ptr, data->textures[i].image);
		if (data->sprite.image)
			mlx_destroy_image(data->mlx.ptr, data->sprite.image);
		if (data->mlx.win)
		{
			mlx_clear_window(data->mlx.ptr, data->mlx.win);
			mlx_destroy_window(data->mlx.ptr, data->mlx.win);
		}
	}
}

int			ft_free_data(t_game_data *data)
{
	ft_free_scene(&data->scene);
	ft_free_mlx(data);
	return (0);
}
