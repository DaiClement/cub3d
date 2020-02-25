/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_keyboard.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:12:41 by cdai              #+#    #+#             */
/*   Updated: 2020/02/25 15:26:18 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_hook(t_game_data *data)
{
	ft_free_data(data);
	exit(0);
	return (0);
}

int	key_press_hook(int keycode, t_game_data *data)
{
	if (keycode == 53)
		exit_hook(data);
	else if (keycode == 123)
		data->mov_flags.turn_left = 1;
	else if (keycode == 124)
		data->mov_flags.turn_right = 1;
	else if (keycode == 1)
		data->mov_flags.backward = 1;
	else if (keycode == 13)
		data->mov_flags.forward = 1;
	else if (keycode == 0)
		data->mov_flags.mov_left = 1;
	else if (keycode == 2)
		data->mov_flags.mov_right = 1;
	return (1);
}

int	key_release_hook(int keycode, t_game_data *data)
{
	if (keycode == 123)
		data->mov_flags.turn_left = 0;
	else if (keycode == 124)
		data->mov_flags.turn_right = 0;
	else if (keycode == 1)
		data->mov_flags.backward = 0;
	else if (keycode == 13)
		data->mov_flags.forward = 0;
	else if (keycode == 0)
		data->mov_flags.mov_left = 0;
	else if (keycode == 2)
		data->mov_flags.mov_right = 0;
	return (1);
}

int	ft_handle_keyboard(t_game_data *data)
{
	mlx_do_key_autorepeatoff(data->mlx.ptr);
	mlx_hook(data->mlx.win, 2, 0, key_press_hook, data);
	mlx_hook(data->mlx.win, 3, 0, key_release_hook, data);
	mlx_hook(data->mlx.win, 17, 0, exit_hook, data);
	return (0);
}
