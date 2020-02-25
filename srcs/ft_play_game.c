/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:03:02 by cdai              #+#    #+#             */
/*   Updated: 2020/02/25 15:12:23 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_play_game(t_game_data *data)
{
	ft_handle_image(data);
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win,
		data->working_img.image, 0, 0);
	return (0);
}
