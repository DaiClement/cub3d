/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:42:24 by cdai              #+#    #+#             */
/*   Updated: 2020/02/24 15:57:23 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_prepare_mlx(t_game_data *data)
{
	if (!(data->mlx.ptr = mlx_init()))
		return (ft_print_error("MLX error (ft_prepare_mlx)"));
	else if (!(data->working_img.image = mlx_new_image(data->mlx.ptr,
		data->scene.width, data->scene.height)))
		return (ft_print_error("MLX error (ft_prepare_mlx)"));
	else if (!(data->working_img.img_data = mlx_get_data_addr(
		data->working_img.image, &data->working_img.bits_per_pixel,
		&data->working_img.size_line, &data->working_img.endian)))
		return (ft_print_error("MLX error (ft_prepare_mlx)"));
	return (1);
}
