/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_images.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:54:25 by cdai              #+#    #+#             */
/*   Updated: 2020/01/29 14:13:41 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_prepare_images(t_game_data *data)
{
	int	i;

	i = 0;
	ft_bzero(data->sprite, 5 * sizeof(*data->sprite));
	while (i < 5)
	{
		data->sprite[i].image = mlx_xpm_file_to_image(data->mlx->ptr, data->scene->sprite[i], &data->sprite[i].width, &data->sprite[i].height);
		data->sprite[i].img_data = mlx_get_data_addr(data->sprite[i].image, &data->sprite[i].bits_per_pixel, &data->sprite[i].size_line, &data->sprite[1].endian);
		i++;
	}
	data->image = ft_calloc(1, sizeof(*(data->image)));
	data->image->image = mlx_new_image(data->mlx->ptr, data->scene->resolution[0], data->scene->resolution[1]);
	data->image->img_data = mlx_get_data_addr(data->image->image, &(data->image->bits_per_pixel), &(data->image->size_line), &(data->image->endian));
	return (1);
}
