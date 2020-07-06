/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_keyboard.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:12:41 by cdai              #+#    #+#             */
/*   Updated: 2020/03/05 16:07:42 by cdai             ###   ########.fr       */
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
	if (keycode == 65307)
		exit_hook(data);
	else if (keycode == 65361)
		data->mov_flags.turn_left = 1;
	else if (keycode == 65363)
		data->mov_flags.turn_right = 1;
	else if (keycode == 115)
		data->mov_flags.backward = 1;
	else if (keycode == 119)
		data->mov_flags.forward = 1;
	else if (keycode == 97)
		data->mov_flags.mov_left = 1;
	else if (keycode == 100)
		data->mov_flags.mov_right = 1;
	return (1);
}

int	key_release_hook(int keycode, t_game_data *data)
{
	if (keycode == 65361)
		data->mov_flags.turn_left = 0;
	else if (keycode == 65363)
		data->mov_flags.turn_right = 0;
	else if (keycode == 115)
		data->mov_flags.backward = 0;
	else if (keycode == 119)
		data->mov_flags.forward = 0;
	else if (keycode == 97)
		data->mov_flags.mov_left = 0;
	else if (keycode == 100)
		data->mov_flags.mov_right = 0;
	return (1);
}

int	print_key(int keycode, t_game_data *data)
{
	if (keycode == 65307)
		exit_hook(data);
	else if (keycode == 65361)
	{
		if (data->mov_flags.turn_left == 1)
		data->mov_flags.turn_left = 0;
		else
		data->mov_flags.turn_left = 1;
	}
	else if (keycode == 65363)
	{
		if (data->mov_flags.turn_right == 1)
		data->mov_flags.turn_right = 0;
		else
		data->mov_flags.turn_right = 1;
	}
	else if (keycode == 115)
	{
		if (data->mov_flags.backward == 1)
		data->mov_flags.backward = 0;
		else
		data->mov_flags.backward = 1;
	}
	else if (keycode == 119)
	{
		if (data->mov_flags.forward == 1)
		data->mov_flags.forward = 0;
		else
		data->mov_flags.forward = 1;
	}
	else if (keycode == 97)
	{
		if (data->mov_flags.mov_left == 1)
		data->mov_flags.mov_left = 0;
		else
		data->mov_flags.mov_left = 1;
	}
	else if (keycode == 100)
	{
		if (data->mov_flags.mov_right == 1)
		data->mov_flags.mov_right = 0;
		else
		data->mov_flags.mov_right = 1;
	}
	return (0);
}

int	ft_handle_keyboard(t_game_data *data)
{
	mlx_do_key_autorepeatoff(data->mlx.ptr);
	mlx_hook(data->mlx.win, 2, 1L << 0, key_press_hook, data);
	mlx_hook(data->mlx.win, 3, 1L << 1, key_release_hook, data);
	mlx_hook(data->mlx.win, 17, 1L << 17, exit_hook, data);
//	mlx_key_hook(data->mlx.win, print_key, data);
	return (0);
}
