/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 10:56:01 by cdai              #+#    #+#             */
/*   Updated: 2020/02/07 15:49:58 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_init_orientation(t_game_data *data)
{
	if (data->scene->orientation == 'N')
	{
//		data->camera->dir_x = 0;
//		data->camera->dir_y = -1.0;
//		data->camera->plane_x = -1.0;
//		data->camera->plane_y = 0;
		data->camera->angle = M_PI / 2;
	}
	else if (data->scene->orientation == 'S')
	{
//		data->camera->dir_x = 0;
//		data->camera->dir_y = 1.0;
//		data->camera->plane_x = 1.0;
//		data->camera->plane_y = 0;
		data->camera->angle = M_PI * 1.5;
	}
	else if (data->scene->orientation == 'W')
	{
//		data->camera->dir_x = -1.0;
//		data->camera->dir_y = 0;
//		data->camera->plane_x = 0;
//		data->camera->plane_y = 1.0;
		data->camera->angle = M_PI;
	}
	else if (data->scene->orientation == 'E')
	{
//		data->camera->dir_x = 1.0;
//		data->camera->dir_y = 0;
//		data->camera->plane_x = 0;
//		data->camera->plane_y = -1.0;
		data->camera->angle = 0;
	}
	data->mov_flags = ft_calloc(1, sizeof(*(data->mov_flags)));
}

void		ft_launch_game(const char *filename)
{
	t_game_data *data;	

	data = ft_calloc(1, sizeof(*data));
	if (!(data->scene = ft_parse_cub(data, filename)))
		return ft_putstr_fd("Error: scene's parsing error.", 1);
	data->mlx = ft_calloc(1, sizeof(*(data->mlx)));
	data->mlx->ptr = mlx_init();
	data->mlx->win = mlx_new_window(data->mlx->ptr, data->scene->resolution[0], data->scene->resolution[1], "cub3D");

printf("Resolution x: %d\n",data->scene->resolution[0]);
printf("Resolution y: %d\n",data->scene->resolution[1]);
printf("North textures path: %s\n", data->scene->sprite[0]);
printf("South textures path: %s\n", data->scene->sprite[1]);
printf("West textures path: %s\n", data->scene->sprite[2]);
printf("East textures path: %s\n", data->scene->sprite[3]);
printf("Sprite textures path: %s\n", data->scene->sprite[4]);
printf("Floor color RGBA: %d,%d,%d,%d\n", data->scene->floor[0], data->scene->floor[1], data->scene->floor[2], data->scene->floor[3]);
printf("Ceilling color RGBA: %d,%d,%d,%d\n", data->scene->ceilling[0], data->scene->ceilling[1], data->scene->ceilling[2], data->scene->ceilling[3]);
int i = 0;
printf("Map : \n");
while (data->scene->map[i])
{
	printf("%s\n", data->scene->map[i]);
	i++;
}
printf("Orientation : %c\n", data->scene->orientation);



	data->image = mlx_new_image(data->mlx->ptr, data->scene->resolution[0], data->scene->resolution[1]);


	data->camera->pos_x += 0.5;
	data->camera->pos_y += 0.5;
	ft_init_orientation(data);

	ft_prepare_images(data);
	data->mov_flags->walk_speed = 0.31;
	data->mov_flags->rotation_speed = 0.2;
	ft_test(data);
//	ft_handle_image(data);
	ft_test(data);
//	ft_handle_keyboard(data);

//	mlx_loop_hook(data->mlx->ptr, ft_handle_image, data);
	mlx_loop(data->mlx->ptr);
}
