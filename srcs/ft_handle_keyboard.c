/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_keyboard.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:12:05 by cdai              #+#    #+#             */
/*   Updated: 2020/01/27 15:16:40 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press_hook(int keycode, t_game_data *data)
{
	printf("key_press_hook => keycode :%d\n", keycode);
	if (keycode == 53)
		exit(0);
	else if (keycode == 0)
		data->mov_flags->turn_left = 1;
	else if (keycode == 2)
		data->mov_flags->turn_right = 1;
	else if (keycode == 1)
		data->mov_flags->backward = 1;
	else if (keycode == 13)
		data->mov_flags->forward = 1;
	else if (keycode == 123)
		data->mov_flags->mov_left = 1;
	else if (keycode == 124)
		data->mov_flags->mov_right = 1;
	//123, 124
	return (1);
}

int	key_release_hook(int keycode, t_game_data *data)
{
	printf("key_release_hook => keycode :%d\n", keycode);
	if (keycode == 0)
		data->mov_flags->turn_left = 0;
	else if (keycode == 2)
		data->mov_flags->turn_right = 0;
	else if (keycode == 1)
		data->mov_flags->backward = 0;
	else if (keycode == 13)
		data->mov_flags->forward = 0;
	else if (keycode == 123)
		data->mov_flags->mov_left = 0;
	else if (keycode == 124)
		data->mov_flags->mov_right = 0;
	//123, 124
	return (1);
}

void	set_hooks(t_game_data *data)
{
	mlx_do_key_autorepeatoff(data->mlx->ptr);
	mlx_hook(data->mlx->win, 2, 0, key_press_hook, data);
	mlx_hook(data->mlx->win, 3, 0, key_release_hook, data);
//	mlx_hook(win_ptr, 4, 0, mouse_press_hook, data);
//	mlx_hook(win_ptr, 5, 0, mouse_release_hook, data);
//	mlx_hook(win_ptr, 6, 0, motion_hook, data);
//	mlx_hook(data->mlx->win, 12, 0, expose_hook, data);
//	mlx_hook(data->mlx->win, 17, 0, exit_hook, data);
}

int	ft_handle_keyboard(t_game_data *data)
{	
	int test;
	set_hooks(data);
	return (0);
}
